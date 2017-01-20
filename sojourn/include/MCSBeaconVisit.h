//
//  MCSBeaconVisit.h
//  Pods
//
//  Created by Michael Ayles on 30/08/2016.
//
//

#import <Foundation/Foundation.h>

@interface MCSBeaconVisit : NSObject

- (void)determineBeaconState:(NSArray* _Nonnull) beacons;
- (void)exitBeaconVisits;
- (void)flushBeaconVisits;

@property (retain, nonatomic) NSArray* _Nullable visits;

@end
