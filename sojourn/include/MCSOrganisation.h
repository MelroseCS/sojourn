//
//  MCSOrganisation.h
//  Pods
//
//  Created by Michael Ayles on 31/08/2016.
//
//

#import <Foundation/Foundation.h>
#import <Parse/Parse.h>

@interface MCSOrganisation :  PFObject<PFSubclassing>

@property (retain, nonatomic) NSString* name;
@property (retain, nonatomic) NSString* uuid;
@property (retain, nonatomic) NSString* orgId;
@property int limit;


@end
