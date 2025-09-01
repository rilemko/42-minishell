/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:05:24 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:36:30 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	index;

	index = 0;
	if (src < dst)
		while (len--)
			ft_memcpy(dst + len, src + len, 1);
	else if (src > dst)
	{
		while (len--)
		{
			ft_memcpy(dst + index, src + index, 1);
			index++;
		}
	}
	return (dst);
}
