//
//  MCSVenueTile.h
//  Pods
//
//  Created by Michael Ayles on 30/08/2016.
//
//

#import <Foundation/Foundation.h>
#import "MCSConstants.h"
#import <CoreLocation/CoreLocation.h>

@class PFObject;

typedef void (^QueryResultBlock)(NSArray<PFObject*> * _Nullable objects, NSError * _Nullable error);

@interface MCSTileData : NSObject


-(NSArray* _Nullable)getNearestVenues: (CLLocation* _Nullable)location limit:(int)limit;
-(NSArray* _Nullable)getBeacons;

- (void)getLocalBeacons:(QueryResultBlock _Nonnull)handler;
- (void)getLocalBeacons: (CLLocationCoordinate2D) location maxItems:(int)limit handler:(QueryResultBlock _Nonnull)handler;
- (BOOL)shouldGetTile: (CLLocationCoordinate2D) location withinKilometers:(double)distance;
- (void)getTileData: (CLLocationCoordinate2D) location distance:(double)distance force:(BOOL)force;
- (void)getLocalVenues: (CLLocationCoordinate2D) location maxItems:(int)limit handler:(QueryResultBlock _Nonnull)handler;
- (void)checkTimestamp: (NSDate* _Nullable)timestamp;
- (void)addVenueToTile:(PFObject* _Nonnull)venue;

@end
