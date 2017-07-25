![image]<img width="773" height="120" src="https://github.com/MQZHot/ZLaunchAdVC/blob/master/Picture/ZLaunchAdVC.png"/>

1

![](https://img.shields.io/badge/platform-iOS-red.svg) ![](https://img.shields.io/badge/language-Swift-green.svg) ![](https://img.shields.io/badge/support-iOS%208%2B-blue.svg) ![](https://img.shields.io/badge/license-MIT%20License-brightgreen.svg) ![](https://img.shields.io/badge/pod-0.0.2-yellow.svg)

### Swift 集成app启动页广告，切换rootViewController，支持LaunchImage和LaunchScreen.storyboard，支持GIF图片显示，支持视图过渡动画，欢迎star✨✨✨
**********

## 功能

- [x] 圆形跳过按钮、倒计时+跳过

- [x] 全屏广告、半屏广告
- [x] 跳过按钮位置：屏幕右上角、右下角，广告图右下角
- [x] 支持 GIF 广告图片显示
- [x] 状态栏颜色设置，以及显示与隐藏

## 用法

* #### 代码

```swift
///AppleDelegate中设置
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

    window = UIWindow.init(frame: UIScreen.main.bounds)
    window?.backgroundColor = UIColor.white
    let homeVC = ViewController()
    let nav = UINavigationController.init(rootViewController: homeVC)

    if launchOptions != nil {
        /// 通过推送等启动
        window?.rootViewController = nav
    } else {
        /// 正常点击icon启动页，加载广告
        let adVC = ZLaunchAdVC.init(defaultDuration: 6, completion: {
        self.window?.rootViewController = nav
        })
        /// 延时模拟网络请求
        /// 网络超过vc默认显示时间（可设置），不加载图片
        DispatchQueue.main.asyncAfter(deadline: DispatchTime.now() + 2, execute: {

            let url = "http://chatm-icon.oss-cn-beijing.aliyuncs.com/pic/pic_20170725104352981.jpg"
            let adDuartion = 4
            /// 设置参数
            adVC.setAdParams(url: url, adDuartion: adDuartion, skipBtnType: .circle, adViewBottomDistance: 100, transitionType: .filpFromLeft, adImgViewClick: {
                /// 广告点击
                let vc = UIViewController()
                vc.view.backgroundColor = UIColor.green
                homeVC.navigationController?.pushViewController(vc, animated: true)

            })
        })
        window?.rootViewController = adVC
    }
    window?.makeKeyAndVisible()
    return true
}
```

* #### 状态栏设置

Target -> General -> Deployment Target -> Status Bar Style 设置状态栏颜色、显示与隐藏

## 安装

* pod 'ZLaunchAdVC'
* pod install / pod update


## CocoaPods更新日志


