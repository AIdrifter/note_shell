# network eth0
-  focre to set static IP

```shell
ifconfig eth0 up
ifconfig eth0 172.16.38.217 netmask 255.255.252.0
```
- find your gate way(board has network alive)
    - Gateway : `172.16.58.254`
```shell
# route
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
default         172.16.58.254   0.0.0.0         UG    0      0        0 eth0
172.16.56.0     *               255.255.252.0   U     0      0        0 eth0
```
- add your gateway

```shell
route add default gw 175.16.59.254
```
