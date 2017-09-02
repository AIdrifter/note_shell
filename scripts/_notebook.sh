#!bin/bash

if [ ! -z "$2" ];then
    echo "notebook rw mode"
    vim $note_shell_path/notebook/$1
    exit
fi

if [ ! -z "$1" ] ;then
    echo "notebook r mode"
    cat $note_shell_path/notebook/$1
    exit
fi


