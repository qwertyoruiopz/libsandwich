ARM-CC		:= arm-apple-darwin10-gcc-4.2.1
ARM-CFLAGS	:= -dynamiclib -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk -Fbinaries/System/Library/PrivateFrameworks/ -c -I include/ -I include/SAObjects/ -I include/Assistant -I.
ARM-LDCFLAGS	:= -fconstant-cfstrings -dynamiclib -Wall -multiply_defined suppress -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk  /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/usr/lib/libMobileGestalt.dylib -framework IOKit -framework CoreTelephony -framework CoreFoundation -framework SAObjects  -lobjc -Fbinaries/System/Library/PrivateFrameworks -framework Foundation -framework AppSupport /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/usr/lib/liblockdown.dylib
OBJS		:= siri_auth.o gestalt.o iokit.o sysctl.o telephony.o lockdown.o
LDID		:= ldid
DYLIB		:= libsandwich.dylib

libsandwich.dylib: $(OBJS)
	$(ARM-CC) $(OBJS) $(ARM-LDCFLAGS) -o $(DYLIB)
	$(LDID) -S $(DYLIB)

%.o : %.m
	$(ARM-CC) $(ARM-CFLAGS) -c $<

%.o : %.c
	$(ARM-CC) $(ARM-CFLAGS) -c $<

clean:
	rm $(DYLIB) $(OBJS)
