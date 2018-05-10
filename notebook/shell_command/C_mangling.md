# C magling
$ readelf -a ./lib/tee/libFkmAgent.so |  grep FkmAG_CreateInstance
0x4174 <_Z20FkmAG_CreateInstancePj>: 0x80b108ab
    77: 00004175   260 FUNC    GLOBAL DEFAULT   10 _Z20FkmAG_CreateInstanceP
   165: 00012894    21 OBJECT  LOCAL  DEFAULT   12 _ZZ20FkmAG_CreateInstance
   964: 00004175   260 FUNC    GLOBAL DEFAULT   10 _Z20FkmAG_CreateInstanceP


