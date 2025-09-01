/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:36:25 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:31:53 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *pointer, int c, size_t size)
{
	int	pos;

	pos = ft_mempos(pointer, c, size);
	if (pos < 0)
		return ((NULL));
	return ((void *) pointer + pos);
}
