/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prs_reading_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:56:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 00:27:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_lne *lne, t_cmd *cmd, t_bool cut);

/*
*	ft_prs_reading_doc() :
*
*/
void	ft_prs_reading_doc(t_lne *lne, t_bool cut)
{
	t_lst	*lst;
	t_cmd	*cmd;

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
		if (lne->read_heredoc == FALSE)
		{
			lne->read_heredoc = TRUE;
			ft_lstclear(&cmd->tpl.heredoc, ft_free);
		}
		ft_process(lne, cmd, cut);
	}
}

static void	ft_process(t_lne *lne, t_cmd *cmd, t_bool cut)
{
	char	delimiter[MAX_PATH_SIZE];
	char	*line;
	int		index;

	(void) cut;
	index = 0;
	ft_bzero(delimiter, MAX_PATH_SIZE);
	line = ft_strtrim(lne->seg.rdr.arg.content, "\n");
	while (cmd->rio.pathname_i[index] && cmd->rio.pathname_i[index] != '\25')
		ft_chrcat(delimiter, cmd->rio.pathname_i[index++], MAX_PATH_SIZE);
	if (ft_strcmp(line, delimiter) == 0)
	{
		lne->heredoc += -1;
		cmd->heredoc_count += -1;
		lne->read_heredoc = FALSE;
		ft_memmove(cmd->rio.pathname_i, &cmd->rio.pathname_i[index + 1],
			ft_strlen(cmd->rio.pathname_i) - index);
	}
	else
		ft_arg_add(&cmd->tpl.heredoc, &lne->seg.rdr.arg);
	ft_free((void *) line);
}
