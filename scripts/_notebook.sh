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
        TEMP_PATH=$PWD/main.cpp
        echo "Quickly Generate $TEMP_PATH"
        echo "#include <iostream>" > $TEMP_PATH
        echo "#include <vector>" >> $TEMP_PATH
        echo "#include <string>" >> $TEMP_PATH
        echo "#include <map>" >> $TEMP_PATH
        echo "using namespace std;" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "#if 1" >> $TEMP_PATH
        echo "int main()" >> $TEMP_PATH
        echo "{" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "    return 0;" >> $TEMP_PATH
        echo "}" >> $TEMP_PATH
        echo "#endif" >> $TEMP_PATH
        vim $TEMP_PATH
        exit
    fi

    echo "notebook r mode"
    cat $note_shell_path/notebook/shell_command/$1.md
    exit
fi



