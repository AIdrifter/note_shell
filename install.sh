#!/bin/sh
echo "please set your note shell path before install"
note_shell_path=${VARIABLE:=~/note_shell}
cp  $note_shell_path/config/.bashrc ~/
cp  $note_shell_path/config/.vimrc ~/
cp  $note_shell_path/config/.tmux.conf ~/

# plugin
echo "install plugin"
sudo apt-get install cscope
sudo apt-get install cdargs

echo "install finish"
