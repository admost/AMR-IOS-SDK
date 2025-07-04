![AMRSDK: Admost Mediation iOS SDK](https://www.admost.com/img/logo.svg)

[![Swift](https://img.shields.io/badge/Swift-4.0_6.0-orange?style=flat-square)](https://img.shields.io/badge/Swift-5.9_5.10_6.0-Orange?style=flat-square)
[![Platforms](https://img.shields.io/badge/Platforms-macOS_iOS-yellowgreen?style=flat-square)](https://img.shields.io/badge/Platforms-macOS_iOS_tvOS_watchOS_vision_OS_Linux_Windows_Android-Green?style=flat-square)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/AMRSDK.svg?style=flat-square)](https://img.shields.io/cocoapods/v/AMRSDK.svg)


AMRSDK is the official iOS SDK for Admost Mediation, enabling seamless ad monetization integration written in Objective-C and Swift.

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Full Documentation](https://admost.github.io/amrios/)
- [License](#license)

## Features

- Support for following ad types; Banner, Native, Interstitial, App Open, Rewarded Video and Offerwall
- Test suite
- A/B test
- Session tracking
- Real time event tracking
- In-app/Subscription tracking
- Remote config
- Header bidding

## Requirements

- iOS 9 or later.
- Xcode 15 or later.
- Application Id provided in Admost Mediation Dashboard.
- Zone Id(s) provided in Admost Mediation Dashboard.

For testing you can use following Ids;

| Name                                             | Id
| ---------------------------------------------------- |-------------------------------------------------------------------------------------------------------------------- |
| Application Id | 15066ddc-9c18-492c-8185-bea7e4c7f88c |
| Banner Zone                                                | b4009772-de04-42c4-bbaa-c18da9e4a1ab                                                                      |
| Interstitial Zone                                              | 39f74377-5682-436a-9338-9d1c4df410bd                                                                      |
| Rewarded Zone                                              | 2bdefd44-5269-4cbc-b93a-373b74a2f067                                                                      |
| OfferWall Zone                                              | 1cadca08-33f9-4da7-969e-ef116d4e7d0e                                                                      |


## Installation

### CocoaPods

[CocoaPods](https://cocoapods.org) is a dependency manager for Cocoa projects. For usage and installation instructions, visit their website. To integrate AMRSDK into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
pod 'AMRSDK'
```


## License

AMRSDK is released under the MIT license. [See LICENSE](https://github.com/admost/AMR-IOS-SDK/blob/master/LICENSE) for details.
