// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SFMCSDK",
    products: [
        .library(name: "SFMCSDK", type: .dynamic, targets: ["SFMCSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "SFMCSDK",
            path: "Frameworks/SFMCSDK.xcframework"
        )
    ]
)
