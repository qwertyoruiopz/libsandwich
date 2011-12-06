/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2.

File name:

    telephony.c

Abstract:

    Override CoreTelephony's functions.

--*/

#include <voodoo.h>

CFStringRef kCTMobileEquipmentInfoIMEI = CFSTR("99 000087 191876 1");
CT_SERVER_COPY_FIRMWARE_VERSION pCTServerConnectionCopyFirmwareVersion;
CT_SERVER_COPY_MOBILE_EQUIPMENT_INFO  pCTServerConnectionCopyMobileEquipmentInfo;
CT_SERVER_COPY_MOBILE_IDENTITY pCTServerConnectionCopyMobileIdentity;

//
// Sparsely documented functions follow.
//

CFStringRef
CTRegistrationCopyLocalizedOperatorName(
    VOID
    )
{
    return CFSTR(CARRIER);
}

CFStringRef
CTRegistrationCopyOperatorName(
    VOID
    )
{
    return CFSTR(CARRIER);
}

CFStringRef
CTRegistrationCopyAbbreviatedOperatorName(
    VOID
    )
{
    return CFSTR(CARRIER);
}

CFNumberRef
CTGetSignalStrength(
    VOID
    )
{
    INT SignalStrength[3] = {2, -100, 20};
    INT Parameter2 = 20;
    
    return CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &Parameter2);
}

CFStringRef
CTRegistrationGetStatus(
    VOID
    )
{
    return CFSTR("kCTRegistrationStatusDenied");
}

CFStringRef
CTRegistrationGetDataIndicator(
    VOID
    )
{
    return CFSTR("kCTRegistrationDataIndicator" DATA_TYPE);
}

CFStringRef
CTSettingCopyMyPhoneNumber(
    VOID
    )
{
    return CFSTR("972-364-4415");
}

CFNumberRef kCTIndicatorsGradedSignalStrength;
CFNumberRef kCTIndicatorsSignalStrength;
CFNumberRef kCTIndicatorsRawSignalStrength;

CFNumberRef
CTIndicatorsGetSignalStrength(
    __in INT Parameter1,
    __in INT Parameter2,
    __in INT Parameter3
    )
{
    INT SignalStrength[3] = {2, -100, 20};
    Parameter2 = 20;
    
    kCTIndicatorsGradedSignalStrength = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &SignalStrength[0]);
    kCTIndicatorsSignalStrength = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &SignalStrength[1]);
    kCTIndicatorsRawSignalStrength = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &SignalStrength[2]);
    
    return CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &Parameter2);
}

CFStringRef
CTSIMSupportGetSIMStatus(
    VOID
    )
{
    return CFSTR("kCTSIMSupportSIMStatusReady");
}

CFStringRef
CTSIMSupportGetSIMTrayStatus(
    VOID
    )
{
    return CFSTR("kCTSIMSupportSIMTrayInsertedWithSIM");
}

PINT
_CTServerConnectionCopyFirmwareVersion(
    PCORE_TELEPHONY_ERROR_STATUS Status,
    PVOID Connection,
    CFStringRef *FirmwareVersion
    )
{
    PINT Data;

    if(!pCTServerConnectionCopyFirmwareVersion)
        pCTServerConnectionCopyFirmwareVersion = dlsym(RTLD_NEXT, "_CTServerConnectionCopyFirmwareVersion");
    
    Data = pCTServerConnectionCopyFirmwareVersion(Status, Connection, FirmwareVersion);
    *FirmwareVersion = CFStringCreateWithCString(0, FIRMWARE_VERSION, kCFStringEncodingMacRoman);
    return Data;
}

PINT
_CTServerConnectionCopyMobileEquipmentInfo(
    PCORE_TELEPHONY_ERROR_STATUS Status,
    PVOID Connection,
    CFMutableDictionaryRef *Dictionary
    )
{
    PINT Data;
    INT i;
    CFStringRef Keys[3];
    CFStringRef Values[3];
    
     Keys[0] = CFSTR("kCTMobileEquipmentInfoIMEI");
     Keys[1] = CFSTR("kCTMobileEquipmentInfoICCID");
     Keys[2] = CFSTR("kCTMobileEquipmentInfoIMSI");
     Values[0] = CFSTR(IMEI);
     Values[1] = CFSTR(ICCID);
     Values[2] = CFSTR(IMSI);

    if(!pCTServerConnectionCopyMobileEquipmentInfo)
        pCTServerConnectionCopyMobileEquipmentInfo = dlsym(RTLD_NEXT, "_CTServerConnectionCopyMobileEquipmentInfo");

    Data = pCTServerConnectionCopyMobileEquipmentInfo(Status, Connection, Dictionary);

    NSLog(CFSTR("%@"), *Dictionary);

    *Dictionary = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    
    for(i = 0; i < 3; i++)
        CFDictionaryAddValue(*Dictionary, Keys[i], Values[i]); 
    
    return Data;
}

PINT
_CTServerConnectionCopyMobileIdentity(
    PCORE_TELEPHONY_ERROR_STATUS Status,
    PVOID Connection,
    CFStringRef *Imei
    )
{
    PINT Data;

    if(!pCTServerConnectionCopyMobileIdentity)
        pCTServerConnectionCopyMobileIdentity = dlsym(RTLD_NEXT, "_CTServerConnectionCopyMobileIdentity");
        
    Data = pCTServerConnectionCopyMobileIdentity(Status, Connection, Imei);

    *Imei = CFStringCreateWithCString(0, IMEI, kCFStringEncodingMacRoman);
    return Data;
}