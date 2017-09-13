//
//  MCSVenueVisit.h
//  Pods
//
//  Created by Michael Ayles on 30/08/2016.
//
//

#import <Foundation/Foundation.h>
#import "MCSConstants.h"
#import "MCSVisit.h"
#import "MCSVenueVisitProtocol.h"
#import <CoreLocation/CLLocationManager.h>

typedef void (^VisitResultBlock)(NSArray<MCSVisit*> * _Nullable objects, NSError * _Nullable error);

@interface MCSVenueVisit : NSObject

@property (retain, nonatomic) NSArray* _Nullable visits;

@property (retain, nonatomic) id<MCSVenueVisitProtocol> _Nullable delegate;

- (void)exitVenueVisits;
- (void)determineVenueState:(CLLocation* _Nullable) location forceEnterVenue:(NSString* _Nullable)venueId;
- (void)flushVenueVisits;
- (PFObject* _Nullable)checkCurrentlyInVenue:(PFObject* _Nonnull)venue;

@end
