/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/SAObjects.framework/SAObjects
 */

#import "SABaseClientBoundCommand.h"

@class NSURL, SAAlarmObject;

@interface SAAlarmCreate : SABaseClientBoundCommand {
}
@property(retain, nonatomic) SAAlarmObject* alarmToCreate;
@property(copy, nonatomic) NSURL* targetAppId;
+ (id)createWithDictionary:(id)dictionary context:(id)context;
+ (id)create;
- (id)encodedClassName;
- (BOOL)requiresResponse;
- (id)groupIdentifier;
@end

