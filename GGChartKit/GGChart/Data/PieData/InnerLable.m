//
//  InnerLable.m
//  GGCharts
//
//  Created by 黄舜 on 17/9/20.
//  Copyright © 2017年 I really is a farmer. All rights reserved.
//

#import "InnerLable.h"
#import "PieInnerLableAbstract.h"

@interface InnerLable ()

@end

@implementation InnerLable

/**
 * 初始化方法
 */
- (instancetype)init
{
    self = [super init];
    
    if (self) {
        
        self.lableFont = [UIFont systemFontOfSize:9];
        self.lableColor = [UIColor blackColor];
        self.stringFormat = @"%.2f";
        self.stringRatio = CGPointMake(-.5f, -.5f);
        self.stringOffSet = CGSizeZero;
    }
    
    return self;
}

@end
