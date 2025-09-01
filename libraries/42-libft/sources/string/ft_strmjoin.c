/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:04:34 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/18 15:50:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmjoin(char const *str1, char const *str2)
{
	size_t	ttlsize;
	char	*memory;

	if (!str1 || !str2)
		return (NULL);
	ttlsize = ft_strlen(str1) + ft_strlen(str2) + 1;
	memory = ft_calloc(ttlsize, sizeof(char));
	if (!memory)
		return (NULL);
	ft_strlcpy(memory, str1, ttlsize);
	ft_strlcat(memory, str2, ttlsize);
	free((void *) str1);
	return (memory);
}
