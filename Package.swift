// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "AMRSDK",
    platforms: [
        .iOS(.v9)
    ],
    products: [
        .library(
            name: "AMRSDK",
            targets: ["AMRSDKWrapper"]
        )
    ],
    dependencies: [
        .package(url: "https://github.com/kokteyldev/KOKTEYL-LOG-SDK.git", from: "1.1.2")
    ],
    targets: [
        .target(
            name: "AMRSDKWrapper",
            dependencies: [
                "AMRSDKBinary",
                .product(name: "KokteylLog", package: "KOKTEYL-LOG-SDK")
            ],
            path: "AMRSDK",
            exclude: ["AMRSDK.xcframework"],
            resources: [
                .copy("AMRResources.bundle")
            ],
            linkerSettings: [
                .linkedFramework("AdSupport"),
                .linkedFramework("AudioToolbox"),
                .linkedFramework("AVFoundation"),
                .linkedFramework("AVKit"),
                .linkedFramework("CFNetwork"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("CoreMedia"),
                .linkedFramework("CoreTelephony"),
                .linkedFramework("JavaScriptCore"),
                .linkedFramework("MediaPlayer"),
                .linkedFramework("QuartzCore"),
                .linkedFramework("SafariServices"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("Foundation"),
                .linkedFramework("UIKit"),
                .linkedFramework("WebKit"),
                .linkedFramework("StoreKit"),
                .linkedLibrary("z"),
                .linkedLibrary("c++")
            ]
        ),
        .binaryTarget(
            name: "AMRSDKBinary",
            path: "AMRSDK/AMRSDK.xcframework"
        )
    ]
)
