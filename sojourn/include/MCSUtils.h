//
//  MCSUtils.h
//  ParseTest
//
//  Created by Michael Ayles on 31/05/2016.
//  Copyright © 2016 Melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#define SECONDS_IN_DAY  24 * 60 * 60
#define SECONDS_IN_HOUR 3600
#define SEVEN_DAYS 7*24*60*60


@interface MCSUtils : NSObject

+(double)getDistance: (CLLocationCoordinate2D)loc1 : (CLLocationCoordinate2D)loc2;
+ (NSDate*)getHistoricDate: (NSInteger)daysAgo;
@end
