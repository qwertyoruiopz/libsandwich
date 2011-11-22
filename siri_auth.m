/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2

File name:

    siri_auth.m

Abstract:

    Override the setSessionValidationData member in the SALoadAssistant
    class in SAObjects? It works? Not yet? What?

--*/

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
    unsigned char validationData[] = { /* data here, replace 0 */ 0 };
    NSLog(@"%@",[NSThread callStackSymbols]);
    NSLog(@"%@",[NSThread callStackReturnAddresses]);
    NSLog(@"current session validation data: %@", _data);
    
    NSData *cocoa_ValidationData = [NSData dataWithBytes:validationData length:sizeof(validationData)];
    
    [self setProperty:[cocoa_ValidationData copy] forKey:@"validationData"];

    [cocoa_ValidationData release];
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
    unsigned char validationData[] = { /* data here, replace 0 */ 0 };
    NSLog(@"%@",[NSThread callStackSymbols]);
    NSLog(@"%@",[NSThread callStackReturnAddresses]);
    NSLog(@"current session validation data: %@", _data);
    
    NSData *cocoa_ValidationData = [NSData dataWithBytes:validationData length:sizeof(validationData)];
    
    [self setProperty:[cocoa_ValidationData copy] forKey:@"sessionValidationData"];

    [cocoa_ValidationData release];
    [_data release];
}

@end

#endif

