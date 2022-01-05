# cgroup
none on /dev/cgroup type tmpfs (rw,relatime)
none on /dev/cgroup/memory type cgroup (rw,relatime,memory)
none on /dev/cgroup/cpu type cgroup (rw,relatime,cpu)
none on /tmp/plugin/JFAAAA6013Ku/dev/cgroup type tmpfs (rw,relatime)
none on /tmp/plugin/JFAAAA6013Ku/dev/cgroup/memory type cgroup (rw,relatime,memory)
none on /tmp/plugin/JFAAAA6013Ku/dev/cgroup/cpu type cgroup (rw,relatime,cpu)
none on /tmp/plugin/JFAAAA6013Ku/tmp/plugin/JFAAAA6013Ku/dev/cgroup type tmpfs (rw,relatime)
none on /tmp/plugin/JFAAAA6013Ku/tmp/plugin/JFAAAA6013Ku/dev/cgroup/memory type cgroup (rw,relatime,memory)
none on /tmp/plugin/JFAAAA6013Ku/tmp/plugin/JFAAAA6013Ku/dev/cgroup/cpu type cgroup (rw,relatime,cpu)

 
#!/bin/sh
# Set up cgroups mountpoints
mkdir -p /dev/cgroup
mount -t tmpfs none /dev/cgroup
mkdir -p /dev/cgroup/memory
mount -t cgroup none /dev/cgroup/memory -o memory
mkdir -p /dev/cgroup/cpu
mount -t cgroup none /dev/cgroup/cpu -o cpu


./init.d/S95cgroups
#!/bin/sh

# Set up cgroups mountpoints
mkdir -p /dev/cgroup
mount -t tmpfs none /dev/cgroup

mkdir -p /dev/cgroup/memory /dev/cgroup/cpu
mount -t cgroup none /dev/cgroup/memory -o memory
mount -t cgroup none /dev/cgroup/cpu -o cpu

