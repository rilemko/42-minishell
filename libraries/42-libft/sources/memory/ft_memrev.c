/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:18:55 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:38:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrev(void *pointer, size_t size)
{
	size_t	index;
	char	buffer;

	size--;
	index = 0;
	while (index < size)
	{
		ft_memcpy(&buffer, pointer + index, 1);
		ft_memcpy(pointer + index++, pointer + size, 1);
		ft_memcpy(pointer + size--, &buffer, 1);
	}
	return ((void *) pointer);
}
