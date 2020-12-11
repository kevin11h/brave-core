/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "base/bind.h"
#include "base/task/post_task.h"
#include "bat/ads/internal/sys_info_helper.h"

namespace ads {

namespace {

base::SysInfo::HardwareInfo g_hardware;

void OnGetHardwareInfo(
    base::SysInfo::HardwareInfo hardware) {
  g_hardware = hardware;
}

}  // namespace

SysInfoHelper::SysInfoHelper() {
  base::SysInfo::GetHardwareInfo(base::BindOnce(&OnGetHardwareInfo));
}

SysInfoHelper::~SysInfoHelper() = default;

// static
base::SysInfo::HardwareInfo SysInfoHelper::GetHardware() {
  return g_hardware;
}

}  // namespace ads
