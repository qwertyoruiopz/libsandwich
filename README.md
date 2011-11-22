libsandwich 0.0.0.1
===================

Previously known as libvoodoogestalt, libsandwich allows you to modify
lower level details of your iDevice using dyld function interposition.
The dylib is sandwiched between any executable, overriding functions as
necessary.

Compiling
---------

    make

Just as easy as that. Make sure to have your iOS 5 SDK installed in /Developer
and in the usual location in that folder, and make sure to have the iPhone4S
dyld cache binaries (dumped using dyld_decache) in binaries/. Also make sure
to compile ldid.

Usage
-----

Make sure to have the dylib on the root filesystem of the target iDevice,
then export the following environment variables for the target process:

    DYLD_INSERT_LIBRARIES=/usr/lib/libsandwich.dylib
    DYLD_FORCE_FLAT_NAMESPACE=1

Some applications will crash, some will not. You will get interesting results
based on whatever you do!


