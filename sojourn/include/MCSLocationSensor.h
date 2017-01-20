//
//  SCLocationSensor.h
//  sensor-collector
//
//  Created by Michael Ayles on 11/05/2016.
//  Copyright © 2016 Melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "MCSBeaconRequest.h"
#import "MCSPedometer.h"
@import CoreBluetooth;


#define DEFAULT_LOCATION_TIMEOUT 10.0 //seconds
#define DEFAULT_BEACON_TIMEOUT 5.0

typedef void(^LocationManagerLocationUpdateBlock)(CLLocation * _Nullable location, NSError * _Nullable error);

@interface MCSLocationSensor : NSObject <CLLocationManagerDelegate, CBCentralManagerDelegate, MCSBeaconRequestDelegate>
{
@private
    CLLocationManager *m_pLocationManager;
    dispatch_queue_t m_queue;
    
    
}

@property (nonatomic) double distanceMovedFilter;
@property (nonatomic) double accuracyRequired;
@property (nonatomic) double visitAccuracyThreshold;
@property (nonatomic, strong) CLLocation* _Nullable lastLocation;
@property (nonatomic) CBCentralManager* _Nullable bluetoothManager;
//@property (nonatomic, strong) MCSPedometer* _Nullable pedometer;
@property (nonatomic, strong) MCSBeaconRequest* _Nullable beaconRequest;


- (void)enableLocationServices;
- (void)initialise;
+ (bool)isLocationEnabled;
-(void) authoriseLocation;
-(void)requestLocation: (LocationManagerLocationUpdateBlock _Nonnull)handler;
-(void)requestLocationWithVenue:(NSString* _Nullable)venueId;
- (void)beaconRequestDidTimeout:(MCSBeaconRequest* _Nullable)beaconRequest;
@end


