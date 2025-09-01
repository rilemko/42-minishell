/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strltrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:21:23 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/10 21:29:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strltrim(const char *string, const char *set)
{
	size_t	start;

	if (!string || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, string[start]))
		start++;
	return (ft_substr(string, start, ft_strlen(string)));
}
