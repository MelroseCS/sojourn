//
//  MCSCustomAttributes.h
//  Pods
//
//  Created by Michael Ayles on 03/11/2016.
//
//

#import <Foundation/Foundation.h>
#import "MCSConstants.h"

@interface MCSAttributes : NSMutableDictionary


@property(atomic) BOOL autoSync;

- (void)removeObjectForKey:(id)key;
- (void)setObject:(id)obj forKey:(id)key;
- (void)setDeviceTokenFromData:(NSData *)deviceTokenData;
- (void)sync;

@end
