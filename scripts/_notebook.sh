#!bin/bash

TEMP_PATH=$PWD/main.c

if [ ! -z "$2" ];then
    echo "notebook rw mode"
    vim $note_shell_path/notebook/shell_command/$1.md
    exit
fi

if [ ! -z "$1" ] ;then
    if [ 'main' = "$1" ];then
        # create $TEMP_PATH fastly
        echo "Quickly Generate $TEMP_PATH"
        echo "#include <stdio.h>" > $TEMP_PATH
        echo "#include <stdlib.h>" >> $TEMP_PATH
        echo "#include <stdint.h>" >> $TEMP_PATH
        echo "#include <stdbool.h>" >> $TEMP_PATH
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
    echo "notebook r mode"
    cat $note_shell_path/notebook/shell_command/$1.md
    exit
fi


