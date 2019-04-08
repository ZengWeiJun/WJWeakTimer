//
//  WJGCDTimerHelper.h
//  Timer
//
//  Created by 曾维俊 on 2019/4/6.
//  Copyright © 2019年 Nius. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WJGCDTimerHelper;
typedef void(^WJGCDTimerHelperCallback)(WJGCDTimerHelper *timerHelper);

/**
 该类是对GCDTimer的封装，使用无需考虑定时器生命周期
 外部只需选择使用合适的方法就可以实现计时功能，不必考虑计时器内存释放问题
 
 由于GCDTimer不依赖RunLoop，相对NSTimer会更加准确
 */
@interface WJGCDTimerHelper : NSObject

/**
 调用计时器开始计时

 @param timerInterval 计时间隔
 @param timerCallback 计时回调
 @return ‘WJGCDTimerHelper’实例
 */
+ (instancetype)scheduledTimerWithTimerInterval:(NSTimeInterval)timerInterval
                                  timerCallback:(WJGCDTimerHelperCallback)timerCallback;

/**
 调用计时器开始计时

 @param timerInterval 计时间隔
 @param yesOrNo YES：重复计时，NO：单次计时
 @param timerCallback 计时回调
 @return ‘WJGCDTimerHelper’实例
 */
+ (instancetype)scheduledTimerWithTimerInterval:(NSTimeInterval)timerInterval
                                        repeats:(BOOL)yesOrNo
                                  timerCallback:(WJGCDTimerHelperCallback)timerCallback;

/**
 调用计时器开始计时

 @param delay 延迟多少秒后开始计时
 @param timerInterval 计时间隔
 @param yesOrNo YES：重复计时，NO：单次计时
 @param async 是否在子线程中执行计时
 @param timerCallback 计时回调
 @return ‘WJGCDTimerHelper’实例
 */
+ (instancetype)scheduledTimerWithDelay:(NSTimeInterval)delay
                          timerInterval:(NSTimeInterval)timerInterval
                                repeats:(BOOL)yesOrNo
                                  async:(BOOL)async
                          timerCallback:(WJGCDTimerHelperCallback)timerCallback;

/**
 调用计时器开始计时

 @param aTarget 接受消息的目标对象
 @param aSelector 接受消息的选择器
 @param delay 延迟多少秒后开始计时
 @param timerInterval 计时间隔
 @param yesOrNo YES：重复计时，NO：单次计时
 @param async 是否在子线程中执行计时
 @return ‘WJGCDTimerHelper’实例
 */
+ (instancetype)scheduledTimerWithTarget:(id)aTarget
                                selector:(SEL)aSelector
                                   delay:(NSTimeInterval)delay
                           timerInterval:(NSTimeInterval)timerInterval
                                 repeats:(BOOL)yesOrNo
                                   async:(BOOL)async;

#pragma mark - Instance method
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 指定初始化方法

 @param timerInterval 计时间隔
 @param yesOrNo YES：重复计时，NO：单次计时
 @param async 是否在子线程中执行计时
 @param timerCallback 计时回调
 @return ‘WJGCDTimerHelper’实例
 */
- (instancetype)initWithTimerInterval:(NSTimeInterval)timerInterval
                              repeats:(BOOL)yesOrNo
                                async:(BOOL)async
                        timerCallback:(WJGCDTimerHelperCallback)timerCallback
                        NS_DESIGNATED_INITIALIZER;

/** 关闭计时器 */
- (void)stopTimer;

/** 重新启动计时器 */
- (void)resumeTimer;

/** 暂停计时器 */
- (void)pauseTimer;


@end

NS_ASSUME_NONNULL_END