/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:35:01 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 17:05:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef struct s_app	t_app;

typedef int				t_bool;
typedef int				t_bytes;
typedef DIR				t_ds;
typedef int				t_fd;
typedef int				t_mod;
typedef int				t_pid;
typedef int				t_rt;

typedef struct s_arg
{
	char			content[MAX_LINE_SIZE];
	t_bool			in_quotes_double;
	t_bool			in_quotes_simple;
	t_bool			is_asterisk;
	t_bool			is_variable;
}	t_arg;

typedef struct s_rdl
{
	char			*color_default;
	char			*color_concate;
	char			*prompt_default;
	char			*prompt_concate;
}	t_rdl;

typedef struct s_cfg
{
	char			*builtins;
	char			*file_history;
	t_rdl			rdl;
	t_lst			*tokens;
}	t_cfg;

typedef struct s_fds
{
	t_fd			fileno_std_e;
	t_fd			fileno_std_i;
	t_fd			fileno_std_o;
}	t_fds;

typedef struct s_ope
{
	t_bool			exists;
	t_bool			has_operand_and;
	t_bool			has_operand_or;
}	t_ope;

typedef struct s_ptr
{
	size_t			current_depth;
	size_t			following;
	t_bool			in_comment;
	t_bool			in_quotes;
	t_bool			in_quotes_double;
	t_bool			in_quotes_simple;
}	t_ptr;

typedef struct s_rdr
{
	t_arg			arg;
	t_bool			is_started;
	t_bool			read_command;
	t_bool			read_comment;
	t_bool			read_delimiter;
	t_bool			read_error;
	t_bool			read_heredoc;
	t_bool			read_herestr;
	t_bool			read_options;
	t_bool			read_redirection_i;
	t_bool			read_redirection_o;
	t_bool			read_variable;
}	t_rdr;

typedef struct s_rio
{
	t_bool			exists;
	t_bool			file_append;
	t_bool			has_file_i;
	t_bool			has_file_o;
	t_bool			has_pipe_i;
	t_bool			has_pipe_o;
	char			pathname_i[MAX_PATH_SIZE];
	char			pathname_o[MAX_PATH_SIZE];
}	t_rio;

typedef struct s_sts
{
	t_bool			is_reading;
	t_bool			is_running;
	t_bool			is_xcuting;
}	t_sts;

typedef struct s_sub
{
	size_t			climb;
	size_t			depth;
	t_bool			is_ended;
	t_bool			is_start;
}	t_sub;

typedef struct s_tpl
{
	t_lst			*argument;
	t_lst			*fullname;
	t_lst			*heredoc;
	t_lst			*options;
	t_lst			*pathname_file_i;
	t_lst			*pathname_file_o;
	t_lst			*variable;
}	t_tpl;

typedef struct s_cmd
{
	char			argument[MAX_LINE_SIZE];
	char			basename[MAX_PATH_SIZE];
	t_bool			builtin_status;
	char			comments[MAX_LINE_SIZE];
	t_bool			exists;
	t_bool			has_argument;
	t_bool			has_command;
	t_bool			has_comment;
	t_bool			has_heredoc;
	t_bool			has_herestr;
	t_bool			has_options;
	t_bool			has_variable;
	size_t			heredoc_count;
	char			fullname[MAX_PATH_SIZE];
	char			heredoc[MAX_LINE_SIZE];
	int				id;
	t_bool			is_builtins;
	t_bool			is_readable;
	t_bool			is_writable;
	t_bool			is_xcutable;
	t_ope			ope;
	char			options[MAX_OPTS_SIZE];
	t_rio			rio;
	t_sub			sub;
	char			terminal[MAX_PATH_SIZE];
	t_tpl			tpl;
}	t_cmd;

typedef struct s_seg
{
	t_cmd			cmd;
	size_t			count;
	t_bool			is_complete;
	t_bool			is_started;
	t_rdr			rdr;
	t_bool			wait_separator;
}	t_seg;

typedef struct s_lne
{
	t_app			*app;
	char			buffer[MAX_LINE_SIZE];
	t_lst			*commands;
	size_t			count;
	size_t			heredoc;
	int				index;
	t_bool			is_complete;
	t_bool			is_validate;
	int				length;
	t_ptr			ptr;
	t_bool			read_heredoc;
	t_seg			seg;
	t_sts			sts;
}	t_lne;

typedef struct s_tio
{
	struct termios	termios_new;
	struct termios	termios_old;
	struct termios	termios_rtm;
}	t_tio;

typedef struct s_tkn
{
	char			display[MAX_TOKN_SIZE];
	void			(*process)(t_lne *, struct s_tkn *);
	size_t			repeat_max;
	char			token;
}	t_tkn;

typedef struct s_exe
{
	int				exit_status;
	t_fd			file_out;
	t_fd			in_fd;
	t_fd			pipe_doc[2];
	t_fd			pipe_sub[2];
	t_fd			pipe_tab[2];
	t_bool			skip;
	int				status;
}	t_exe;

typedef struct s_app
{
	int				argc;
	t_cfg			cfg;
	char			current_prompt[MAX_LINE_SIZE];
	char			dir_base[MAX_PATH_SIZE];
	char			dir_home[MAX_PATH_SIZE];
	char			dir_root[MAX_PATH_SIZE];
	t_lst			*env;
	t_exe			exe;
	t_fds			fds;
	char			*file_history;
	int				last_status;
	t_lne			lne;
	char			*name;
	char			*shell;
	size_t			shell_level;
	t_sts			sts;
	t_tio			tio;
	t_lst			*var;
}	t_app;
