//
//  MCSVenueVisitProtocol.h
//  sojournLib
//
//  Created by Michael Ayles on 01/08/2017.
//  Copyright © 2017 melrose. All rights reserved.
//

#ifndef MCSVenueVisitProtocol_h
#define MCSVenueVisitProtocol_h
#include <Parse/Parse.h>

/*!
 *  @brief MCSVenueVisitProtocol protocol - Implement to alert the application of
 *  notifications when user enters or leaves a venue
 *
 */
@protocol MCSVenueVisitProtocol <NSObject>
/*!
 *  @discussion Called when a device enters a venue's geofence.
 *
 *  @param visit The visit object.
 */
- (void)didEnterVenue:(PFObject* _Nonnull)visit;
/*!
 *  @discussion Called when a device exits a venue's geofence.
 *
 *  @param visit The visit object.
 
 */
- (void)didExitVenue:(PFObject* _Nonnull)visit;

@end



#endif /* MCSVenueVisitProtocol_h */
