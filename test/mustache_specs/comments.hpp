#pragma once

#include <ArduinoJson.h>
#include <doctest.h>

// clang-format off
/* generated via
cat test/test_ministache/mustache_specs/comments.json| jq -r '.tests[] | "TEST_CASE(\"\(.name)\") { ArduinoJson::JsonDocument data; deserializeJson(data, R\"(\(.data))\"); CHECK_MESSAGE(ministache::render(R\"(\(.template))\", data) == R\"(\(.expected))\", R\"(\(.desc))\"); }\n"' | pbcopy
*/
// clang-format on

TEST_SUITE_BEGIN("ministache/specs/comments");

TEST_CASE("Inline") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(12345{{! Comment Block! }}67890)", data) == R"(1234567890)",
                R"(Comment blocks should be removed from the template.)");
}

TEST_CASE("Multiline") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(12345{{!
  This is a
  multi-line comment...
}}67890
)",
                                   data) == R"(1234567890
)",
                R"(Multiline comments should be permitted.)");
}

TEST_CASE("Standalone") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(Begin.
{{! Comment Block! }}
End.
)",
                                   data) == R"(Begin.
End.
)",
                R"(All standalone comment lines should be removed.)");
}

TEST_CASE("Indented Standalone") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(Begin.
  {{! Indented Comment Block! }}
End.
)",
                                   data) == R"(Begin.
End.
)",
                R"(All standalone comment lines should be removed.)");
}

TEST_CASE("Standalone Line Endings") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(|
{{! Standalone Comment }}
|)",
                                   data) == R"(|
|)",
                R"("\r\n" should be considered a newline for standalone tags.)");
}

TEST_CASE("Standalone Without Previous Line") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(  {{! I'm Still Standalone }}
!)",
                                   data) == R"(!)",
                R"(Standalone tags should not require a newline to precede them.)");
}

TEST_CASE("Standalone Without Newline") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(!
  {{! I'm Still Standalone }})",
                                   data) == R"(!
)",
                R"(Standalone tags should not require a newline to follow them.)");
}

TEST_CASE("Multiline Standalone") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(Begin.
{{!
Something's going on here...
}}
End.
)",
                                   data) == R"(Begin.
End.
)",
                R"(All standalone comment lines should be removed.)");
}

TEST_CASE("Indented Multiline Standalone") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(Begin.
  {{!
    Something's going on here...
  }}
End.
)",
                                   data) == R"(Begin.
End.
)",
                R"(All standalone comment lines should be removed.)");
}

TEST_CASE("Indented Inline") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(ministache::render(R"(  12 {{! 34 }}
)",
                                   data) == R"(  12 
)",
                R"(Inline comments should not strip whitespace)");
}

TEST_CASE("Surrounding Whitespace") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({})");
  CHECK_MESSAGE(
      ministache::render(R"(12345 {{! Comment Block! }} 67890)", data) == R"(12345  67890)",
      R"(Comment removal should preserve surrounding whitespace.)");
}

TEST_CASE("Variable Name Collision") {
  ArduinoJson::JsonDocument data;
  deserializeJson(data, R"({"! comment":1,"! comment ":2,"!comment":3,"comment":4})");
  CHECK_MESSAGE(ministache::render(R"(comments never show: >{{! comment }}<)", data) ==
                    R"(comments never show: ><)",
                R"(Comments must never render, even if variable with same name exists.)");
}

TEST_SUITE_END();
