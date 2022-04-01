//
//  UIViewController+SFMCSdkSwizzling.h
//  SFMCSDK
//
//  Created by Prakashini Pattabiraman on 08/03/22.
//  Copyright © 2022 Salesforce Marketing Cloud. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController ()

+ (void)swizzleViewDidAppearForScreenTracking;

@end

NS_ASSUME_NONNULL_END
