##
## Makefile for Makefile in /home/bodart/projets/SRC
## 
## Made by louis bodart
## Login   <bodart_l@epitech.net>
## 
## Started on Sun Nov 18 12:37:28 2012 BODART Louis
## Last update Sun May 26 17:50:21 2013 BODART Louis
##

CC=		cc

RM=		rm -f

#CFLAGS +=	-ansi -pedantic
CFLAGS += 	-W -Wall -Wextra -Werror
CFLAGS +=	-g -I includes/

LDFLAGS =	-ltermcap

NAME =		42sh

SRCS =		alias/alias.c			\
		alias/alias_is.c		\
		alias/check_alias.c		\
		alias/display_alias.c		\
		alias/what_is_it.c		\
		builtins/cd.c			\
		builtins/env.c			\
		builtins/source.c		\
		builtins/get_pwd.c		\
		builtins/init_builtins.c	\
		builtins/set_env.c		\
		builtins/man.c			\
		builtins/unalias.c		\
		builtins/unset_env.c		\
		builtins/local_var.c		\
		builtins/exit.c			\
		builtins/my_echo.c		\
		convert_environment.c		\
		edit_command.c			\
		line_syntax.c			\
		glob.c				\
		env_var.c			\
		get_commands.c			\
		free_end.c			\
		historic/builting_histo.c	\
		historic/exclamation_histo.c	\
		historic/exec_histo.c		\
		historic/first_histo.c		\
		historic/free_histo.c		\
		historic/histo.c		\
		historic/recup_histo.c		\
		exec/built.c			\
		exec/exec.c			\
		exec/exec_one_cmd.c		\
		exec/cmd_and.c			\
		exec/cmd_or.c			\
		exec/cmd_pipe.c			\
		exec/redir.c			\
		exec/redir_left.c		\
		exec/redir_right.c		\
		get_environment.c		\
		get_next_line.c			\
		main.c				\
		mode_passif.c			\
		show_prompt.c			\
		parse_env.c			\
		parser/add_node.c		\
		parser/build_trees.c		\
		parser/explode.c		\
		parser/check_grammar.c		\
		parser/concatenation.c		\
		parser/line_cutter.c		\
		parser/line_lexer.c		\
		parser/line_parser.c		\
		parser/pre_lexer.c		\
		parser/separators.c		\
		parser/shell_grammar.c		\
		parser/replace_all.c		\
		parser/free_lexer.c		\
		lib/my_count_char.c		\
		lib/my_remove_in_tab.c		\
		lib/my_count_printable.c	\
		lib/my_epur_str.c		\
		lib/my_explode.c		\
		lib/my_explode_cote.c		\
		lib/my_getnbr.c			\
		lib/my_malloc.c			\
		lib/my_memset.c			\
		lib/my_printf.c			\
		lib/my_putnbr_base.c		\
		lib/my_put_nbr.c		\
		lib/my_putstr.c			\
		lib/my_revstr.c			\
		lib/my_strcat.c			\
		lib/my_strcmp.c			\
		lib/my_strcut.c			\
		lib/my_strdup.c			\
		lib/my_strlen.c			\
		lib/my_put_nbr_str.c		\
		lib/p_flag.c			\
		lib/my_atoi.c			\
		auto_completion/auto_complet.c	\
		auto_completion/add_complet.c	\
		term42/init_termcaps.c		\
		display_prompt.c		\
		term42/circu.c			\
		term42/delete.c			\
		term42/key.c			\
		term42/move.c			\
		term42/parseur.c		\
		term42/key_ctrl.c		\
		term42/moved.c			\
		term42/key_other.c		\
		term42/key_clear.c		\
		term42/key_tab.c		\
		term42/key_arrow.c		\
		term42/key_enter.c		\
		term42/key_delete.c		\
		term42/chainlist_to_str.c	\
		term42/term_func.c		\
		term42/term.c		

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
