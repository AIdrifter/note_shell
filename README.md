# How to start note shell
- 1. clone your note shell
- 2. .vimrc and .tmux.conf will update
- 3. notebook folder saved note information

how to install ?
```shell
./install.sh
```
## which command support?
- _fls : find file and list its data and owners
- _fld : find folder and list its data and owners
- _cscope : create file which cscope needed
- _sed : replace the words

## Notebook
Edit notebook information
```shell
c $bookoname $edit
```

cat notebook information
```shell
c $bookoname
```

search notebook information
```shell
g $bookname
```

show notebook information
```shell
cl $bookname
```

show command on history
```shell
# h $keyword
bash> h git

  562   2018-06-19 23:17:32 git add README.md
  563   2018-06-19 23:17:35 git add singleton.cpp
  565   2018-06-19 23:17:40 git commit
  566   2018-06-19 23:18:32 git push
  567   2018-06-19 23:18:43 git push
  571   2018-06-20 15:06:15 git pull
  577   2018-06-20 15:06:46 git rm a.out
  581   2018-06-20 15:07:56 git add _notebook.sh
```

create main.c to test quickly in your current position
```shell
c main
```

## Others
- You need install vim vundle berfore using vim
- Install Plugins:

   Launch `vim` and run `:PluginInstall`

   To install from command line: `vim +PluginInstall +qall`

## News
- sdcv support to find work chinese to english or english to chinese
- vim support to look up dictionary `\w`
