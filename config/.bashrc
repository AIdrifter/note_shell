export TERM="xterm-256color"
export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad

# color set
GREEN1="\[\033[01;32m\]"
WHITE="\[\033[00m\]"
GREEN2="\[\033[01;36m\]"
YELLOW="\[\033[0;33m\]"
RED="\[\033[0;31m\]"
RED_BOLD="\[$(tput bold)\]\[\033[38;5;196m\]"
YELLOW="\[\033[0;33m\]"
GREEN="\[\033[0;32m\]"
BLOD_GREEN="\[$(tput bold)\]\[\033[38;5;10m\]"
BLUE="\[\033[38;5;14m\]"
BLOD_BLUE="\[$(tput bold)\]\[\033[38;5;14m\]"
NO_COLOR="\[\033[0m\]"
NEW_LINE="\n\[$(tput sgr0)\]"

# display console
PS1="$NEW_LINE $BLOD_BLUE\w$YELLOW\$(parse_git_branch)$NEW_LINE$BLOD_GREEN\u@\h$NO_COLOR\$ "

# Commands
export note_shell_path=${VARIABLE:=~/note_shell}
eval `dircolors`
alias ls='ls --color=auto '
alias ll='ls -alrt'
alias la='ls -A'
alias l='ls -CF'
alias dir='ls --color=auto --format=vertical'
alias vdir='ls --color=auto --format=long'
alias grep='grep --color'
alias grep1='grep --color -A 5 -B 5 -R -i -nH'
alias grep2='grep1 --exclude='*tags' --exclude='*.files' --exclude='*.out''
alias tmux="TERM=screen-256color-bce tmux"
alias mdv='~/bin/terminal_markdown_viewer/mdv.py'
alias cat='~/bin/Pygments-2.2.0/pygmentize -g'
alias fdls='find . -type d -name'
alias DB='source _cscope DB'
alias vi='vim --noplugin'

# notebook
alias g="sh  $note_shell_path/scripts/_grep_notebook.sh"
alias h="source $note_shell_path/scripts/_history_special.sh"
alias c="sh $note_shell_path/scripts/_notebook.sh"
alias cl="ls -l  $note_shell_path/notebook"

# cdargs
source $note_shell_path/config/cdargs/cdargs-bash.sh

# note shell scripts
export PATH=$PATH:$note_shell_path/bin:$note_shell_path/scripts/

#From http://rgba.tumblr.com/post/520663635/including-current-git-branch-in-your-bash-prompt setting for Git
function parse_git_branch {
    git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}

HISTTIMEFORMAT=`echo -e "\033[1;34m %F %T \033[0m"`
