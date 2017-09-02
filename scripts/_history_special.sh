#!/bin/sh
if [ -z "$1" ];then
    history
else
    history | grep --color "$filter_var"
fi


