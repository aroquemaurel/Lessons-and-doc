if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
imap <silent> <Plug>IMAP_JumpBack =IMAP_Jumpfunc('b', 0)
imap <silent> <Plug>IMAP_JumpForward =IMAP_Jumpfunc('', 0)
inoremap <silent> <Plug>NERDCommenterInInsert  <BS>:call NERDComment(0, "insert")
inoremap <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
vmap <NL> <Plug>IMAP_JumpForward
nmap <NL> <Plug>IMAP_JumpForward
noremap  :set spell spelllang=fr 
nmap \ca <Plug>NERDCommenterAltDelims
vmap \cA <Plug>NERDCommenterAppend
nmap \cA <Plug>NERDCommenterAppend
vmap \c$ <Plug>NERDCommenterToEOL
nmap \c$ <Plug>NERDCommenterToEOL
vmap \cu <Plug>NERDCommenterUncomment
nmap \cu <Plug>NERDCommenterUncomment
vmap \cn <Plug>NERDCommenterNest
nmap \cn <Plug>NERDCommenterNest
vmap \cb <Plug>NERDCommenterAlignBoth
nmap \cb <Plug>NERDCommenterAlignBoth
vmap \cl <Plug>NERDCommenterAlignLeft
nmap \cl <Plug>NERDCommenterAlignLeft
vmap \cy <Plug>NERDCommenterYank
nmap \cy <Plug>NERDCommenterYank
vmap \ci <Plug>NERDCommenterInvert
nmap \ci <Plug>NERDCommenterInvert
vmap \cs <Plug>NERDCommenterSexy
nmap \cs <Plug>NERDCommenterSexy
vmap \cm <Plug>NERDCommenterMinimal
nmap \cm <Plug>NERDCommenterMinimal
vmap \c  <Plug>NERDCommenterToggle
nmap \c  <Plug>NERDCommenterToggle
vmap \cc <Plug>NERDCommenterComment
nmap \cc <Plug>NERDCommenterComment
nmap gx <Plug>NetrwBrowseX
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
vmap <silent> <Plug>IMAP_JumpBack `<i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpBack "_<Del>i=IMAP_Jumpfunc('b', 0)
vmap <silent> <Plug>IMAP_DeleteAndJumpForward "_<Del>i=IMAP_Jumpfunc('', 0)
nmap <silent> <Plug>IMAP_JumpBack i=IMAP_Jumpfunc('b', 0)
nmap <silent> <Plug>IMAP_JumpForward i=IMAP_Jumpfunc('', 0)
nmap <silent> <Plug>NERDCommenterAppend :call NERDComment(0, "append")
nnoremap <silent> <Plug>NERDCommenterToEOL :call NERDComment(0, "toEOL")
vnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(1, "uncomment")
nnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(0, "uncomment")
vnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(1, "nested")
nnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(0, "nested")
vnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(1, "alignBoth")
nnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(0, "alignBoth")
vnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(1, "alignLeft")
nnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(0, "alignLeft")
vmap <silent> <Plug>NERDCommenterYank :call NERDComment(1, "yank")
nmap <silent> <Plug>NERDCommenterYank :call NERDComment(0, "yank")
vnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(1, "invert")
nnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(0, "invert")
vnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(1, "sexy")
nnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(0, "sexy")
vnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(1, "minimal")
nnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(0, "minimal")
vnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(1, "toggle")
nnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(0, "toggle")
vnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(1, "norm")
nnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(0, "norm")
nnoremap <silent> <F9> :NERDTree 
noremap <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
noremap <F6> :set nospell 
noremap <F4> :set spell spelllang=en 
imap <NL> <Plug>IMAP_JumpForward
inoremap <expr>  omni#cpp#maycomplete#Complete()
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap <expr> > omni#cpp#maycomplete#Arrow()
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set backspace=2
set backupdir=~/.vim/backup
set cindent
set completeopt=preview,menuone
set fileencodings=ucs-bom,utf-8,default,latin1
set grepprg=grep\ -nH\ $*
set helplang=fr
set hlsearch
set ignorecase
set incsearch
set infercase
set laststatus=2
set modelines=3
set mouse=a
set omnifunc=omni#cpp#complete#Main
set printoptions=paper:a4
set report=0
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim71,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set scrolloff=3
set shiftwidth=4
set shortmess=atI
set showcmd
set smartindent
set smarttab
set softtabstop=4
set nostartofline
set statusline=%<%f%m\ %r\ %h\ %w%=%l,%c\ %p%%
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tabstop=4
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/stl,~/.vim/tags/gl,~/.vim/tags/sdl,~/.vim/tags/qt4
set title
set visualbell
set whichwrap=b,s,h,l,<,>,[,]
set wildmode=list:full
" vim: set ft=vim :
