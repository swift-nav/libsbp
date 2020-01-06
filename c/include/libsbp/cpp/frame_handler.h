/**
 * Copyright (C) 2020 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_FRAME_HANDLER_H
#define SBP_CPP_FRAME_HANDLER_H

#include <cassert>
#include <array>

#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>

namespace sbp {

/**
 * A helper function for calling a C++ object member function from a libsbp frame callback.
 *
 * This function is registered with libsbp as a callback and calls the `handle_sbp_frame`
 * member function of an object from that callback passing through all of the arguments.
 * The instance of the object is passed in via the `context` parameter.
 *
 * @tparam ClassT The class type to call the function on
 *
 * @param sender_id The decoded sender ID, is forwarded
 * @param msg_type The message type, is forwarded
 * @param payload_len The length of the payload, is forwarded
 * @param payload A pointer to the payload, is forwarded
 * @param frame_len The length of the frame, is forwarded
 * @param frame A pointer to the frame, is forwarded
 * @param context Pointer to an instance of `ClassT` to use
 */
template<typename ClassT>
inline void sbp_frame_cb_passthrough(uint16_t sender_id, uint16_t msg_type,
                                     uint8_t payload_len, uint8_t payload[],
                                     uint16_t frame_len, uint8_t frame[],
                                     void *context) {
  assert(nullptr != context);

  auto instance = static_cast<ClassT *>(context);
  instance->handle_sbp_frame(sender_id, msg_type, payload_len, payload, frame_len, frame);
}

/**
 * Base type for defining classes that handle specific SBP Frames
 *
 * Application classes should derive from this class if they wish to handle
 * entire frames of specific SBP messages with a member function. `FrameHandler`
 * instantiates all of the callback nodes, and registers the member function with
 * the given `sbp_state_t`.
 *
 * Classes that derive from `FrameHandler` need to implement
 * @code
 *   void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
 *                         uint8_t payload_len, uint8_t payload[],
 *                         uint16_t frame_len, uint8_t frame[]);
 * @endcode
 * 
 * This member function will be called for each message specified in the template parameters.
 * You will be able to differentiate the message types based on the `msg_type` argument.
 *
 * Due to the nature of the callback registration in libsbp we dissallow copying or
 * moving of `FrameHandler`.
 *
 * @note It should not matter if the class derives publicly or privately from `FrameHandler`
 * or if the `handle_sbp_frame` function is public or private.
 *
 * @example
 * class ECEFHandler : private sbp::FrameHandler<msg_gps_time_t, msg_pos_ecef_t> {
 *   public:
 *     ECEFHandler(sbp::State *state) : sbp::FrameHandler<msg_gps_time_t, msg_pos_ecef_t>(state) {
 *       // The callbacks have already been registered
 *       // Perform other initialization tasks
 *     }
 *
 *     void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
 *                         uint8_t payload_len, uint8_t payload[],
 *                         uint16_t frame_len, uint8_t frame[]) {
 *       // handle either GPS_TIME or POS_ECEF message types
 *     }
 * };
 *
 * @tparam MsgTypes List of SBP message types to register callbacks for
 */
template<typename ...MsgTypes>
class FrameHandler {
    static constexpr size_t kMsgCount = sizeof...(MsgTypes);

    State &state_;
    std::array<sbp_msg_callbacks_node_t, kMsgCount> callback_nodes_;

  public:

    explicit FrameHandler(State *state) : state_(*state), callback_nodes_() {
        static constexpr std::array<uint16_t, kMsgCount> ids = { sbp::MessageTraits<MsgTypes>::id... };

        for (size_t i = 0; i < kMsgCount; ++i) {
            sbp_register_frame_callback(state_.get_state(),
                    ids[i],
                    &sbp_frame_cb_passthrough<FrameHandler>,
                    this,
                    &callback_nodes_[i]);
        }
    }

    virtual ~FrameHandler() {
        for (auto& node : callback_nodes_) {
            sbp_remove_callback(state_.get_state(), &node);
        }
    }

    FrameHandler(const FrameHandler&) = delete;
    FrameHandler(FrameHandler&& other) = delete;
    FrameHandler& operator=(const FrameHandler&) = delete;
    FrameHandler& operator=(FrameHandler&&) = delete;
    
    virtual void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
                                     uint8_t payload_len, uint8_t payload[],
                                     uint16_t frame_len, uint8_t frame[]) = 0;
};

/**
 * Base type for defining classes that handle all SBP frames.
 *
 * Application classes should derive from this class if they wish to handle
 * all valid SBP frames with a single member function. `AllFrameHandler`
 * instantiates the callback node, and registers the member functions with
 * the given `sbp_state_t`.
 *
 * Classes that derive from `AllFrameHandler` need to implement
 * @code
 *   void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
 *                         uint8_t payload_len, uint8_t payload[],
 *                         uint16_t frame_len, uint8_t frame[]);
 * @endcode
 *
 * Due to the nature of the callback registration in libsbp we dissallow copying or
 * moving of `AllFrameHandler`.
 *
 * @note It should not matter if the class derives publicly or privately from `AllFrameHandler`
 * or if the `handle_sbp_frame` function is public or private.
 *
 * @example
 * class EverythingHandler : private sbp::AllFrameHandler {
 *   public:
 *     EverythingHandler(sbp::State *state) : sbp::AllFrameHandler(state) {
 *       // The callbacks have already been registered
 *       // Perform other initialization tasks
 *     }
 *
 *     void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
 *                         uint8_t payload_len, uint8_t payload[],
 *                         uint16_t frame_len, uint8_t frame[]) {
 *       // handle all frames here
 *     }
 * };
 *
 */
class AllFrameHandler {
    State &state_;
    sbp_msg_callbacks_node_t callback_node_;

  public:

    explicit AllFrameHandler(State *state) : state_(*state), callback_node_() {
      sbp_register_all_msg_callback(state_.get_state(),
              sbp_frame_cb_passthrough<AllFrameHandler>,
              this,
              &callback_node_);
    }

    virtual ~AllFrameHandler() {
        sbp_remove_callback(state_.get_state(), &callback_node_);
    }

    AllFrameHandler(const AllFrameHandler&) = delete;
    AllFrameHandler(AllFrameHandler&& other) = delete;
    AllFrameHandler& operator=(const AllFrameHandler&) = delete;
    AllFrameHandler& operator=(AllFrameHandler&&) = delete;
    
    virtual void handle_sbp_frame(uint16_t sender_id, uint16_t msg_type,
                                     uint8_t payload_len, uint8_t payload[],
                                     uint16_t frame_len, uint8_t frame[]) = 0;
};

} /* namespace sbp */

#endif /* SBP_CPP_MESSAGE_HANDLER_H */
