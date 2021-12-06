# sysctlat /proc/sys/kernel/core_pattern
ulimit -c unlimited
sudo sysctl -w kernel.core_pattern=/var/tmp/core-xxx
cat /proc/sys/kernel/core_pattern

