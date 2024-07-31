/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:42:05 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:41:33 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int number)
{
	char			buffer[12];
	unsigned int	nbrlen;
	unsigned int	index;

	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_bzero(buffer, 12);
	nbrlen = ft_nbrlen(number);
	if (number < 0)
	{
		ft_memset(&buffer[nbrlen], '-', 1);
		number = -number;
	}
	index = 0;
	while (index < nbrlen)
	{
		ft_memset(&buffer[index++], (number % 10) + '0', 1);
		number /= 10;
	}
	return (ft_strdup(ft_strrev(buffer)));
}
