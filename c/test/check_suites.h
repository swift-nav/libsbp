/*
 * Copyright (C) 2011-2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef CHECK_SUITES_H
#define CHECK_SUITES_H

Suite* acquisition_suite(void);
Suite* bootload_suite(void);
Suite* edc_suite(void);
Suite* file_io_suite(void);
Suite* flash_suite(void);
Suite* navigation_suite(void);
Suite* observation_suite(void);
Suite* piksi_suite(void);
Suite* sbp_suite(void);
Suite* settings_suite(void);
Suite* system_suite(void);
Suite* tracking_suite(void);

#endif /* CHECK_SUITES_H */
