""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" coding tytle                                       "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" language UTF8 problem
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set nu


" ignore case and search word
set ic
set hlsearch

" set tap problem
filetype plugin indent on
" show existing tab with 4 spaces width
set tabstop=4
" when indenting with '>', use 4 spaces width
set shiftwidth=4
" On pressing tab, insert 4 spaces
set expandtab


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"  Add plugin vim BEGIN()
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()


" NERdtses
" Plugin 'scrooloose/nerdtree'
" Plugin 'SrcExpl'
" Plugin 'Xuyuanp/nerdtree-git-plugin'"

" bookmark
Plugin 'MattesGroeger/vim-bookmarks'
Plugin 'vasconcelloslf/vim-interestingwords' " hight light key word
Plugin 'airblade/vim-gitgutter'

" Airline
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'

" Check your systastic and compler error
 Plugin 'scrooloose/syntastic' " support vim 7
"Plugin 'w0rp/ale' " support vim 8
" fix bakcspace problem in insert mode
set backspace=indent,eol,start
"let g:ale_statusline_format = ['⨉ %d', '⚠ %d', '⬥ ok']
" find header problem
"let g:c_syntax_for_h = 1
"let g:syntastic_ada_no_default_include_dirs = 1
"let b:syntastic_ada_cflags = ' -I/usr/include/libsoup-2.4'

" fzf
Plugin 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plugin 'junegunn/fzf.vim'

" Commentify
Plugin 'scrooloose/nerdcommenter'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

"""""""""""""""""""""""""""END() """""""""""""""""""""""""""""""""""""""



""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"                       Plugin Setup
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"
" airline set
"
set laststatus=2
" 使用powerline打過補丁的字體
let g:airline_powerline_fonts = 1
" 開啟tabline
let g:airline#extensions#tabline#enabled = 1
" tabline中當前buffer兩端的分隔字符
let g:airline#extensions#tabline#left_sep = ' '
" tabline中未激活buffer兩端的分隔字符
let g:airline#extensions#tabline#left_alt_sep = '|'
" tabline中buffer顯示編號
let g:airline#extensions#tabline#buffer_nr_show = 1
" 映射切換buffer的鍵位
nmap .. :bn<CR>
nmap ,, :bp<CR>
"nmap q : bd<CR>


"
" scrooloose/syntastic
"
let g:syntastic_error_symbol='>>'
let g:syntastic_warning_symbol='>'
let g:syntastic_check_on_open=1
let g:syntastic_check_on_wq=0
let g:syntastic_enable_highlighting=1
let g:syntastic_python_checkers=['pyflakes'] " 使用pyflakes,速度比pylint快
let g:syntastic_javascript_checkers = ['jsl', 'jshint']
let g:syntastic_html_checkers=['tidy', 'jshint']
" 修改高亮的背景色, 适应主题
highlight SyntasticErrorSign guifg=white guibg=black

" to see error location list
let g:syntastic_always_populate_loc_list = 0
let g:syntastic_auto_loc_list = 0
let g:syntastic_loc_list_height = 5
function! ToggleErrors()
    let old_last_winnr = winnr('$')
    lclose
    if old_last_winnr == winnr('$')
        " Nothing was closed, open syntastic error location panel
        Errors
    endif
endfunction
nnoremap <Leader>s :call ToggleErrors()<cr>
" nnoremap <Leader>sn :lnext<cr>
" nnoremap <Leader>sp :lprevious<cr>


"
" cscope setting
"
" [S] Find this C symbol
cs add $CSCOPE_DB
nmap cs :cs find s

" [G] Find this definition
nmap cg :cs find g

" [C] Find functions calling this function
nmap cc :cs find c

" [T] Find this text string
nmap ct :cs find t

" [E] Find this egreo pattern
nmap ce :cs find e

nmap cf :cs find f

" [I] Find files #including this file
nmap ci :cs find i ^=expand("")$

