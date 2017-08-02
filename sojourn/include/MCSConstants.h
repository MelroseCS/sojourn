//
//  MCSConstants.h
//  Pods
//
//  Created by Michael Ayles on 30/08/2016.
//
//

#ifndef MCSConstants_h
#define MCSConstants_h

@import Foundation;

#define BEACON_UUID                @"uuid"
#define BEACON_MAJOR               @"major"
#define BEACON_MINOR               @"minor"


#define LOCATION_OBJECT     @"DeviceLocation"
#define USERNAME            @"user"
#define LOCATION            @"location"
#define ACCURACY            @"accuracy"
#define COURSE              @"course"
#define SPEED               @"speed"
#define TIMESTAMP           @"timestamp"
#define VENUE_OBJECT        @"Venue"
#define BEACON_OBJECT       @"Beacon"
#define LOCATION_OBJECT_PIN @"locations"
#define VENUE_OBJECT_PIN    @"venues"
#define BEACON_OBJECT_PIN   @"beacons"
#define TILE_OBJECT         @"tileLocation"
#define TILE_OBJECT_PIN     @"tileLocations"
#define DISTANCE            @"distance"
#define RADIUS              @"radius"
#define VENUE_VISIT_OBJECT  @"VenueVisit"
#define VENUE_VISIT_OBJECT_PIN  @"VenueVisit"
#define BEACON_VISIT_OBJECT @"BeaconVisit"
#define BEACON_VISIT_OBJECT_PIN @"BeaconVisit"
#define VENUE_ID            @"venueId"
#define BEACON_ID           @"beaconId"
#define EXIT_TIMESTAMP      @"exit"
#define ENTER_TIMESTAMP     @"enter"
#define VENUE_NAME          @"name"
#define BEACON_LIST         @"beaconList"
#define LOGFILE             @"logFile"
#define DEVICELOG_OBJECT    @"DeviceLogs"
#define IS_ACTIVE           @"isConfirmed"
#define IS_HIDDEN           @"isHidden"
#define IDFA                @"idfa"
#define PEDOMETER_OBJECT    @"Pedometer"
#define STEPS               @"steps"
#define DISTANCE            @"distance"
#define FLOORS_UP           @"floorsAscended"
#define FLOORS_DOWN         @"floorsDescended"
#define PEDOMETER_OBJECT_PIN @"pedometer"
#define SAVE_ON_ENTER       @"enterActionList"

#define ORGANISATION_OBJECT @"Organisation"
#define ORGANISATION_ID     @"orgId"
#define ORGANISATION_UUID   @"uuid"
#define ORGANISATION_POINTER @"organisationId"
#define ORGANISATION_NAME   @"name"

#define TILE_UPDATED_NOTIFICATION @"SOJOURN_NOTIFICATION_TILE_UPDATED"

#define DEFAULT_VENUE_DISTANCE_KM 2

#define INSTALLATION_ID     @"installationId"

#define LOC_AUTH_STATUS     @"locationAuthStatus"
#define BLUETOOTH_STATUS    @"bluetoothStatus"

//#define LAST_LOCATION_OBJECT_PIN    @"cachedLocation"
#define LAST_CONFIG_TIMESTAMP       @"lastConfigRefresh"
#define CONFIG_REFRESH_CADENCE      @"configRefresh"
#define DISTANCE_FILTER             @"distanceMovedFilter"
#define VISIT_ACCURACY_THRESHOLD    @"visitAccuracyThreshold"
#define ACCURACY_REQUIRED           @"accuracyRequired"
#define VENUE_LAST_REFRESH          @"timestamp"
#define VISIT_ACTIVITY              @"visitActivity"
#define VENUE_MAP_ACCEPTED          @"venueMapTermsAccepted"
#define MOVEMENT_DETECTION          @"movementDetection"
#define LAST_KNOW_LOCATION_OBJECT_PIN @"LastKnownLocation"
#define LAST_KNOWN_LOCATION_OBJECT    @"LastLocation"

#define BACKGROUND_TASK_CANCELLED   -12345

#define LOGGING_ROLL_FREQUENCY 60 * 60 * 24 //1 day
#define MAX_NUMBER_OF_LOGS 7

#define PEDOMETER_HISTORY_LIMIT 7

#define MAX_TILE_SIZE_KM    10.0
#define DEFAULT_DISTANCE_FILTER 100
#define DEFAULT_ACCURACY 100
#define DEFAULT_VISIT_THRESHOLD 1000
#define MAX_BEACONS 4
#define MAX_VENUES 100

#define LOG_ASYNC_ENABLED YES

extern const int ddLogLevel;

#define LOG_LEVEL_DEF ddLogLevel

typedef NS_ENUM(NSInteger, BluetoothStateType) {
    BluetoothStateUnknown,
    BluetoothStateNotSupported,
    BluetoothStateNotAuthorised,
    BluetoothStateOff,
    BluetoothStateOn
};



#endif /* MCSConstants_h */
