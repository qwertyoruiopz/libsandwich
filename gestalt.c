/*++

Copyright (C) 2011,  Velocity Limitless Organization
Licensed under the GNU General Public License v2.

File name:

    gestalt.c

Abstract:

    Hook functions used by /usr/lib/libMobileGestalt.dylib,
    specifically libMobileGestalt!MGCopyAnswer.

--*/

#include <voodoo.h>

PMG_COPY_ANSWER_ROUTINE pMGCopyAnswer;

CFTypeRef
MGCopyAnswer(
    __in CFStringRef KeyToCopy
    )
/*++

Routine Description:

    Copy a CFData value from the internal mobilegestalt
    dictionary, and return a pointer to that CFData object.
    
Arguments:

    KeyToCopy   - Key to copy from MobileGestalt.

Return Value:

    Pointer to CFType object

--*/
{
    CFTypeRef ReturnData;
    CFStringRef DeviceName = CFSTR(DEVICE_NAME);
    CFStringRef MachineString = CFSTR(MACHINE_STRING);
    CFStringRef ModelNumber = CFSTR(MG_MODEL);
    CFStringRef ModelString = CFSTR(MODEL_STRING);
    CFStringRef SerialNumber = CFSTR(MG_SERIAL);
    
    //
    // Check to see if the real function is null.
    //
    
    if(!pMGCopyAnswer)
        pMGCopyAnswer = dlsym(RTLD_NEXT, "MGCopyAnswer");
    
    //
    // Check to see if the string is ours or not.
    //
    
    if(!CFStringCompare(KeyToCopy, CFSTR("ProductType"), 0))
        return MachineString;
    else if(!CFStringCompare(KeyToCopy, CFSTR("ModelNumber"), 0))
        return ModelNumber;
    else if(!CFStringCompare(KeyToCopy, CFSTR("SerialNumber"), 0))
        return SerialNumber;
    else if(!CFStringCompare(KeyToCopy, CFSTR("HWModelStr"), 0))
        return ModelString;
    else if(!CFStringCompare(KeyToCopy, CFSTR("DeviceName"), 0))
        return DeviceName;
    else if(!CFStringCompare(KeyToCopy, CFSTR("DeviceClass"), 0))
        return DeviceName;
    else if(!CFStringCompare(KeyToCopy, CFSTR("DeviceClass"), 0))
        return DeviceName;
        
    //
    // It's not.
    //
    
    ReturnData = pMGCopyAnswer(KeyToCopy);
    
    return ReturnData;
}

