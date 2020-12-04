/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/wip/ad_targeting/processors/purchase_intent/purchase_intent_processor.h"

#include "bat/ads/internal/unittest_base.h"
#include "bat/ads/internal/unittest_util.h"

// npm run test -- brave_unit_tests --filter=BatAds*

namespace ads {
namespace ad_targeting {
namespace processor {

class BatAdsPurchaseIntentProcessorTest : public UnitTestBase {
 protected:
  BatAdsTextProcessorTest() = default;

  ~BatAdsTextProcessorTest() override = default;
};

TEST_F(BatAdsPurchaseIntentProcessorTest,
    Process) {
  // Arrange

  // Act
  PurchaseIntentProcessor processor;
  processor.Process();

  // Assert
  FAIL();
}

}  // namespace processor
}  // namespace ad_targeting
}  // namespace ads