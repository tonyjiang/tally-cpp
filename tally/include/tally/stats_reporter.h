// Copyright (c) 2018 Uber Technologies, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

#include "tally/base_stats_reporter.h"
#include "tally/buckets.h"
#include "tally/histogram.h"

namespace tally {

class StatsReporter : public BaseStatsReporter {
 public:
  virtual ~StatsReporter() = default;

  // Methods to report metrics.
  virtual void ReportCounter(
      const std::string &name,
      const std::unordered_map<std::string, std::string> &tags,
      int64_t value) = 0;

  virtual void ReportGauge(
      const std::string &name,
      const std::unordered_map<std::string, std::string> &tags,
      double value) = 0;

  virtual void ReportTimer(
      const std::string &name,
      const std::unordered_map<std::string, std::string> &tags,
      std::chrono::nanoseconds value) = 0;

  virtual void ReportHistogramValueSamples(
      const std::string &name,
      const std::unordered_map<std::string, std::string> &tags,
      uint64_t bucket_id, uint64_t num_buckets, double buckets_lower_bound,
      double buckets_upper_bound, uint64_t samples) = 0;

  virtual void ReportHistogramDurationSamples(
      const std::string &name,
      const std::unordered_map<std::string, std::string> &tags,
      uint64_t bucket_id, uint64_t num_buckets,
      std::chrono::nanoseconds buckets_lower_bound,
      std::chrono::nanoseconds buckets_upper_bound, uint64_t samples) = 0;
};

}  // namespace tally
