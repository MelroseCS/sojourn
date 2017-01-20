//
//  MCSBackgrountTask.h
//  ParseTest
//
//  Created by Michael Ayles on 07/06/2016.
//  Copyright © 2016 Melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

@interface MCSBackgroundTask : NSObject
{
    UIBackgroundTaskIdentifier bgTask;
    bool                cancel;
    NSCondition*        lock;
    NSDate*             startTime;
}

-(void)execute: (void(^)(void))handler;
-(void)cancel;

@end
