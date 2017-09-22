# addr2line
PC: /lib/libc-2.24.so [0x74a65bac]
LR: /usr/lib/libadaptor.so.0.1.0 [0x759becd8]


754c8000-75a9a000 r-xp 00000000 b3:1f 146        /usr/lib/libkadaptor.so.0.1.0
75a9a000-75aaa000 ---p 005d2000 b3:1f 146        /usr/lib/libkadaptor.so.0.1.0
75aaa000-75b89000 rw-p 005d2000 b3:1f 146        /usr/lib/libkadaptor.so.0.1.0

>>> hex(0x759becd8-0x754c8000)
'0x4f6cd8'

$ addr2line -a -f -e ./libkadaptor.so 0x4f6cd8
