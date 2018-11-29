//
//  SojournListener.h
//  sojournLib
//
//  Created by Michael Ayles on 22/06/2018.
//  Copyright © 2018 melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * Pro
 */
@protocol SojournListener <NSObject>
@optional
    /**
     * Called when location is updated.  Movement indications amount of distance
     * in metres from the last location.
     */
    - (void)didUpdateLocation:(CLLocation* _Nullable)location movement:(double)distance;
    /**
     * Called when the status updates.
     */
    - (void)didUpdateAuthorizationStatus:(CLAuthorizationStatus)status;

@required
    /**
     * Called when we've been notified of
     * a new message arriving
     */
    - (void)didReceiveInboxMessage;
@end
