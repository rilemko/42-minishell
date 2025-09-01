/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:35:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/15 11:40:43 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcnt(const char *string, char separator)
{
	int	count;

	count = 0;
	while (*string)
	{
		if (*string != separator && (*(string + 1)
				== separator || !*(string + 1)))
			count++;
		string++;
	}
	return (count);
}
