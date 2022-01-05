# sysctl
ulimit -c unlimited
sysctl -w kernel.core_pattern=/var/core-%e-%s-%u-%g-%p-%t
cat /proc/sys/kernel/core_pattern

