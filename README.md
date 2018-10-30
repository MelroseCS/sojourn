# Sojourn
Sojourn is a flexible location collection service. It comprises of a mobile SDK for Android or iOS and a web based dashboard to manage your deployment. A core feature of Sojourn is it's efficient algorithm for collecting location data. Location services are not used until the device moves significantly.

The web dashboard provides a portal to manage your deployment. You can create and manage geofences and measure users dwell time at these locations. Basic reporting is available.

We recognise that every use case that requires location from a mobile device is different. With this in mind the system is highly customisable, giving developers the ability to trigger actions on data updates, and easily persist data in the cloud.

Features
* iOS & Android native SDKs
* Quick and easy integration.
* Power efficient algorithm for collecting location data.
* Highly customisable.
* Supports offline store and forward algorithms.
* JavaScript SDK available.
* Support for iBeacons.
* Support for circular geofences.
## Other features:
* Flexible cloud rules engine.
* Inbox
* Social Feeds
* Deep linking.
* System can support user sign-up and anonymous users.
* Email and SMS MFA.
* Web Dashboard
* Create and manage geofences
* Create and manage iBeacons
* Basic reporting active users, visits
* Export of location data
* Server support before and after save triggers.
* Custom rule logic can be implemented.
* Push notifications.
* Highly scalable system.

# Getting Started
The SDK is distributed via CocoaPods. CocoaPods is an open source dependency manager for Swift and Objective-C Cocoa projects. CocoaPods makes it easy to install or update new SDKs when working with Xcode.

You can install the CocoaPods tool on OS X by running the following command from the terminal. 

`$ sudo gem install cocoapods`

