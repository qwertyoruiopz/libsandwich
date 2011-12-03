/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2

File name:

    siri_auth.m

Abstract:

    Override the setSessionValidationData member in the SALoadAssistant
    class in SAObjects? It works? Not yet? What?

--*/

#define _HACKTIVATE_SIRI_

#ifdef _HACKTIVATE_SIRI_

#import "SACreateAssistant.h"
#import "SALoadAssistant.h"
#import <Foundation/Foundation.h>

@class NSString, NSData;




//
// Override method interface
//

@interface SACreateAssistant(Override)
-(void) setValidationData:(NSData *) _data;
@end



//
// Actual code.
// 

@implementation SACreateAssistant(Override)

-(NSData *)validationData {
    return [self propertyForKey:@"validationData"];
}

-(void) setValidationData:(NSData *) _data; {
    NSError *error;    
    NSData * tempData = [[NSData alloc] initWithContentsOfFile:@"/var/mobile/Library/Preferences/com.vlo.libsandwich.plist"];
    NSPropertyListFormat plistFormat;
    NSDictionary *temp = [NSPropertyListSerialization propertyListWithData:tempData options:NSPropertyListImmutable format:&plistFormat error:&error];
    NSData *validationData = [temp valueForKey:@"ValidationData"];
    
    NSLog(@"%@",[NSThread callStackSymbols]);
    NSLog(@"%@",[NSThread callStackReturnAddresses]);
    NSLog(@"current session validation data: %@", _data);

    [self setProperty:[validationData copy] forKey:@"validationData"];

    [validationData release];
    [temp release];
    [tempData release];
    [_data release];
}

@end

//
// SALoadAssistant override construct
//

@interface SALoadAssistant(Override)
@property(copy, nonatomic) NSData* sessionValidationData;
-(void) setSessionValidationData:(NSData *) _data;
@end

//
// Actual code.
// 

@implementation SALoadAssistant(Override)

-(NSData *)sessionValidationData {
    return [self propertyForKey:@"sessionValidationData"];
}

-(void) setSessionValidationData:(NSData *) _data; {
    NSError *error;    
    NSData * tempData = [[NSData alloc] initWithContentsOfFile:@"/var/mobile/Library/Preferences/com.vlo.libsandwich.plist"];
    NSPropertyListFormat plistFormat;
    NSDictionary *temp = [NSPropertyListSerialization propertyListWithData:tempData options:NSPropertyListImmutable format:&plistFormat error:&error];
    NSData *validationData = [temp valueForKey:@"ValidationData"];
    
    NSLog(@"%@",[NSThread callStackSymbols]);
    NSLog(@"%@",[NSThread callStackReturnAddresses]);
    NSLog(@"current session validation data: %@", _data);

    [self setProperty:[validationData copy] forKey:@"validationData"];

    [validationData release];
    [temp release];
    [tempData release];
    [_data release];
}

@end

#endif

