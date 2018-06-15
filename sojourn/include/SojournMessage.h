//
//  SojournMessage.h
//  sojourn-update
//
//  Created by Michael Ayles on 14/06/2018.
//  Copyright © 2018 melrose. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SojournMessage : NSObject

@property (retain, nonatomic) NSString* objectId;
@property (retain, nonatomic) NSString* url;
@property (retain, nonatomic) NSString* title;
@property (retain, nonatomic) NSString* body;
@property (retain, nonatomic) NSDate* timestamp;
@property int type;
@property int state;

@end