Detailed information is available in the [Getting Started guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

## Add Sojourn SDK to your iOS app
CocoaPods is used to install and manage dependencies in existing Xcode projects.

* Create an Xcode project, and save it to your local machine.
* Create a file named Podfile in the root directory of your project. This file defines your project's dependencies, and is commonly referred to as a Podspec.
* Open Podfile, and add your dependencies. A simple Podspec is shown here. replace <xcode-target-name> as appropriate:

```source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target '<xcode-target-name>' do
   pod 'sojourn', '~> 0.0.49'
end


```

* Save the file.
* Open a terminal and cd to the directory containing the Podfile:

`$ cd <path-to-project>`

* Run the pod install command. This will install the SDKs specified in the Podspec, along with any dependencies they may have. 'pod repo update' will first ensure you have the required version in your local cache. 

`$ pod repo update`

`$ pod install`

* Open your app's .xcworkspace file to launch Xcode. Use this file for all development on your app. Do not open the xcodeproj (project) itself after this. 

## Enable Background Location for your Project
* Make the Project Navigator visible in Xcode (?+1)
* Ensure the Standard Editor is visible (?+↵)
* Select the project in the Project Navigator
* Select Capabilities in the Standard Editor on the right hand side.
* Turn the 'Background Modes' option on
* Select the 'Location Updates' checkbox
* Add descriptions for keys NSLocationAlwaysAndWhenInUseUsageDescription, NSLocationWhenInUseUsageDescription and/or NSLocationAlwaysUsageDescription to your applications plist file. Do this by adding Custom iOS Target Properties to the Info pane in XCode. 

## Add SDK initialisation
The SDK needs to be initialised in order to start working.  To do this you will need to contact support to retrieve your applicationId and the URL of the server.

* Add to the didFinishLaunchingWithOptions function in your appDelegate the init function.
```#import <sojourn/Sojourn.h.h>
 
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[Sojourn sharedService] initWithConfiguration:@"ENTER_YOUR_APPLICATION_ID" serverUrl:@"ENTER_YOUR_SERVER_URL"];
    return YES;
}
```

## Enable Location 
To enable sojourn to start collecting location data you must explicitly enable it using the following.  This must be called after initialisation.

```
[Sojourn sharedService].enableLocation = YES;
```

## Custom Attribute
You can apply custom attributes to the device record.  Exisintg values will be overwritten.  This will allow for example more complex rules around sending messages based on gender or team preference etc.

Data types supported: NSString, NSDate, NSNumber.

```
- (void)applyCustomAttributes:(NSDictionary* _Nullable)attributes
```

## Push Handling
Sojourn will require push to be enabled to notify users of new messages when the application is in the background.  There are a number of other system notifications that are silent.  That is no UI is shown in response to these messages.

### Store Push Token
The push token will need to be persisted in order to enable Sojourn to send pushes to the device.  Call the following API to store the push.  This should be called everytime you receive a push token from the OS.  As it may change.

```
- (void)storeRemoteNotificationsWithDeviceToken:(NSData *_Nullable)deviceToken
```

### Handle Incoming Push
Push notification should be passed to Sojourn in order for them to be handled.  It is safe to pass every notification regardless of the intended recipient.

```
- (void)handlePush: (NSDictionary * _Nullable)userInfo fetchCompletionHandler:(PushResultBlock _Nullable) completionHandler
```

## Inbox
The inbox contains 0..* messages delivered by the platform.  These may be generated by a user entering or exiting a geofence or beacon.

### Get Inbox Messages
Retrieves the messages for the specific device.

```
[[Sojourn sharedService] getInbox:0 limit:30 block:^(NSArray * _Nullable objects, NSError * _Nullable error) {
    if (!error) {
        //do something with the messages.
    }
}];
```

### Get Inbox Totals
Gets the total number of messages in the inbox and the total number of unread messages in the inbox.

```
[[Sojourn sharedService] getInboxCount:^(int total, int unread) {
    NSLog(@"Inbox Total:%d, Unread:%d", total, unread);
}];
```

If an error occures then a value of -1 is passed to the block handler.

### Mark all Messages as Read
Marks all messages in the inbox as read.

```
[[Sojourn sharedService] markInboxAsRead:^(BOOL succeeded, NSError * _Nullable error) {
    NSLog(@"Marked all messages as read result:%d", succeeded);
}];
```

### Mark a Message as Read
Marks a specific message identified by it's objectId as read.

```
[[Sojourn sharedService] markAsRead:message.objectId block:^(BOOL succeeded, NSError * _Nullable error) {
    NSLog(@"Marked message %@ as read result:%d", message.objectId, succeeded);
}];
```

### Delete a Message
Deletes a specific message identified by it's objectId.

```
[[Sojourn sharedService] deleteInboxMessage:message.objectId block:^(BOOL succeeded, NSError * _Nullable error) {
    NSLog(@"Delete message %@ result:%d", message.objectId, succeeded);
}];
```

### Delete all Messages
Deletes all messages.

```
[[Sojourn sharedService] deleteAllInboxMessages:^(BOOL succeeded, NSError * _Nullable error) {
    NSLog(@"Deleted all messages result:%d", succeeded);
}];
```

## GDPR
Location data relating to individuals is very likely to be able to identify them. Hence it constitutes personal data and unless exemptions apply, the Data Protection Acts 1988 and 2003 (hereinafter called the ‘Data Protection Acts’) apply. It could also constitute sensitive data, and should therefore be handled carefully. Data controllers have a responsibility to minimise the amount of data collected, processed and retained because of risks posed by linked location data.

See here for more details:
[Guidance Note for Data Controllers on Location Data](https://www.dataprotection.ie/docs/Guidance-Note-for-Data-Controllers-on-Location-Data/1587.htm)
 
Informed consent is the most appropriate basis for processing personal location data in most cases.  This puts emphasis on the app developer to inform the user why they are collecting location data, what they are going to do with and how it will benefit the user.

To ensure Sojourn complies with GDPRs right to be forgotten we supply an API to allow users to mark their account as deleted.  This will record the users request to be forgotten and trigger an asynchronous process to delete the location data.

```
- (void)deleteMe:^(BOOL succeeded, NSError * _Nullable error) {
    NSLog(@"User account data marked for deletion result:%d", succeeded);
}];
```
