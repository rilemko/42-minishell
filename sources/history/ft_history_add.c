/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:05:49 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/07 22:18:37 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_history_add() :
*	Add { content } to the history of "readline" library. If { file_history }
*	is specified and targets an existing, writable file, write { content }
*	inside for a persistent history.
*/
void	ft_history_add(const char *content, const char *file_history)
{
	char	*buffer;

	if (content != NULL && ft_strlen(content) > 0)
	{
		if (file_history != NULL && ft_strlen(file_history) > 0)
		{
			buffer = ft_strjoin(content, "\n");
			if (buffer != NULL)
			{
				ft_fwrite(file_history, buffer, TRUE, FALSE);
				ft_free((void *) buffer);
			}
		}
		add_history(content);
	}
}
