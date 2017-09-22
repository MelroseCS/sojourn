//
//  MCSService.h
//  ParseTest
//
//  Created by Michael Ayles on 31/05/2016.
//  Copyright © 2016 Melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCSConstants.h"
#import "MCSLocationSensor.h"
#import <CocoaLumberjack/CocoaLumberjack.h>
#import <Parse/Parse.h>
#import "MCSReachability.h"
#import "MCSTileData.h"
#import "MCSVenueVisit.h"
#import "MCSBeaconVisit.h"
#import "MCSVenueVisitProtocol.h"


typedef CF_ENUM(int, CFSojournErrors) {
    kCFInvalidParameters = 1,
    kCFLocationDisabled = 2,
    kCFLocationServicesDisabled = 3,
    kCFLocationRequestTimeout = 4
};

extern NSString* _Nonnull kCFSojournDomain;

extern NSString* _Nonnull kCFSojournMinAccuracyKey;
extern NSString* _Nonnull kCFSojournMinDistanceKey;


typedef void (^LocationResultBlock)(CLLocation* _Nullable location, NSError * _Nullable error);
typedef void (^PushResultBlock)(UIBackgroundFetchResult result);
typedef void (^QueryResultBlock)(NSArray<PFObject*> * _Nullable objects, NSError * _Nullable error);
typedef void (^ResultBlock)(BOOL succeeded, NSError * _Nullable error);


@interface MCSService : NSObject
{
    dispatch_queue_t m_queue;
}

+ (MCSService* _Nonnull)sharedService;
-(BOOL) initWithConfiguration:(NSString* _Nonnull)applicationId serverUrl:(NSString* _Nonnull)url;
-(void)saveLocationOffline:(CLLocation* _Nonnull)location;
-(void) checkinVenue:(PFObject* _Nonnull)venue timeout:(int)timeoutSecs key:(NSString* _Nullable)key object:(NSObject* _Nullable)object handler:(ResultBlock _Nonnull)handler;
-(void) flush;
-(void) fetchConfig;

-(void)getLastLocation: (LocationResultBlock _Nonnull)handler;
-(void)getLocalVenues: (CLLocation* _Nonnull) location maxItems:(int)limit handler:(QueryResultBlock _Nonnull)handler;
-(void)getLocalVisits: (QueryResultBlock _Nonnull)handler;

- (void)storeRemoteNotificationsWithDeviceToken:(NSData *_Nullable)deviceToken;
- (void)storeAuthStatus: (NSNumber*_Nullable)status;
- (void)storeBluetoothStatus: (NSInteger)status;

- (void)handlePush: (NSDictionary * _Nullable)userInfo fetchCompletionHandler:(PushResultBlock _Nullable) completionHandler;
- (void)getCurrentLocation:(LocationManagerLocationUpdateBlock _Nonnull)handler;

- (void)applyCustomAttributes:(NSDictionary* _Nullable)attributes;

- (NSArray* _Nonnull)getMovementDetectionConfig;

@property (nonatomic) BOOL enableLocation;
@property (nonatomic, retain) MCSLocationSensor* _Nullable sensor;
@property (nonatomic, retain) MCSTileData* _Nullable tileHandler;
@property (nonatomic, retain) MCSVenueVisit* _Nullable venueHandler;
@property (nonatomic, retain) MCSBeaconVisit* _Nullable beaconHandler;
@property (nonatomic, retain) NSString* _Nullable username;
@property (nonatomic, readonly) NSString* _Nullable deviceId;
@property (nonatomic) MCSReachability* _Nullable hostReachability;
@property (nonatomic, retain) id<MCSVenueVisitProtocol> _Nullable visitDelegate;
@end
