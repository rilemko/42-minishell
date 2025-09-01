/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:51:13 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:43:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chrcat(char *dst, char character, size_t dstsize)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize > dstlen + 1)
	{
		ft_memset(dst + dstlen, character, 1);
		ft_bzero(dst + dstlen + 1, 1);
	}
	return (dstsize + 1);
}
