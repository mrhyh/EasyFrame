//
//  DCPaymentAlert.h
//  DCPayAlertDemo
//
//  Created by dawnnnnn on 15/12/9.
//  Copyright © 2015年 dawnnnnn. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DCPaymentAlert : UIView

@property (nonatomic, copy) NSString *title, *detail;
@property (nonatomic, assign) CGFloat amount;

@property (nonatomic, copy) NSString *inputPwd;
@property (nonatomic, copy) void (^completeHandle)(NSString *password);

@end
// 版权属于原作者
// http://code4app.com (cn) http://code4app.net (en)
// 发布代码于最专业的源码分享网站: Code4App.com