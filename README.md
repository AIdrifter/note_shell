# How to start note shell
- 1. clone your note shell
- 2. .vimrc and .tmux.conf will update
- 3. notebook folder saved note information

how to install ?
```bash
./install.sh
```
## which command support?
- _fls : find file and list its data and owners
- _fld : find folder and list its data and owners
- _cscope : create file which cscope needed
- _sed : replace the words

## Notebook
Edit notebook information
```bash
c $bookoname $edit
```

cat notebook information
```bash
c $bookoname
```

search notebook information
```bash
g $bookname
```

show notebook information
```bash
cl $bookname
```


## Others
- You need install vim vundle berfore using vim
- Install Plugins:

   Launch `vim` and run `:PluginInstall`

   To install from command line: `vim +PluginInstall +qall`

## News
- sdcv support to find work chinese to english or english to chinese
- vim support to look up dictionary `\w`
