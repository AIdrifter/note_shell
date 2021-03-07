#!bin/bash


if [ ! -z "$2" ];then
    echo "notebook rw mode"
    vim $note_shell_path/notebook/shell_command/$1.md
    exit
fi

if [ ! -z "$1" ] ;then
    if [ 'main' = "$1" ];then
        TEMP_PATH=$PWD/main.c
        echo "Quickly Generate $TEMP_PATH"
        echo "#include <stdio.h>" > $TEMP_PATH
        echo "#include <stdlib.h>" >> $TEMP_PATH
        echo "#include <stdint.h>" >> $TEMP_PATH
        echo "#include <stdbool.h>" >> $TEMP_PATH
        echo "#include <string.h>" >> $TEMP_PATH
        echo "#include <unistd.h>" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "int main()" >> $TEMP_PATH
        echo "{" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "    return 0;" >> $TEMP_PATH
        echo "}" >> $TEMP_PATH
        vim $TEMP_PATH
        exit
    fi
    if [ 'cpp' = "$1" ];then
        cp $note_shell_path/notebook/main.cpp $PWD/main.cpp
        vim $PWD/main.cpp
        exit
    fi

    echo "notebook r mode"
    cat $note_shell_path/notebook/shell_command/$1.md
    exit
fi



