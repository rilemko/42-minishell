/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_asterisk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:21:58 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:31:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(const char *pattern, char *buffer, t_bool *is_pattern);

/*
*	ft_interpret_asterisk() :
*	
*/
void	ft_interpret_asterisk(t_arg *arg, char *buffer)
{
	char	pattern[MAX_LINE_SIZE];
	t_bool	is_pattern;
	int		index;

	index = -1;
	is_pattern = FALSE;
	ft_bzero(pattern, MAX_LINE_SIZE);
	while (arg->content[++index])
	{
		if (arg->content[index] == TOKEN_012
			|| arg->content[index] == TOKEN_032)
		{
			ft_process(pattern, buffer, &is_pattern);
			ft_bzero(pattern, MAX_LINE_SIZE);
			ft_chrcat(buffer, arg->content[index], MAX_LINE_SIZE);
		}
		else
		{
			ft_chrcat(pattern, arg->content[index], MAX_LINE_SIZE);
			if (arg->content[index] == TOKEN_042)
				is_pattern = TRUE;
		}
	}
	ft_process(pattern, buffer, &is_pattern);
}

static void	ft_process(const char *pattern, char *buffer, t_bool *is_pattern)
{
	char	**matches;
	int		index;

	if (*(is_pattern) == TRUE && ft_strlen(pattern) > 0)
	{
		if (ft_glob(pattern, &matches) > 0)
		{
			index = -1;
			while (matches[++index])
			{
				ft_strlcat(buffer, matches[index], MAX_LINE_SIZE);
				if (matches[index + 1] != NULL)
					ft_chrcat(buffer, TOKEN_032, MAX_LINE_SIZE);
			}
			ft_free_deep((void **) matches);
		}
		else
			ft_strlcat(buffer, pattern, MAX_LINE_SIZE);
		*(is_pattern) = FALSE;
	}
	else
		ft_strlcat(buffer, pattern, MAX_LINE_SIZE);
}
