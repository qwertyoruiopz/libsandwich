MODELID		:= _BLACK_IPHONE_4S_UNKNOWN_DEMO
ARM-CC		:= arm-apple-darwin10-gcc-4.2.1
ARM-CFLAGS	:= -dynamiclib -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk -Fbinaries/System/Library/PrivateFrameworks/ -c -I include/ -I include/SAObjects/ -I include/Assistant -I. -g -D$(MODELID)
ARM-LDCFLAGS	:= -fconstant-cfstrings -dynamiclib -Wall -multiply_defined suppress -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk  /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/usr/lib/libMobileGestalt.dylib -framework IOKit -framework CoreTelephony -framework CoreFoundation -framework SAObjects  -lobjc -Fbinaries/System/Library/PrivateFrameworks -framework Foundation -framework AppSupport /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/usr/lib/liblockdown.dylib -g
OBJS		:= siri_auth.o gestalt.o iokit.o sysctl.o telephony.o lockdown.o
LDID		:= ldid
DYLIB		:= libsandwich.dylib

libsandwich.dylib: $(OBJS)
	@echo Linking $(DYLIB)...
	@$(ARM-CC) $(OBJS) $(ARM-LDCFLAGS) -o $(DYLIB)
	@echo Fake-codesigning $(DYLIB)...
	@$(LDID) -S $(DYLIB)

%.o : %.m
	@echo Compiling $<
	@$(ARM-CC) $(ARM-CFLAGS) -c $<

%.o : %.c
	@echo Compiling $<
	@$(ARM-CC) $(ARM-CFLAGS) -c $<

clean:
	@echo Deleting "$(DYLIB) $(OBJS)"...
	@rm $(DYLIB) $(OBJS)
