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
        echo "#include <cstring>">$TEMP_PATH
        echo "#include <string.h>">>$TEMP_PATH
        echo "#include <map>">>$TEMP_PATH
        echo "#include <deque>">>$TEMP_PATH
        echo "#include <queue>">>$TEMP_PATH
        echo "#include <stack>">>$TEMP_PATH
        echo "#include <sstream>">>$TEMP_PATH
        echo "#include <iostream>">>$TEMP_PATH
        echo "#include <iomanip>">>$TEMP_PATH
        echo "#include <cstdio>">>$TEMP_PATH
        echo "#include <cmath>">>$TEMP_PATH
        echo "#include <cstdlib>">>$TEMP_PATH
        echo "#include <ctime>">>$TEMP_PATH
        echo "#include <algorithm>">>$TEMP_PATH
        echo "#include <vector>">>$TEMP_PATH
        echo "#include <set>">>$TEMP_PATH
        echo "#include <complex>">>$TEMP_PATH
        echo "#include <list>">>$TEMP_PATH
        echo "#define PB push_back">>$TEMP_PATH
        echo "#define ALL(v) v.begin(),v.end()">>$TEMP_PATH
        echo "#define RALL(v) v.rbegin(),v.rend()">>$TEMP_PATH
        echo "#define REP_0(i,m) for(int i=0;i<(int)(m);i++)">>$TEMP_PATH
        echo "#define FOR_IT(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)">>$TEMP_PATH
        echo "#define MEMSET(a,b) memset(a,b,sizeof(a))">>$TEMP_PATH

        echo "using namespace std;" >> $TEMP_PATH
        echo "class Solution" >> $TEMP_PATH
        echo "{" >> $TEMP_PATH
        echo "};" >> $TEMP_PATH


        echo "" >> $TEMP_PATH
        echo "" >> $TEMP_PATH
        echo "#if 1" >> $TEMP_PATH
        echo "int main()" >> $TEMP_PATH
        echo "{" >> $TEMP_PATH
        echo "Solution S;" >> $TEMP_PATH
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



