/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:38:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:42:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(long number)
{
	unsigned int	nbrlen;

	nbrlen = 0;
	while (number / 10)
	{
		number /= 10;
		nbrlen++;
	}
	return (++nbrlen);
}
