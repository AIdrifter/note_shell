# telnet
`Server`
 telnetd -l /bin/sh

`Client`

telnet 172.16.59.184
telnet 172.16.58.247

telnet 192.168.10.6 8000
telnet 192.168.10.6 8080
telnet 192.168.10.6 8085
telnet 192.168.10.6 8885

config_set fw.system.run-as-process no
config_set fw.discardable.storage.enable false
