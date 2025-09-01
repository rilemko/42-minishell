/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:34:38 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 10:43:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_end(t_cmd *current_cmd)
{
	printf("> OPE      ] %i | AND : %i | OR : %i\n",
		current_cmd->ope.exists, current_cmd->ope.has_operand_and,
		current_cmd->ope.has_operand_or);
	printf("> FILE I   ] %s [\n", current_cmd->rio.pathname_i);
	printf("> FILE O   ] %s [\n", current_cmd->rio.pathname_o);
	printf("> HEREDOC  ] %s [\n", current_cmd->heredoc);
	printf("> OPTIONS  ] %s [\n", current_cmd->options);
	printf("> COMMENTS ] %s [\n", current_cmd->comments);
}

void	debug(t_cmd *current_cmd)
{
	printf("# %02i =======================================\
====================================\n", current_cmd->id);
	printf("> COMMAND  ] ( e:%i b:%i r:%i w:%i x:%i ) : %s | %s [\n",
		current_cmd->exists, current_cmd->is_builtins,
		current_cmd->is_readable, current_cmd->is_writable,
		current_cmd->is_xcutable, current_cmd->basename,
		current_cmd->fullname);
	printf("> ARGUMENT ] %s [\n", current_cmd->argument);
	printf("> CONTENTS ] ARG : %i | CMD : %i | CMT : %i | DOC : %i | \
STR : %i | OPT : %i | VAR : %i\n",
		current_cmd->has_argument, current_cmd->has_command,
		current_cmd->has_comment, current_cmd->has_heredoc,
		current_cmd->has_herestr, current_cmd->has_options,
		current_cmd->has_variable);
	printf("> DEPTH    ] %li | START : %i | END : %i | CLIMB : %li [ \n",
		current_cmd->sub.depth,
		current_cmd->sub.is_start, current_cmd->sub.is_ended,
		current_cmd->sub.climb);
	printf("> RIO      ] %i | PI  : %i | PO : %i | FI : %i | FO : %i \
| APPEND : %i\n",
		current_cmd->rio.exists,
		current_cmd->rio.has_pipe_i,
		current_cmd->rio.has_pipe_o, current_cmd->rio.has_file_i,
		current_cmd->rio.has_file_o, current_cmd->rio.file_append);
	debug_end(current_cmd);
}
