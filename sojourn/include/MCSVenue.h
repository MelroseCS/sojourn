//
//  MCSVenue.h
//  Pods
//
//  Created by Michael Ayles on 31/08/2016.
//
//

#import <Foundation/Foundation.h>
#import <Parse/Parse.h>

@interface MCSVenue :  PFObject<PFSubclassing>

@property (nonatomic, retain) NSString* name;
@property (nonatomic, retain) NSString* googlePlacesId;

@property double radius;
@property BOOL isConfirmed;
@property (nonatomic, retain) PFGeoPoint* location;
@property (nonatomic, retain) NSArray* beaconList;
@property (nonatomic, retain) PFObject* organisationId;

@end
