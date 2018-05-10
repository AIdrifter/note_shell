# stop process
kill -stop PID ; # stop PID (Ctrl + Z
sleep 10s ; # "sleep" command  stop himself 10s
kill -cont PID # recover the stop PID ( fg

PID=465; kill -stop $PID; sleep 10s; kill -cont $PID

when process be stoped, process can got to background(bg) or foreground(fg)

