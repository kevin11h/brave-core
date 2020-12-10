/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_AD_TARGETING_PROCESSORS_PROCESSOR_DELEGATE_MOCK_H_
#define BAT_ADS_INTERNAL_AD_TARGETING_PROCESSORS_PROCESSOR_DELEGATE_MOCK_H_

#include "testing/gmock/include/gmock/gmock.h"
#include "bat/ads/internal/ad_targeting/processors/processor_delegate.h"

namespace ads {
namespace ad_targeting {
namespace processor {

class DelegateMock : public Delegate {
 public:
  DelegateMock();

  ~DelegateMock() override;

  DelegateMock(const DelegateMock&) = delete;
  DelegateMock& operator=(const DelegateMock&) = delete;

  MOCK_METHOD(void, OnDidProcess, ());

  MOCK_METHOD(void, OnFailedToProcess, ());
};

}  // namespace processor
}  // namespace ad_targeting
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_AD_TARGETING_PROCESSORS_PROCESSOR_DELEGATE_MOCK_H_
