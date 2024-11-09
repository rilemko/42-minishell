/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:58:50 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/21 23:36:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_infile(t_app *app, t_exe *exec, char *str)
{
	exec->in_fd = open(str, O_RDONLY);
	if (exec->in_fd == -1)
	{
		ft_perror(app->name, "", str, "");
		ft_exit(app, 1, "");
	}
	dup2(exec->in_fd, STDIN_FILENO);
}

void	ft_change_infile(t_app *app, t_exe *exec, t_cmd *cmd)
{
	int		i;
	char	**in_files;

	i = 0;
	in_files = ft_split(cmd->rio.pathname_i, '\25');
	while (in_files[i] != 0)
	{
		if (in_files[i][0] == TOKEN_036)
		{
			ft_perror(app->name, "", in_files[i], "ambiguous redirect");
			ft_free_deep((void **) in_files);
			ft_exit(app, 1, "");
		}
		if (ft_exists(in_files[i], TRUE, FALSE) == FALSE)
		{
			ft_perror(app->name, "", in_files[i], "");
			ft_free_deep((void **) in_files);
			ft_exit(app, 1, "");
		}
		i++;
	}
	ft_open_infile(app, exec, in_files[i - 1]);
	ft_free_deep((void **) in_files);
}
