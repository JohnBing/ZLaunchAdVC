//
//  ZLaunchAdVC.h
//  ZLaunchAdObjc
//
//  Created by mengqingzheng on 2017/8/18.
//  Copyright © 2017年 mengqingzheng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZLaunchAdConfig.h"

typedef void (^ZLaunchAdCompletion)();
typedef void (^ConfigSkipBtn)(ZLaunchAdConfig *config);


typedef NS_ENUM(NSUInteger, TransitionStyle) {
    TransitionStyleNone = 0,            /** 无动画 */
    TransitionStyleRippleEffect,        /** 涟漪波纹 */
    TransitionStyleFade,                /** 交叉淡化 */
    TransitionStyleFlipFromTop,         /** 上下翻转 */
    TransitionStyleFlipFromBottom,
    TransitionStyleFlipFromLeft,        /** 左右翻转 */
    TransitionStyleFlipFromRight,
};

@interface ZLaunchAdVC : UIViewController

- (instancetype)initWithDuration: (NSInteger)duration transitionStyle: (TransitionStyle)transitionStyle adBottom: (CGFloat)adBottom completion: (ZLaunchAdCompletion)completion;

/**
 配置网络图片

 @param url url
 @param duration 显示时间
 @param adImgViewClick 点击回调
 */
- (void)configNetImageWithURL: (NSString *)url
                     duration: (NSInteger)duration
               adImgViewClick: (ZLaunchAdCompletion)adImgViewClick;

/**
 配置本地图片

 @param image 图片
 @param duration 显示时间
 @param adImgViewClick 点击回调
 */
- (void)configLocalImageWithImage: (UIImage *)image
                         duration: (NSInteger)duration
                   adImgViewClick: (ZLaunchAdCompletion)adImgViewClick;


/**
 配置本地GIF

 @param name 图片名
 @param duration 显示时间
 @param adImgViewClick 点击回调
 */
- (void)configLocalGifWithName: (NSString *)name
                      duration: (NSInteger)duration
                adImgViewClick: (ZLaunchAdCompletion)adImgViewClick;

/**
 配置跳过按钮
 */
@property (nonatomic, copy) ConfigSkipBtn configSkipBtn;

@end
