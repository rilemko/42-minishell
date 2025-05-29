/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:11:31 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/09 17:32:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *string1, const char *string2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) string1;
	str2 = (unsigned char *) string2;
	while (*str1++ && *str2 && *(str1 - 1) == *str2)
		str2++;
	return (*((unsigned char *) str1 - 1) - *(unsigned char *) str2);
}
