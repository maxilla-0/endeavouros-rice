"Basics
set background=dark
set clipboard=unnamedplus
set mouse=a
set number
set title
set cursorline
set cursorcolumn
set noshowmode
set ic
set relativenumber

if has("autocmd")
  " When editing a file, always jump to the last cursor position
  autocmd BufReadPost *
  \ if line("'\"") > 0 && line ("'\"") <= line("$") |
  \   exe "normal g'\"" |
  \ endif
endif

call plug#begin()

Plug 'shinchu/lightline-gruvbox.vim'
Plug 'ellisonleao/gruvbox.nvim'
Plug 'arcticicestudio/nord-vim'
Plug 'itchyny/lightline.vim'

call plug#end()

colorscheme gruvbox

highlight Normal guibg=none
highlight NonText guibg=none

let g:lightline = {
   \ 'colorscheme': 'gruvbox'
   "\ 'separator': {'left': "\uE0B0", 'right': "\uE0B2"},
   "\ 'subseparator': { 'left': "\uE0B1", 'right': "\uE0B3"}
   \ }

"let g:lightline = {}
"let g:lightline.colorscheme = 'gruvbox'

"###### neovide config ######
"if exists("g:neovide")
"	set guifont=JetbrainsMono\ Nerd\ Font:h10
"endif
"let g:neovide_transparency = 0.9
"let g:neovide_padding_top = 10
"let g:neovide_padding_bottom = 10
"let g:neovide_padding_right = 10
"let g:neovide_padding_left = 10