" [D] Find functions called by this function
nmap cd :cs find d



"
" bookmark
"
highlight BookmarkSign ctermbg=NONE ctermfg=160
highlight BookmarkLine ctermbg=20 ctermfg=NONE
let g:bookmark_no_default_key_mappings = 1
function! BookmarkMapKeys()
    nmap mm :BookmarkToggle<CR>
    nmap mi :BookmarkAnnotate<CR>
    nmap mn :BookmarkNext<CR>
    nmap mp :BookmarkPrev<CR>
    nmap ma :BookmarkShowAll<CR>
    nmap mc :BookmarkClear<CR>
    nmap mx :BookmarkClearAll<CR>
    nmap mkk :BookmarkMoveUp
    nmap mjj :BookmarkMoveDown
endfunction
function! BookmarkUnmapKeys()
    unmap mm
    unmap mi
    unmap mn
    unmap mp
    unmap mc
    unmap ma
    unmap mx
    unmap mkk
    unmap mjj
endfunction
autocmd BufEnter * :call BookmarkMapKeys()
autocmd BufEnter NERD_tree_* :call BookmarkUnmapKeys()
let g:bookmark_manage_per_buffer = 1
let g:bookmark_save_per_working_dir = 1
let g:bookmark_auto_save = 1
let g:bookmark_highlight_lines = 1

"
" majutsushi/tagbar
"
nmap <F8> :TagbarToggle<CR>

"
" Ag
"
command! -bang -nargs=* Ag
  \ call fzf#vim#ag(<q-args>,
  \                 <bang>0 ? fzf#vim#with_preview('up:60%')
  \                         : fzf#vim#with_preview('right:50%:hidden', '?'),
  \                 <bang>0)
nnoremap <silent> <Leader>a :Ag<CR>

"
" FZF
"
nnoremap <silent> <C-p> :Files<CR>
map <leader>f ::History<CR>


""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"  nmap other hot key                                    "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" remove remainder space
nmap rs :call setline(1,map(getline(1,"$"),'substitute(v:val,"\\s\\+$","","")'))<CR>
nmap nu :set nu<CR>
nmap nonu :set nonu<CR>

" paste
set paste

" nerdcommenter
filetype plugin on
let g:NERDSpaceDelims=1
let g:NERDTrimTrailingWhitespace = 1

" color display
syntax on
set t_Co=256       " Explicitly tell Vim that the terminal supports 256 colors


" support directionary
nmap <leader>w :call SearchWord()<CR>

"maximam current windows ( <leade> + z
function! Zoom ()
    " check if is the zoomed state (tabnumber > 1 && window == 1)
    if tabpagenr('$') > 1 && tabpagewinnr(tabpagenr(), '$') == 1
        let l:cur_winview = winsaveview()
        let l:cur_bufname = bufname('')
        tabclose
        " restore the view
        if l:cur_bufname == bufname('')
            call winrestview(cur_winview)
        endif
    else
        tab split
    endif
endfunction
nmap <leader>z :call Zoom()<CR>

" scheme
colorscheme slate
" colorscheme monokai

" High light unwanted spaces in end of line
highlight ExtraWhitespace ctermbg=darkred guibg=darkcyan
autocmd BufEnter * if &ft != 'help' | match ExtraWhitespace /\s\+$/ | endif
autocmd BufEnter * if &ft == 'help' | match none /\s\+$/ | endif

" hi  ()
hi MatchParen ctermbg=blue ctermfg=yellow

hi CursorLine   cterm=NONE ctermbg=235 ctermfg=NONE
hi CursorColumn   cterm=NONE ctermbg=242 ctermfg=NONE
set cursorcolumn
set cursorline

" define your region
highlight Foo ctermbg=16 guibg=#000000
syntax region Foo start=/^\s*#ifdef.*_DEBUG/ end=/^\s*#endif/
set expandtab

set nonu
