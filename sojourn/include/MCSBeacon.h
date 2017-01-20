//
//  MCSBeacon.h
//  Pods
//
//  Created by Michael Ayles on 31/08/2016.
//
//

#import <Foundation/Foundation.h>
#import <Parse/Parse.h>

@interface MCSBeacon : PFObject<PFSubclassing>

+ (NSString *)parseClassName;

@property (retain, nonatomic) NSString* name;
@property (retain, nonatomic) NSString* mac;
@property (retain, nonatomic) NSString* uuid;

@property (strong, nonatomic) NSNumber* major;
@property (strong, nonatomic) NSNumber* minor;
@property (nonatomic, retain) PFObject* venueId;

@property BOOL isActive;
@property BOOL isMobile;


@end
