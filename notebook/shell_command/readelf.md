# readelf

* check Shared libraries
readelf -a libxxx.so | grep Shared

* GCC version
readelf -p .comment

* CPU version
readelf -h

* module version
readelf -p  .mmodule_version libxxx.so


