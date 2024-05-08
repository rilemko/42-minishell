/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:05:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/23 15:36:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_lne *lne);

/*
*	ft_abort_doc() :
*
*/
t_rt	ft_abort_doc(t_app *app, t_lne *lne)
{
	ft_parse_read(lne, TRUE);
	ft_process(lne);
	ft_perror(app->name, "warning", "",
		"here-document delimited by end-of-file");
	lne->heredoc += -1;
	if (lne->heredoc == 0)
		return (SUCCESS);
	return (FAILURE);
}

static void	ft_process(t_lne *lne)
{
	t_lst	*lst;
	t_cmd	*cmd;
	size_t	size;

	lst = lne->commands;
	while (lst)
	{
		cmd = ft_cmd_get(&lst, 0);
		if (cmd->has_heredoc == TRUE && cmd->heredoc_count > 0)
			break ;
		lst = lst->next;
	}
	if (lst != NULL && cmd != NULL)
	{
		cmd->heredoc_count += -1;
		lne->read_heredoc = FALSE;
		size = ft_lstsize(cmd->tpl.heredoc);
		if (size > 0)
			ft_chrcat(ft_arg_get(&cmd->tpl.heredoc, size - 1)->content,
				TOKEN_012, MAX_LINE_SIZE);
	}
}
