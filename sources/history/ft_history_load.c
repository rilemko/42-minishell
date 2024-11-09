/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:16:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/10 16:26:25 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_history_load() :
*	Read the contents of the file referred to by { file_history } and add the
*	lines as entries in the history of "readline" library. If { clear } is
*	TRUE, clear the current history before proceeding.
*/
void	ft_history_load(const char *file_history, t_bool clear)
{
	char	*content;
	char	**array;
	int		index;

	if (clear == TRUE)
		ft_history_clear("");
	if (file_history != NULL && ft_strlen(file_history) > 0
		&& ft_is_readable(file_history, TRUE, TRUE) == TRUE)
	{
		content = ft_calloc(ft_size(file_history) + 1, sizeof(char));
		if (content != NULL && ft_fread(file_history, content) == SUCCESS)
		{
			array = ft_split(content, '\n');
			if (array != NULL)
			{
				index = -1;
				while (array[++index])
					ft_history_add(array[index], "");
				ft_free_deep((void **) array);
			}
			ft_free((void *) content);
		}
	}
}
