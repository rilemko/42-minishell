/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:59:26 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/21 23:37:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_outfile(t_app *app, t_exe *exec, t_cmd *cmd, char *str)
{
	if (cmd->rio.file_append == FALSE)
		exec->file_out = open(str,
				O_CREAT | O_RDWR | O_TRUNC, 0664);
	else
	{
		exec->file_out = open(str,
				O_CREAT | O_RDWR | O_APPEND, 0664);
	}
	if (exec->file_out == -1)
	{
		ft_perror(app->name, "", str, "");
		ft_exit(app, 1, "");
	}
}

void	ft_change_outfile(t_app *app, t_exe *exec, t_cmd *cmd)
{
	int		i;
	char	**out_files;

	i = 0;
	out_files = ft_split(cmd->rio.pathname_o, '\25');
	while (out_files[i] != 0)
	{
		if (out_files[i][0] == TOKEN_036)
		{
			ft_perror(app->name, "", out_files[i], "ambiguous redirect");
			ft_exit(app, 1, "");
		}
		ft_open_outfile(app, exec, cmd, out_files[i]);
		if (out_files[i + 1] != 0)
			close(exec->file_out);
		i++;
	}
	dup2(exec->file_out, STDOUT_FILENO);
	ft_free_deep((void **) out_files);
}
