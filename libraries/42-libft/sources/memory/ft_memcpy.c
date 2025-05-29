/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:51:01 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/09 17:37:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char		*destination;
	const char	*source;

	destination = (char *) dst;
	source = (const char *) src;
	if (destination || source)
		while (size--)
			ft_memset(destination++, *source++, 1);
	return (dst);
}
