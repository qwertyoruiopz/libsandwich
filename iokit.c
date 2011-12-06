/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2.

File name:

    iokit.c

Abstract:

    Hook functions used by IOKit the framework,
    specifically IOKit!IORegistryEntryCreateCFProperty.

--*/

#include <voodoo.h>

PIO_REGISTRY_ENTRY_CREATE_CF_PROPERTY pIORegistryEntryCreateCFProperty;

CFTypeRef
IORegistryEntryCreateCFProperty(
    __in PVOID Entry,
    __in CFStringRef Key,
    __in CFAllocatorRef Allocator,
    __in PVOID Options
    )
/*++

Routine Description:

    Return a CFTypeRef object from the Key in Entry's dictionary.

Arguments:

    Entry       - Dictionary.
    Key         - Key to retrieve.
    Allocator   - Which allocator should be used.
    Options     - Unused.
    
Return Value:

    Pointer to a CFTypeRef object.

--*/
{
    CONST UInt8 ModelBuffer[32] = MG_MODEL;
    CONST UInt8 MachineBuffer[9] = MODEL_STRING;
    CONST UInt8 MlbSerialBuffer[16] = MLB_SERIAL;
    CONST UInt8 UniqueChipId[8] = {0x8e, 0xf5, 0x0c, 0x20, 0xec, 0x02, 0x00, 0x00};
    CONST UInt8 DieId[8] = {0x00, 0x61, 0x97, 0x8d, 0xd6, 0x47, 0x2e, 0x2d};
    CFStringRef SerialNumber = CFSTR(MG_SERIAL);
    CFDataRef DataValue;
    
    //
    // Check to see if hooked function is null or not.
    // 
    
    if(!pIORegistryEntryCreateCFProperty)
        pIORegistryEntryCreateCFProperty = dlsym(RTLD_NEXT, "IORegistryEntryCreateCFProperty");
        
    //
    // Do we handle it?
    //
    
    if(!CFStringCompare(Key, CFSTR("model-number"), 0)) {
        DataValue = CFDataCreate(kCFAllocatorDefault, ModelBuffer, 32);
        return DataValue;
    } else if(!CFStringCompare(Key, CFSTR("model"), 0)) {
        DataValue = CFDataCreate(kCFAllocatorDefault, MachineBuffer, 9);
        return DataValue;
    } else if(!CFStringCompare(Key, CFSTR("mlb-serial-number"), 0)) {
        DataValue = CFDataCreate(kCFAllocatorDefault, MlbSerialBuffer, 16);
        return DataValue;
    } else if(!CFStringCompare(Key, CFSTR("die-id"), 0)) {
        DataValue = CFDataCreate(kCFAllocatorDefault, DieId, 8);
        return DataValue;
    } else if(!CFStringCompare(Key, CFSTR("unique-chip-id"), 0)) {
        DataValue = CFDataCreate(kCFAllocatorDefault, UniqueChipId, 8);
        return DataValue;
    } else if(!CFStringCompare(Key, CFSTR("IOPlatformSerialNumber"), 0)) {
        return SerialNumber;
    }
    
    //
    // We don't.
    //
    
    return pIORegistryEntryCreateCFProperty(Entry, Key, Allocator, Options);

}