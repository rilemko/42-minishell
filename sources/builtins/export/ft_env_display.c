/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:11:58 by vpolojie          #+#    #+#             */
/*   Updated: 2023/04/18 16:10:15 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_display_env(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
	if (str[i] == '=')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
		write(STDOUT_FILENO, "\"", 1);
		while (str[i] != '\0')
		{
			write(STDOUT_FILENO, &str[i], 1);
			i++;
		}
		write(STDOUT_FILENO, "\"", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
