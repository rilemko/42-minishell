/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:52:59 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:48:45 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	if (!size)
		return (0);
	while (*str1++ && *str2 && *(str1 - 1) == *str2 && size-- - 1)
		str2++;
	return (*((unsigned char *) str1 - 1) - *(unsigned char *) str2);
}
