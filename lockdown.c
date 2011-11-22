/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2

File name:

    lockdown.c

Abstract:

    Override liblockdown.dylib, hacktivate.

--*/

#include <voodoo.h>

#ifdef _HACKTIVATE_

PLOCKDOWN_COPY_VALUE pLockdown_copy_value;

CFTypeRef
lockdown_copy_value(
    __in PVOID LockdownConnection,
    __in CFStringRef Domain,
    __in CFStringRef Key
    )
/*++

Routine Description:

    Copy a value from domain:key using LockdownConnection
    as a connection to lockdownd.

Arguments:

    LockdownConnection  - Connection to lockdownd.
    Domain              - Domain that key is in.
    Key                 - Key to retrieve.

Return Value:

    Pointer to anything?

--*/
{
    CFStringRef ActivationState = CFSTR("FactoryActivated");
    CFStringRef DeviceUdid = CFSTR(DEVICE_UDID);

    //
    // Check to see if the real function is null.
    //
    
    if(!pLockdown_copy_value)
        pLockdown_copy_value = dlsym(RTLD_NEXT, "lockdown_copy_value");
    
    //
    // Check to see if the string is ours or not.
    //
    
    if(!CFStringCompare(Key, CFSTR("ActivationState"), 0))
        return ActivationState;
    if(!CFStringCompare(Key, CFSTR("BrickState"), 0))
        return kCFBooleanFalse;

    //
    // It's not.
    //
    
    return pLockdown_copy_value(LockdownConnection, Domain, Key);
}

#endif