/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:27:01 by mconreau          #+#    #+#             */
/*   Updated: 2022/04/01 20:11:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	if (dstsize > dstlen)
	{
		srclen = ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
		return (dstlen + srclen);
	}
	return (dstsize + ft_strlen(src));
}
