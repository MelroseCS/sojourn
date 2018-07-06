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
@required
    /**
     * Called when we've been notified of
     * a new message arriving
     */
    - (void)didReceiveInboxMessage;
@end
