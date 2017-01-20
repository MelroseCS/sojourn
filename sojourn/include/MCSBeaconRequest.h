//
//  MCSBeaconRequest.h
//  Reader_V2
//
//  Created by Michael Ayles on 28/06/2016.
//  Copyright © 2016 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

typedef void (^BeaconResultBlock)(NSArray<CLBeacon*> * _Nullable objects, NSError * _Nullable error);


@class MCSBeaconRequest;

/**
 Protocol for the MCSBeaconRequest to notify the its delegate that a request has timed out.
 */
@protocol MCSBeaconRequestDelegate

/**
 Notification that a location request has timed out.
 
 @param beaconRequest The beacon request that timed out.
 */
- (void)beaconRequestDidTimeout:(MCSBeaconRequest* _Nullable)beaconRequest;

@end

@interface MCSBeaconRequest : NSObject

/** The delegate for this location request. */
@property (nonatomic, weak, nullable) id<MCSBeaconRequestDelegate> delegate;

@property (nonatomic, readonly) BOOL hasTimedOut;
/** The block to execute when the beacon request completes. */
@property (nonatomic, copy, nullable) BeaconResultBlock block;

@property (nonatomic, assign) NSTimeInterval timeout;
/** How long the beacon request has been alive since the timeout value was last set. */
@property (nonatomic, readonly) NSTimeInterval timeAlive;

@property (nonatomic, strong, nullable) NSMutableArray* beacons;

/** Cancels the request request. */
- (void)cancel;

/** Starts the beacons request's timeout timer if a nonzero timeout value is set, and the timer has not already been started. */
- (void)startTimeoutTimer;

- (void)onBeaconSeen:(NSArray* _Nullable)beacons;


@end
