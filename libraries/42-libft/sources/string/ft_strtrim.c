/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:26 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/10 21:29:43 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *string, const char *set)
{
	size_t	start;
	size_t	stop;

	if (!string || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, string[start]))
		start++;
	stop = ft_strlen(string);
	if (stop <= start)
		return (ft_strdup(""));
	while (ft_strchr(set, string[stop]))
		stop--;
	return (ft_substr(string, start, stop - start + 1));
}
