/*
** parser.h for parser in /home/bodart/projets/Tek1/42sh/parser
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May  6 14:12:50 2013 BODART Louis
** Last update Sun May 26 17:54:54 2013 BODART Louis
*/

#ifndef PARSER_H_
# define PARSER_H_

#define	TRUE	1
#define	FALSE	0
#define	SIMPL_R	0
#define	DOUBL_R	1
#define	SIMPL_L	2
#define	DOUBL_L	3

#include	<term.h>
#include	"alias.h"
#include	"histo.h"

typedef	struct	s_node	t_node;
typedef	struct	s_trees	t_trees;
typedef	struct	s_lex	t_lex;
typedef	struct	s_env	t_env;
typedef	struct	s_cmd	t_cmd;
typedef	struct	s_infos	t_infos;
typedef	struct	s_built	t_built;
typedef struct	s_link	t_link;
typedef struct	s_term	t_term;
typedef	struct	s_tcaps	t_tcaps;

struct		s_node
{
  int		type;
  char		*word;
  t_node	*left;
  t_node	*right;
  t_node	*parent;
};

struct		s_trees
{
  t_node	*root;
  t_trees	*nxt;
};

struct		s_lex
{
  int		type;
  char		*word;
  t_lex		*nxt;
  t_lex		*prv;
};

struct		s_env
{
  char		*name;
  char		*value;
  t_env		*nxt;
};

struct		s_cmd
{
  char		*word;
  t_cmd		*nxt;
};

struct		s_infos
{
  char		*hidden_pwd;
  char		*hidden_old_pwd;
};

struct		s_built
{
  char		*name;
  int		(*function)(t_link *, char **);
  t_built	*nxt;
};

struct		s_term
{
  struct termios	termios;
  struct termios	sauv;
};

typedef struct	s_line
{
  int		select;
  int		where;
  int		suppr;
  unsigned char	arg;
  struct s_line	*next;
  struct s_line	*prev;
}		t_line;

struct		s_tcaps
{
  char		*buff;
  int		(*function)(t_link *);
  t_tcaps	*nxt;
};

struct		s_link
{
  int		exit_status;
  int		exit_code;
  char		*histo_path;
  t_lex		*lex;
  t_trees	*trees;
  t_alias	*alias;
  t_local	*local;
  t_histo	*histo;
  t_built	*built;
  t_env		*env;
  t_term	term;
  t_line	*line;
  t_line	*sauv_line;
  t_tcaps	*tcaps;
  int		term_caps;
};

