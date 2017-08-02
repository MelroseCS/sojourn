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

+(BOOL)saveVenue:(MCSVenue*)venue error:(NSError **)error;
+(BOOL)deleteVenue:(MCSVenue*)venue error:(NSError **)error;
+(NSArray*) getVenuesForOrganisation:(MCSOrganisation*)org offset:(int)offset;
+(NSInteger) getVenueCount:(MCSOrganisation*)org;

+(BOOL) saveOrganisation:(MCSOrganisation*)org error:(NSError **)error;
+(MCSOrganisation*) getOrganisationByName:(NSString*)name error:(NSError **)error;
+(MCSOrganisation*) getOrganisationById:(NSString*)orgId error:(NSError **)error;
+(BOOL) deleteOrganisation:(MCSOrganisation*)org error:(NSError **)error;



+(void)saveBeacon:(MCSBeacon*)beacon;

@end
