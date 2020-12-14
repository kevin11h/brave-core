/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/ad_targeting/ad_targeting_util.h"

#include <string>

#include "testing/gtest/include/gtest/gtest.h"

// npm run test -- brave_unit_tests --filter=BatAds*

namespace ads {
namespace ad_targeting {

TEST(BatAdsAdTargetingUtilTest,
    SplitParentChildSegment) {
  // Arrange
  const std::string segment = "parent-child";

  // Act
  const SegmentList segments = SplitSegment(segment);

  // Assert
  const SegmentList expected_segments = {
    "parent",
    "child"
  };

  EXPECT_EQ(expected_segments, segments);
}

TEST(BatAdsAdTargetingUtilTest,
    SplitParentSegment) {
  // Arrange
  const std::string segment = "parent";

  // Act
  const SegmentList segments = SplitSegment(segment);

  // Assert
  const SegmentList expected_segments = {
    "parent"
  };

  EXPECT_EQ(expected_segments, segments);
}

TEST(BatAdsAdTargetingUtilTest,
    SplitEmptySegment) {
  // Arrange
  const std::string segment = "";

  // Act
  const SegmentList segments = SplitSegment(segment);

  // Assert
  const SegmentList expected_segments = {};

  EXPECT_EQ(expected_segments, segments);
}

TEST(BatAdsAdTargetingUtilTest,
    GetParentSegments) {
  // Arrange
  const SegmentList segments = {
    "technology & computing-software",
    "personal finance-personal finance",
    "automobiles"
  };

  // Act
  const SegmentList parent_segments = GetParentSegments(segments);

  // Assert
  const SegmentList expected_parent_segments = {
    "technology & computing",
    "personal finance",
    "automobiles"
  };

  EXPECT_EQ(expected_parent_segments, parent_segments);
}

TEST(BatAdsAdTargetingUtilTest,
    GetParentSegmentsForEmptyList) {
  // Arrange
  const SegmentList segments;

  // Act
  const SegmentList parent_segments = GetParentSegments(segments);

  // Assert
  const SegmentList expected_parent_segments = {};

  EXPECT_EQ(expected_parent_segments, parent_segments);
}

}  // namespace ad_targeting
}  // namespace ads
