
Pod::Spec.new do |s|
  s.name             = 'QFStatistics'
  s.version          = '0.0.7'
  s.summary          = 'A statistics SDK of QianFang Inc.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/342261733/QFStatisticsSDK'
  s.license          = 'MIT'
  s.author           = { 'QFPayShadowMan' => 'xunianqiang@qfpay.com' }
  s.source           = { :git => 'https://github.com/342261733/QFStatisticsSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '7.0'
  s.vendored_frameworks = "**/*.framework"
  s.preserve_paths = "**/*.framework"

  s.frameworks = 'UIKit', 'CoreLocation', 'Foundation', 'SystemConfiguration', 'CoreTelephony'
  s.xcconfig  = { "OTHER_LDFLAGS" => "-lObjC",'LD_RUNPATH_SEARCH_PATHS' => '"$(SRCROOT)/**/*.framework"' }

end
