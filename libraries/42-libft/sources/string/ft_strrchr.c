/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:15:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:49:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	char	*pointer;

	pointer = ft_strchr(string, character);
	if (pointer)
		while (ft_strchr(pointer + 1, character)
			&& ft_strlen(pointer) > 0)
			pointer = ft_strchr(pointer + 1, character);
	return (pointer);
}
