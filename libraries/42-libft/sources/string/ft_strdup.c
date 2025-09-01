/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:04:00 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:46:45 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	strsize;
	char	*memory;

	strsize = ft_strlen(string) + 1;
	memory = (char *) ft_calloc(strsize, sizeof(char));
	if (!memory)
		return (NULL);
	ft_bzero(memory, strsize);
	ft_strlcpy(memory, string, strsize);
	return (memory);
}
