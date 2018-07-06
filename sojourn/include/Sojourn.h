//
//  SojournService.h
//  AIR
//
//  Created by Michael Ayles on 12/06/2018.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import "SojournListener.h"
typedef void (^PushResultBlock)(UIBackgroundFetchResult result);
typedef void (^InboxCountResultBlock)(int total, int unread);
typedef void (^InboxResultBlock)(NSArray* _Nullable objects, NSError * _Nullable error);
typedef void (^InboxBooleanResultBlock)(BOOL succeeded, NSError *_Nullable error);
typedef void (^DeleteMeBooleanResultBlock)(BOOL succeeded, NSError *_Nullable error);




@interface Sojourn : NSObject

/**
 Controls Sojourn location.  Set to false to
 stop sojourn turning on location services.  The default is false.
 */
@property (nonatomic) BOOL enableLocation;
/**
 Register a deletegate by setting this property to get
 notifications of new messages etc..
 */
@property (nonatomic, strong) id<SojournListener> _Nullable delegate;


/**
 Returns the one and only instance of the Sojourn SDK.
 */
+ (Sojourn* _Nonnull)sharedService;

/**
 Sets the configuration to be used for the Sojourn SDK.
 
 @note Calling this multiple time results in undefined behavior.
 
 @param applicationId The API key to use
 @param url The service endpoint
 */
-(BOOL)initWithConfiguration:(NSString* _Nonnull)applicationId serverUrl:(NSString* _Nonnull)url;

/**
 Saves the attributes defined in the dictionary.
 
 @note Attibutes are key/value pairs.  Only simple object types like string, date and number
       are supported
 */
- (void)applyCustomAttributes:(NSDictionary* _Nullable)attributes;
/**
 Saves the push token to sojourn to allow sojourn to send notifications
 */
- (void)storeRemoteNotificationsWithDeviceToken:(NSData *_Nullable)deviceToken;
/**
 Call this function to allow sojourn to process push notifications specific to sojourn.
 */
- (void)handlePush: (NSDictionary * _Nullable)userInfo fetchCompletionHandler:(PushResultBlock _Nullable) completionHandler;
/**
 Gets the total number of messages in the inbox and the number of messages that remain
 unread.
 */
- (void)getInboxCount:(InboxCountResultBlock _Nonnull)block;
/**
 Gets the messages in the inbox
 */
- (void)getInbox:(int)skip limit:(int)limit block:(InboxResultBlock _Nonnull)block;
/**
 Marks specific message in the inbox as read.
 */
- (void)markAsRead:(NSString* _Nonnull)objectId block:(InboxBooleanResultBlock _Nonnull)block;
/**
 Marks all messages in the inbox as read.
 */
- (void)markInboxAsRead:(InboxBooleanResultBlock _Nonnull)block;
/**
 Deletes a specific message.
 */
- (void)deleteInboxMessage:(NSString*_Nonnull)objectId block:(InboxBooleanResultBlock _Nonnull)block;
/**
 Deletes all messages.
 */
- (void)deleteAllInboxMessages:(InboxBooleanResultBlock _Nonnull)block;


/**
 Deletes sensitive data about the user.  This means
 we will delete any location data about the user.  Some deletion will
 not be instant.
 */
- (void)deleteMe:(DeleteMeBooleanResultBlock _Nonnull)block;
@end
