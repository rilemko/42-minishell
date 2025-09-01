/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:42:07 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:45:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *string, char separator)
{
	char			**memory;
	char			buffer[200000];
	unsigned int	index;

	if (!string)
		return (NULL);
	memory = ft_calloc(ft_strcnt(string, separator) + 1, sizeof(char *));
	if (!memory)
		return (NULL);
	ft_bzero(buffer, 200000);
	index = 0;
	while (*string)
	{
		if (*string++ != separator)
			ft_chrcat(buffer, *(string - 1), 200000);
		if (ft_strlen(buffer) > 0 && (*string == separator || !*string))
		{
			memory[index++] = ft_strdup(buffer);
			ft_bzero(buffer, 200000);
		}
	}
	memory[index] = NULL;
	return (memory);
}
