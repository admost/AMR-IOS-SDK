Pod::Spec.new do |s|
  s.name             = 'AMRSDK'
  s.version          = '1.5.41'
  s.requires_arc     = true
  s.license          = { :type => 'Copyright', :text => <<-LICENSE
									Copyright 2016
									Admost Mediation Limited.
									LICENSE
								}
  s.homepage         = 'http://www.admost.com/'
  s.author           = { 'Admost Mediation Limited' => 'amr@admost.com' }
  s.summary          = 'Admost Mediation Router SDK.'
  s.description      = <<-DESC
Admost Mediation Router is a powerful mediation tool to maximize your ad revenues for your apps and games from all major ad networks.
                       DESC
  s.source           = { :git => 'https://github.com/admost/AMR-IOS-SDK.git',
 								 :tag => s.version.to_s }
  s.documentation_url = 'https://admost.github.io/amrios/'
  s.platform = :ios
  s.ios.deployment_target = '9.0'
  s.frameworks = 'AdSupport', 'AudioToolbox', 'AVFoundation', 'AVKit', 'CFNetwork', 'CoreGraphics', 'CoreMedia', 'CoreTelephony', 'JavaScriptCore', 'MediaPlayer', 'QuartzCore', 'SafariServices', 'SystemConfiguration'
  s.weak_frameworks = ['Foundation', 'UIKit', 'WebKit', 'StoreKit']
  s.libraries = 'z'
  s.pod_target_xcconfig = { 
    'OTHER_LDFLAGS' => '-ObjC -lc++',
    "VALID_ARCHS": "arm64 armv7 x86_64",
    'VALID_ARCHS[sdk=iphoneos*]' => 'armv7 arm64',
    'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64 arm64'
  }

  s.dependency 'KokteylLog', '~> 1.1.1'
  s.swift_versions = ['5']
  s.subspec 'Core' do |cr|
    cr.vendored_frameworks = 'AMRSDK/AMRSDK.xcframework'
    cr.resources = ['AMRSDK/AMRResources.bundle']
  end

  s.subspec 'AFA' do |af|
    af.vendored_frameworks = 'AMRSDK/AMRSDK.xcframework', 'AFA/AMRAdapterAFA.xcframework'
    af.resources = ['AMRSDK/AMRResources.bundle']
    af.dependency 'AdmostFairAds', '~> 1.3.0'
  end
end
