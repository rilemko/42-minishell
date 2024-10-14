/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_no_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:09:50 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/20 09:04:59 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_export_alphasort(void *ptr1, void *ptr2);

void	ft_export_env(t_cmd *cmd, char **env_arg)
{
	int	i;
	int	size;
	int	*tab;

	i = 0;
	size = ft_arraysize((void **) env_arg);
	tab = malloc(sizeof(int) * size);
	while (i != size)
	{
		tab[i] = i;
		i++;
	}
	ft_qsort((void **) env_arg, ft_export_alphasort, size);
	i = 0;
	while (i != size)
	{
		ft_write(STDOUT_FILENO, "declare -x ");
		ft_display_env(env_arg[tab[i]]);
		i++;
	}
	free(tab);
	cmd->builtin_status = TRUE;
}

static int	ft_export_alphasort(void *ptr1, void *ptr2)
{
	return (ft_strcmp((const char *) ptr1, (const char *) ptr2));
}
