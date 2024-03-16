#pragma once

#ifndef MINISTACHE_MINISTACHE_HPP
#define MINISTACHE_MINISTACHE_HPP

#include <Arduino.h>
#include <ArduinoJson.h>

#include <algorithm>
#include <cassert>
#include <vector>

namespace ministache {

typedef std::vector<std::pair<String, String>> PartialList;

String render(const String& templateContents, const ArduinoJson::JsonDocument& data,
              const PartialList& partials = {});

};  // namespace ministache

#endif  // MINISTACHE_MINISTACHE_HPP