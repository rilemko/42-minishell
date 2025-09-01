/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:54:17 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 17:36:45 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *string)
{
	int			sign;
	long long	result;

	while (ft_isspace(*string))
		string++;
	sign = 1;
	if (*string == '-' || *string == '+')
		if (*string++ == '-')
			sign = -sign;
	result = 0;
	while (*string && ft_isdigit(*string))
		result = (result * 10) + (*string++ - '0');
	return (result * sign);
}
