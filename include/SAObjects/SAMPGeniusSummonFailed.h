/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/SAObjects.framework/SAObjects
 */

#import "SABaseCommand.h"
#import "SAServerBoundCommand.h"

@class NSString;

@interface SAMPGeniusSummonFailed : SABaseCommand <SAServerBoundCommand> {
}
@property(copy, nonatomic) NSString* aceId;
@property(copy, nonatomic) NSString* refId;
@property(copy, nonatomic) NSString* reason;
@property(assign, nonatomic) int errorCode;
+ (id)geniusSummonFailed;
+ (id)geniusSummonFailedWithDictionary:(id)dictionary context:(id)context;
+ (id)geniusSummonFailedWithErrorCode:(int)errorCode;
+ (id)geniusSummonFailedWithReason:(id)reason;
- (id)initWithErrorCode:(int)errorCode;
- (id)encodedClassName;
- (id)groupIdentifier;
- (id)initWithReason:(id)reason;
@end
