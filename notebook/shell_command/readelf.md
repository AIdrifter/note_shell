# readelf

* check Shared libraries
readelf -a libxxx.so | grep Shared

* GCC version
readelf -p .comment

* CPU version
readelf -h

* module version
readelf -p  .mmodule_version libxxx.so

* list all symbols even though they stripped
readelf -sDW .

find ./ -name \*.so | parallel "readelf -sDW  {} 2>/dev/null | grep _ZN4Roku9SingletonINS_2v114CodecDBWrapperEEERT_v && echo {}"

