/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:58:05 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/09 17:27:59 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (ptr1 == NULL)
		return (-1);
	if (ptr2 == NULL)
		return (1);
	str1 = (unsigned char *) ptr1;
	str2 = (unsigned char *) ptr2;
	while (size--)
		if (*str1++ != *str2++)
			return (*(str1 - 1) - *(str2 - 1));
	return (0);
}
