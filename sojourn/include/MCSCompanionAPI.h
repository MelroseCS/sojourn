//
//  MCSCompanionAPI.h
//  Pods
//
//  Created by Michael Ayles on 31/08/2016.
//
//

#import <Foundation/Foundation.h>
#import "MCSOrganisation.h"
#import "MCSVenue.h"
#import "MCSBeacon.h"


@interface MCSCompanionAPI : NSObject


+(MCSOrganisation*) getOrganisation:(NSString*)orgId;
+(NSArray*) getVenuesForOrganisation:(MCSOrganisation*)org offset:(int)offset;
+(NSInteger) getVenueCount:(MCSOrganisation*)org;
+(void)saveBeacon:(MCSBeacon*)beacon;

@end
