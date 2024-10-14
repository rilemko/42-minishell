/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:23:06 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:47:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	ttlsize;
	char	*memory;

	if (!str1 || !str2)
		return (NULL);
	ttlsize = ft_strlen(str1) + ft_strlen(str2) + 1;
	memory = (char *) ft_calloc(ttlsize, sizeof(char));
	if (!memory)
		return (NULL);
	ft_strlcpy(memory, str1, ttlsize);
	ft_strlcat(memory, str2, ttlsize);
	return (memory);
}
