![AMRSDK: Admost Mediation iOS SDK](https://www.admost.com/img/logo.svg)

[![Swift](https://img.shields.io/badge/Swift-5.0_6.0-orange?style=flat-square)](https://img.shields.io/badge/Swift-5.0_6.0-orange?style=flat-square)
[![Platforms](https://img.shields.io/badge/Platforms-iOS-yellowgreen?style=flat-square)](https://img.shields.io/badge/Platforms-iOS-yellowgreen?style=flat-square)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/AMRSDK.svg?style=flat-square)](https://img.shields.io/cocoapods/v/AMRSDK.svg)
[![SPM Compatible](https://img.shields.io/badge/SPM-compatible-brightgreen?style=flat-square)](https://img.shields.io/badge/SPM-compatible-brightgreen?style=flat-square)

# AMRSDK

AMRSDK is the official iOS SDK for Admost Mediation, enabling seamless ad monetization integration written in Objective-C and Swift.

## Features

- Support for following ad types; Banner, Native, Interstitial, App Open, Rewarded Video and Offerwall
- Test suite
- A/B test
- Session tracking
- Real time event tracking
- In-app/Subscription tracking
- Remote config
- Header bidding
- Automatic Google UMP consent (optional)

## Requirements

- iOS 9.0+
- Xcode 15+
- Application Id provided in Admost Mediation Dashboard.
- Zone Id(s) provided in Admost Mediation Dashboard.

For testing you can use following Ids:

| Name | Id |
|---|---|
| Application Id | 15066ddc-9c18-492c-8185-bea7e4c7f88c |
| Banner Zone | b4009772-de04-42c4-bbaa-c18da9e4a1ab |
| Interstitial Zone | 39f74377-5682-436a-9338-9d1c4df410bd |
| Rewarded Zone | 2bdefd44-5269-4cbc-b93a-373b74a2f067 |
| OfferWall Zone | 1cadca08-33f9-4da7-969e-ef116d4e7d0e |

## Installation

### Swift Package Manager

Add the following to your `Package.swift` dependencies:

```swift
.package(url: "https://github.com/admost/AMR-IOS-SDK.git", from: "1.5.85")
```

Then add `AMRSDK` to your target dependencies:

```swift
.product(name: "AMRSDK", package: "AMRSDK")
```

Or in Xcode: **File → Add Package Dependencies** and enter the repository URL.

### CocoaPods

Add the following to your `Podfile`:

```ruby
pod 'AMRSDK'
```

Then run:

```sh
pod install
```

## Automatic UMP consent (optional)

AMRSDK can show Google's User Messaging Platform (UMP) consent form for you and start the ad networks after the user's choice.

1. Add GoogleUserMessagingPlatform 2.1.0+ to your app (`pod 'GoogleUserMessagingPlatform'`, or the Swift package `https://github.com/googleads/swift-package-manager-google-user-messaging-platform`). With Swift Package Manager, make sure Other Linker Flags contains `-ObjC`.
2. Add `GADApplicationIdentifier` (your AdMob app id) to `Info.plist`.
3. In AdMob, create a GDPR message and add Admost and your ad networks as ad partners.
4. Contact the Admost team at amr@admost.com (or your account manager) to enable automatic UMP for your app.
5. Offer a way to change the choice, for example in your settings screen:

```swift
privacyButton.isHidden = !AMRSDK.isPrivacyOptionsRequired()

@objc func privacyButtonTapped() {
    AMRSDK.presentPrivacyOptionsForm(from: self) { error in
        if let error { print(error.localizedDescription) }
    }
}
```

## License

Copyright 2016 Admost Mediation Limited. All rights reserved. [See LICENSE](https://github.com/admost/AMR-IOS-SDK/blob/master/LICENSE) for details.

## Contact

- **Website:** [admost.com](http://www.admost.com/)
- **Email:** amr@admost.com
- **Documentation:** [admost.github.io/amrios](https://admost.github.io/amrios/)
