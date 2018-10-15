/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/metrics.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup metrics Metrics
 *
 * * Standardized system messages from Swift Navigation devices.
 * \{ */

#ifndef LIBSBP_METRICS_MESSAGES_H
#define LIBSBP_METRICS_MESSAGES_H

#include "common.h"

SBP_PACK_START


/** List the available metrics on the system
 *
 * This message ask the system to return a list of available
 * metrics on the system.
 */
#define SBP_MSG_METRICS_LIST_REQ      0x0301
typedef struct SBP_ATTR_PACKED {
  u16 request_id;    /**< a unique id for the request */
} msg_metrics_list_req_t;


/** A metric that's available on the system.
 *
 * This message details a metric that can be enabled in order
 * for a client to receive information reported by the metric.
 */
#define SBP_MSG_METRICS_LIST_RESP     0x0302
typedef struct SBP_ATTR_PACKED {
  u16 request_id;    /**< the unique id of the original request */
  u16 index;         /**< The index number of the metric, should be stable per firmware
version, and should not change between invocations of the metrics
daemon.  Doubles as the "id" that used when the metric is enabled.
 */
  u16 max_index;     /**< The maximum number of metrics that are supported by the system.
When metric_index == max_metrics_index (and all metrics have been
received)
 */
  u8 type;          /**< Bit field describing the type of the metric: where 0x1 = s32, 0x2 = s64,
0x4 = u32, 0x01 = u64, 0x02 = f64, 0x04 = time (nanosecond).
 */
  u16 interval;      /**< The interval at which the metric updates, in 10s of milliseconds. A value
of 50 would mean the metric updates every 500 milliseconds. A value of
30,000 would mean the metric updates every 5 minutes.
 */
  u8 name[240];     /**< The human readable name of the metric */
} msg_metrics_list_resp_t;


/** Request a specific metric by it's index.
 *
 * Allows the system to re-request a metric if it's lost
 * because of a link communication error.
 */
#define SBP_MSG_METRICS_GET_INDEX_REQ 0x0303
typedef struct SBP_ATTR_PACKED {
  u16 request_id;    /**< the unique id of the original request */
  u16 index;         /**< The index number of the metric that is being requested.
 */
} msg_metrics_get_index_req_t;


/** Sets the reporting interval
 *
 * Tells metrics daemon to begin reporting at the specified interval.
 * It should be possible to align the specified interval to a second
 * boundary.
 */
#define SBP_MSG_METRICS_INTERVAL_REQ  0x0304
typedef struct SBP_ATTR_PACKED {
  u16 request_id;            /**< the request id that was completed */
  u16 reporting_interval;    /**< The interval at which the metrics should be reported, specified
in 10s of milliseconds. A value of 50 would mean the metric reports
every 500 milliseconds. A value of 30,000 would mean the reports
every 5 minutes.

The special value of 0 will disable metrics reporting, but leave
the daemon running.    
 */
} msg_metrics_interval_req_t;


#define SBP_MSG_METRICS_INTERVAL_RESP 0x0305
typedef struct SBP_ATTR_PACKED {
  u16 request_id;    /**< the request id that was completed */
  u8 result;        /**< A value of zero means success, a non-zero value means an error
occurred.
 */
  u8 message[240];  /**< A message describing the reason for a failure, or nothing if the
request was sucessful.  
 */
} msg_metrics_interval_resp_t;


/** Sets the divisor for the specified metrics.
 *
 * Upon receipt the metrics daemon will begin emitting the specified metrics
 * with the associated divisors.
 */
#define SBP_MSG_METRICS_DIVISOR_REQ   0x0306
typedef struct SBP_ATTR_PACKED {
  u16 request_id;           /**< a unique id for the request */
  u8 count;                /**< The number of metrics that are being configured. A count of
zero will result in a "success" response that results in no action.
A special value of 0xFF means all metrics are being configured
with a divisor of 1 (and the value of `metrics_reporting_divisor`
is ignored).
 */
  u64 index_mask[4];        /**< An array of four u64 values indicating which metrics are being
configured.  Only ~245 metrics can be configured per one of these
messages, each on bit in the mask should correspond to an entry
in the `reporting_divisor` array, with the first on bit
corresponding to the first entry of the array.
 */
  u8 reporting_divisor[245]; /**< The number of intervals that must expire before a metric is reported.
That is, if the reporting interval is 50ms, and the divisor is 2,
100ms will transpire before the metric is reported. Each enabled
index in `enable_metrics_indexes` should have a corresponding entry
in this array. The special value 0 will disable reporting of the
metric
 */
} msg_metrics_divisor_req_t;


#define SBP_MSG_METRICS_DIVISOR_RESP  0x0307
typedef struct SBP_ATTR_PACKED {
  u16 request_id;    /**< the request id that was completed */
  u8 result;        /**< A value of zero means the metrics where enabled successfully,
a non-zero value means an error occurred.
 */
  u8 message[240];  /**< A message relating to the `result` value or nothing
if the enable request was successful.
 */
} msg_metrics_divisor_resp_t;


#define SBP_MSG_METRICS_REPORT        0x0308
typedef struct SBP_ATTR_PACKED {
  u64 timestamp;     /**< Nano-second timestamp at which the metrics were collected. */
  u64 index_mask[4]; /**< An array of four u64 values indicating which metrics are included
in the report.  A total of 1024 metrics can be reported currently.
If one metric report doesn't fit in a single SBP message, multiple
SBP message will be emitted.
 */
  u8 values[245];   /**< Binary blob of metric data.  Metric values from the blob are
consumed in increasing order as they appear in the `index_mask`.
A mask value of 0x10010101 means that metrics with indexes 0
2, 4 and 7 appear in the report and in that order.  Clients are
expected to keep a map of metric indexes -> data type width
in order to correctly parse the values.
 */
} msg_metrics_report_t;


/** \} */

SBP_PACK_END

#endif /* LIBSBP_METRICS_MESSAGES_H */