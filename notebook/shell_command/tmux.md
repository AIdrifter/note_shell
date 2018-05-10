# tmux
C-b :source-file ~/.tmux.conf

" ctrl + a + d
" tmux attach
但是 tmux 其實是有一個很強的功能，你在不關機的情況下想要關閉 Terminal 但又不想要把剛開的東西都關掉，可以用 ctrl + b 按一下後按下 d 就可以把 tmux 從當前視窗「卸載」，然後等到你需要用的時候再執行 tmux attach 就可以把剛剛卸載的 tmux 給掛回來，工作環境就又回來了。


ctrl + a + &    关闭当前窗口

C+b + Ctrl + 方向鍵上/下/左/右
# 可以調整當前分割視窗的長寬，好用！

作用鍵 + d
# 將目前的 Tmux Session 丟到背景去

tmux ls
# 列出主機上所有的 Tmux Session

ctrl + a + z
最大化當前視窗

ctrl + a + n (next windows)
ctrl + a + p (previous windows)

ctrl + a + [        (insert mode)
           space    (copy)
ctrl + a + ]        (paste)

# send command to all windows
`Ctrl-b` then ":setw synchronize-panes"

Type your command to be executed in all panes in same window ;)

To turn off:

`Ctrl-b` then ":setw synchronize-panes off"

