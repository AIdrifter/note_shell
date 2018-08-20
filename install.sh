#!/bin/sh
echo "please set your note shell path before install"
note_shell_path=${VARIABLE:=~/note_shell}
cp  $note_shell_path/config/.bashrc ~/
cp  $note_shell_path/config/.vimrc ~/
cp  $note_shell_path/config/.tmux.conf ~/

# ubuntu plugin
echo "install plugin"
sudo apt-get install cscope
sudo apt-get install cdargs

# vim
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

# sdcv : dictionary
sudo apt-get install sdcv
git clone https://github.com/chusiang/vim-sdcv.git
cp vim-sdcv/plugin/sdcv.vim ~/.vim/plugin
mkdir -p ~/.stardict/dic/
cp -rf  $note_shell_path/config/dictionary/*  ~/.stardict/dic/

# chrome
wget -c https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb --no-check-certificate
sudo dpkg -i google-chrome-stable_current_amd64.deb
sudo apt-get install

# Ag : silversearcher-ag
sudo apt-get install silversearcher-ag


echo "note shell install finish"