t_lex		*line_lexer(char *);
t_lex		*get_first_priority(t_lex *);
t_lex		*get_second_priority(t_lex *);
t_env		*get_environment(char **);
t_env		*get_line_env(char *, t_link *);
t_env		*get_var_pointer(t_link *, char *);
t_env		*env_var_in_list(t_env *, char *, char *);
t_trees		*build_trees(t_lex *);
int		do_change(char *);
int		exec(t_trees *, t_link *);
int		exec_cmd_type(t_node *, t_link *);
int		exec_cmd_and(t_node *, t_link *);
int		exec_cmd_or(t_node *, t_link *);
int		exec_one_cmd(t_node *, t_link *);
int		check_the_quote_place(char *, int);
int		take_my_bashrc(t_link *, char *);
int		is_an_egal(char *);
int		is_two_quotes(char *);
int		aff_history(t_histo *);
int		if_poss_history(t_histo *, char *);
int		max_histo(t_histo *);
int		mode_passif(t_link *, char **, char **);
int		get_command_line(t_link *, char *, int);
int		my_printf(const char *, ...);
int		get_int_history(t_histo *);
int		epur_commands(t_lex *);
int		check_line_syntax(t_lex *);
int		builtin_setenv(t_link *, char **);
int		my_tablen(char **);
int		exec_cmd_pipe(t_node *, t_link *);
int		redir_right(char ***);
int		redir_left(char ***);
int		check_redir_right(char *);
int		get_type_redir(char *);
int		show_prompt(t_link *);
int		term_init(t_link *, char **);
int		term_mode(t_link *);
int		is_exec(char *);
int		is_separator(char);
int		my_count_printable(char *);
int		get_separator_type(char *);
int		compare_with_grammar(t_lex *);
int		contain(char *, char);
int		lexeme_is_word(t_lex **, char *, char *, int *);
int		lexeme_is_separator(t_lex **, char *, char *, int *);
int		change_selected_left(t_link *);
int		change_selected_right(t_link *);
int		finish_term(t_link *);
int		term_auto_completion(t_link *);
int		key_delete(t_link *);
int		key_clean(t_link *);
int		key_enterr(t_link *);
int		key_arrow_up(t_link *);
int		key_arrow_down(t_link *);
int		key_tab(t_link *);
int		key_other(t_link *, unsigned char *);
int		is_redir(char *);
int		local_var(t_link *, char **);
int		syntax_is_right(char *);
int		check_return(int);
int		exec_son(t_node *, t_link *);
int		get_next_redir_right(char **, int);
int		my_putchar_int(int);
char		*check_quote(char *);
char		*get_pwd(void);
char		*compare_command_histo(char *, t_histo *);
char		*get_good_excla(char *);
char		*get_var_value(t_link *, char *);
char		*get_full_command(t_link *, char *);
char		*exec_exclamation(char *, t_histo *);
char		*delete_excla(char *, int);
char		*back_up_histo(t_histo *, int);
char		*get_int_command(t_histo *, int);
char		*my_put_nbr_str(int);
char		*envir(char **);
char		*concat_replace(char *, char);
char		*convert_char_to_str(char);
char		*get_last_histo(t_histo *);
char		*check_in_env_var(t_link *, char *);
char		*concat_lexeme(t_lex *);
char		*concat_tab(char **);
char		*replace_all(t_link *, char *, int *);
char		*check_in_alias(t_alias *, char *);
char		*pre_lexer(t_link *, char *, int);
char		*up_histo(t_link *);
char		*down_histo(t_link *);
char		*glob_exec(char *);
char		*convert_list_to_str(t_line *);
char		*get_before_sla(char *);
char		*get_local_value(t_link *, char *);
char		**convert_environment(t_env *);
char		**convert_environment(t_env *);
char		**replace_cmd(char **, t_link *);
char		**remove_cmd(char **);
char		**edit_command(t_link *, char *);
char		**my_explode_cote(char *, char);
char		**remove_all_quote(char **);
t_node		*build_node(t_lex *, t_node *);
t_node		*create_node_by_lex(t_lex *);
t_alias		*command_start_by_alias(t_alias *, char *);
t_local		*what_is_it(t_local *, char *);
t_local		*get_local_pointer(t_link *, char *);
t_built		*is_built(char *, t_link *);
t_built		*init_builtins();
t_histo		*delete_first(t_histo *);
t_histo		*add_histo(t_histo *, char *, int);
t_histo		*get_hist(t_link *, char *, int);
t_histo		*free_histo(t_histo *);
t_histo		*recup_history(t_histo *);
t_histo		*reset_histo(t_link *);
t_excl		*params_excla(t_excl *, char *);
t_excl		*replace_excla(t_histo *, char *);
t_excl		*free_list(t_excl *);
t_excl		*add_params_in_excl(t_excl *, char *, t_histo *);
t_line		*put_in_list(t_line *, char);
t_line		*get_selected(t_line *);
t_line		*delete_char_line(t_line *);
t_line		*convert_str_to_list(char *);
void		write_histo(t_link *);
void		replace_lexeme(t_link *, t_lex *, int *);
void		my_clean();
void		del_one();
void		move_right(t_link *);
void		move_left(t_link *);
void		bip();
void		move_cur_left();
void		sauv_cur();
void		my_delete_line();
void		my_clear();
void		my_show_list(t_line *, t_link *);
void		display_prompt(t_link *);
int		key_ctrl_a(t_link *);
int		key_ctrl_u(t_link *);
int		key_ctrl_c(t_link *);
int		key_ctrl_d(t_link *);
int		my_atoi(char *);
int		key_all(t_link *, unsigned char *);
void		free_env(t_env *);
void		free_alias(t_alias *);
void		free_local(t_local *);

#endif /* !PARSER_H_ */
