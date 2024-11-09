/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:26:30 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/10 23:18:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrtrim(const char *string, const char *set)
{
	size_t	stop;

	if (!string || !set)
		return (NULL);
	stop = ft_strlen(string);
	while (ft_strchr(set, string[stop]))
		stop--;
	return (ft_substr(string, 0, stop + 1));
}
