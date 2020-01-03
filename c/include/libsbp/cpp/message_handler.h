/**
 * Copyright (C) 2019 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SBP_CPP_MESSAGE_HANDLER_H_
#define SBP_CPP_MESSAGE_HANDLER_H_

#include <cassert>
#include <array>

#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>

namespace sbp {

/**
 * A convenience type alias for class member functions that accept SBP message callbacks
 */
template<typename ClassT, typename ArgT>
using CallbackMemFn = void (ClassT::*)(uint16_t, uint8_t, const ArgT &);

/**
 * A helper function for calling a C++ object member function from a libsbp callback.
 *
 * This function is registered with libsbp as a callback and calls a specific member function
 * of an object from that callback with the SBP message decoded. The member function pointer
 * is encoded into the template parameter, and the instance of the object is passed in via
 * the `context` parameter.
 *
 * @tparam MsgT The message type to decode the payload as
 * @tparam ClassT The class type to call the function on
 * @tparam func Pointer to the member function to call
 *
 * @param sender_id The decoded sender ID, is forwarded on to `func`
 * @param len The length of the message, is forwarded on to `func`
 * @param msg The raw message payload
 * @param context Pointer to an instance of `ClassT` to call `func` on
 */
template<typename MsgT, typename ClassT, CallbackMemFn<ClassT, MsgT> func>
inline void sbp_cb_passthrough(uint16_t sender_id, uint8_t len, uint8_t msg[], void *context) {
  assert(nullptr != context);

  auto instance = static_cast<ClassT *>(context);
  auto val = reinterpret_cast<MsgT *>(msg);
  ((*instance).*(func))(sender_id, len, *val);
}

namespace details {

/**
 * Recursive interface type for defining the interface functions for `MessageHandler`.
 *
 * These types define a virtual `handle_sbp_msg()` for handling a specific SBP message type,
 * as well as a function for registering it as a SBP callback.
 *
 * @note These types aren't meant to be used directly by application code.
 *
 * @tparam MsgType The type of SBP message to define an interface for
 * @tparam OtherTypes Other types to recursively define interfaces for
 */
template<typename MsgType, typename... OtherTypes>
class CallbackInterface : CallbackInterface<OtherTypes...> {
 public:
  CallbackInterface() = default;
  virtual ~CallbackInterface() = default;

  using CallbackInterface<OtherTypes...>::handle_sbp_msg;
  virtual void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const MsgType& msg) = 0;

 protected:
  void register_callback(sbp_state_t *state, sbp_msg_callbacks_node_t nodes[]) {
    sbp_register_callback(state,
        sbp::MessageTraits<MsgType>::id,
        &sbp_cb_passthrough<MsgType, CallbackInterface, &CallbackInterface::handle_sbp_msg>,
        this,
        &nodes[0]);
    CallbackInterface<OtherTypes...>::register_callback(state, &nodes[1]);
  }
};

template<typename MsgType>
class CallbackInterface<MsgType> {
 public:
  CallbackInterface() = default;
  virtual ~CallbackInterface() = default;

  virtual void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const MsgType& msg) = 0;
 protected:
  void register_callback(sbp_state_t *state, sbp_msg_callbacks_node_t nodes[]) {
    sbp_register_callback(state,
                          sbp::MessageTraits<MsgType>::id,
                          &sbp_cb_passthrough<MsgType, CallbackInterface, &CallbackInterface::handle_sbp_msg>,
                          this,
                          &nodes[0]);
  }
};

} // namespace details

/**
 * Base type for defining classes that handle SBP messages
 *
 * Application classes should derive from this class if they wish to handle
 * SBP messages with a member function. `MessageHandler` instantiates all of
 * the callback nodes, and registers the member functions with the given
 * `sbp_state_t`.
 *
 * Classes that derive from `MessageHandler` need to implement
 *   void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const MsgType& msg);
 * for each `MsgType` in the list of message types given as template parameters.
 *
 * Due to the nature of the callback registration in libsbp we dissallow copying or
 * moving of `MessageHandler`.
 *
 * @note It should not matter if the class derives publicly or privately from `MessageHandler`
 * or if the `handle_sbp_msg` functions are public or private.
 *
 * @example
 * class ECEFHandler : private sbp::MessageHandler<msg_gps_time_t, msg_pos_ecef_t> {
 *   public:
 *     ECEFHandler(sbp::State *state) : sbp::MessageHandler<msg_gps_time_t, msg_pos_ecef_t>(state) {
 *       // The callbacks have already been registered
 *       // Perform other initialization tasks
 *     }
 *
 *     void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const msg_gps_time_t& msg) {
 *       // handle GPS time message
 *     }
 *
 *     void handle_sbp_msg(uint16_t sender_id, uint8_t message_length, const msg_pos_ecef_t& msg) {
 *       // handle pos ECEF message
 *     }
 * };
 *
 * @tparam MsgTypes List of SBP message types to register callbacks for
 */
template<typename... MsgTypes>
 class MessageHandler : public details::CallbackInterface<MsgTypes...> {
    static constexpr size_t kMsgCount = sizeof...(MsgTypes);

    State &state_;
    std::array<sbp_msg_callbacks_node_t, kMsgCount> callback_nodes_;

  public:

    explicit MessageHandler(State *state) : details::CallbackInterface<MsgTypes...>(), state_(*state), callback_nodes_() {
      details::CallbackInterface<MsgTypes...>::register_callback(state_.get_state(), callback_nodes_.data());
    }

    virtual ~MessageHandler() {
        for (auto& node : callback_nodes_) {
            sbp_remove_callback(state_.get_state(), &node);
        }
    }

    MessageHandler(const MessageHandler&) = delete;
    MessageHandler(MessageHandler&& other) = delete;
    MessageHandler& operator=(const MessageHandler&) = delete;
    MessageHandler& operator=(MessageHandler&&) = delete;

    using details::CallbackInterface<MsgTypes...>::handle_sbp_msg;
};

} /* namespace sbp */

#endif /* SBP_CPP_MESSAGE_HANDLER_H_ */
