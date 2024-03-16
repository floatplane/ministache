[![.github/workflows/build.yml](https://github.com/floatplane/ministache/actions/workflows/build.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/build.yml)
[![.github/workflows/test.yml](https://github.com/floatplane/ministache/actions/workflows/test.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/test.yml)
[![.github/workflows/static_analysis.yml](https://github.com/floatplane/ministache/actions/workflows/static_analysis.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/static_analysis.yml)
[![.github/workflows/clangformat.yml](https://github.com/floatplane/ministache/actions/workflows/clangformat.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/clangformat.yml)

# Ministache

A spec-complete implementation of the [Mustache](https://mustache.github.io/) templating language for Arduino.

## Features

Complete support for all elements of the [Mustache core specification](https://github.com/mustache/spec) version 1.4.1, with 100% of tests passing. Supported features:

- Interpolation
- Sections
- Iteration
- Partials
- Comments
- Custom delimiters

See the [mustache documentation](https://mustache.github.io/mustache.5.html) for more details on these features.

## Example

```c++
ArduinoJson::JsonDocument data;
data[F("subject")] = F("world");
const String output = ministache::render(F("Hello, {{subject}}!"), data);
Serial.println(output); // Hello, world!
```
