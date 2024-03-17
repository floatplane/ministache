[![PlatformIO Registry](https://badges.registry.platformio.org/packages/floatplane/library/Ministache.svg)](https://registry.platformio.org/libraries/floatplane/Ministache)
[![.github/workflows/build.yml](https://github.com/floatplane/ministache/actions/workflows/build.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/build.yml)
[![.github/workflows/test.yml](https://github.com/floatplane/ministache/actions/workflows/test.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/test.yml)
[![.github/workflows/static_analysis.yml](https://github.com/floatplane/ministache/actions/workflows/static_analysis.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/static_analysis.yml)
[![.github/workflows/clangformat.yml](https://github.com/floatplane/ministache/actions/workflows/clangformat.yml/badge.svg)](https://github.com/floatplane/ministache/actions/workflows/clangformat.yml)
[![BuyMeACoffee](https://raw.githubusercontent.com/pachadotdev/buymeacoffee-badges/main/bmc-donate-yellow.svg)](https://www.buymeacoffee.com/floatplane)

# Ministache

A spec-complete implementation of the [Mustache](https://mustache.github.io/) templating language for Arduino. A sane alternative to building up complex strings via concatenation and custom code. Very useful for embedded web servers!

## Features

Complete support for all elements of the [Mustache core specification](https://github.com/mustache/spec) version 1.4.1, with 100% of tests passing. Supported features:

- Interpolation
- Sections
- Iteration
- Partials
- Comments
- Custom delimiters

See the [mustache documentation](https://mustache.github.io/mustache.5.html) for more details on these features.

## Basics

```c++
ArduinoJson::JsonDocument data;
data[F("subject")] = F("world");
const String output = ministache::render(F("Hello, {{subject}}!"), data);
Serial.println(output); // Hello, world!
```

See [basic.ino](examples/basic/basic.ino) for a sketch demonstrating basic Ministache usage.

## Partials

Partials are a powerful Mustache feature allow you to define a chunk of template code and use it in a loop. See [partials.ino](examples/partials/partials.ino) for a sketch demonstrating how to use partials with Ministache.

## Projects using Ministache

- [floatplane/MitsuQTT](https://github.com/floatplane/MitsuQTT)

## Support 

I hope this is useful to you! If it is, then maybe you'd like to buy me a coffee? :blush:

<a href="https://www.buymeacoffee.com/floatplane" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-violet.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>
