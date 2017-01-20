//
//  MCSVisit.h
//  ParseTest
//
//  Created by Michael Ayles on 31/05/2016.
//  Copyright © 2016 Melrose. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>



@interface MCSVisit : NSObject

@property (nonatomic, retain) NSString* name;

@property (nonatomic, retain) NSString* venue_id;

@property (nonatomic, retain) NSDate* enter;

@property (nonatomic, retain) NSDate* exit;

@property CLLocationCoordinate2D location;

@property double radius;

@end
