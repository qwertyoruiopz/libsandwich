/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/SAObjects.framework/SAObjects
 */

#import "SADomainObject.h"

@class NSNumber, NSString;

@interface SATimerObject : SADomainObject {
}
@property(retain, nonatomic) NSNumber* timerValue;
@property(copy, nonatomic) NSString* state;
+ (id)objectWithDictionary:(id)dictionary context:(id)context;
+ (id)object;
- (void)updateUsingSet:(id)set add:(id)add remove:(id)remove;
- (id)encodedClassName;
- (id)groupIdentifier;
@end
