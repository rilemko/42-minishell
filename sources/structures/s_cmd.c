/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:08:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 15:58:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_cmd_clear(t_cmd *cmd)
{
	st_ope_clear(&cmd->ope);
	st_rio_clear(&cmd->rio);
	st_sub_clear(&cmd->sub);
	st_tpl_clear(&cmd->tpl);
}

void	st_cmd_initialize(t_cmd *cmd)
{
	ft_bzero(cmd->argument, MAX_LINE_SIZE);
	ft_bzero(cmd->basename, MAX_PATH_SIZE);
	ft_bzero(cmd->terminal, MAX_PATH_SIZE);
	ft_bzero(cmd->comments, MAX_LINE_SIZE);
	cmd->exists = FALSE;
	cmd->has_argument = FALSE;
	cmd->has_command = FALSE;
	cmd->has_comment = FALSE;
	cmd->has_heredoc = FALSE;
	cmd->has_herestr = FALSE;
	cmd->has_options = FALSE;
	cmd->has_variable = FALSE;
	cmd->heredoc_count = 0;
	ft_bzero(cmd->fullname, MAX_PATH_SIZE);
	ft_bzero(cmd->heredoc, MAX_LINE_SIZE);
	cmd->id = 0;
	cmd->is_builtins = FALSE;
	cmd->is_readable = FALSE;
	cmd->is_writable = FALSE;
	cmd->is_xcutable = FALSE;
	ft_bzero(cmd->options, MAX_OPTS_SIZE);
	st_ope_initialize(&cmd->ope);
	st_rio_initialize(&cmd->rio);
	st_sub_initialize(&cmd->sub);
	st_tpl_initialize(&cmd->tpl);
}
