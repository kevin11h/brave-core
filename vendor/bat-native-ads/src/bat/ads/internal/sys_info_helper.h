/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_SYS_INFO_HELPER_H_
#define BAT_ADS_INTERNAL_SYS_INFO_HELPER_H_

#include "base/system/sys_info.h"

namespace ads {

class SysInfoHelper {
 public:
  SysInfoHelper();

  ~SysInfoHelper();

  static base::SysInfo::HardwareInfo GetHardware();
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_SYS_INFO_HELPER_H_
