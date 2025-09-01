/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:10:16 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/25 02:38:28 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	size_t	offset;
	char	*memory;

	if (!string)
		return (NULL);
	offset = ft_strlen(string);
	if (start > offset)
		return (ft_strdup(""));
	offset = offset - start;
	if (len > offset)
		len = offset;
	memory = ft_calloc(len + 1, sizeof(char));
	if (!memory)
		return (NULL);
	ft_memcpy(memory, &string[start], len);
	ft_bzero(&memory[len], 1);
	return (memory);
}
