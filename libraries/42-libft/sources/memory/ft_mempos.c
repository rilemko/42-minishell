/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:45:12 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:37:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mempos(const void *pointer, int c, size_t size)
{
	const unsigned char		*str;
	unsigned char			character;
	unsigned int			index;

	str = (const unsigned char *) pointer;
	character = (unsigned char) c;
	index = 0;
	while (size--)
		if (str[index++] == character)
			return (index - 1);
	return (-1);
}
