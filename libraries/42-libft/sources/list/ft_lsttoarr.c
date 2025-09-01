/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:31:28 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/17 23:51:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lsttoarr(t_lst *lst)
{
	int		index;
	char	**array;

	index = 0;
	array = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	while (lst)
	{
		array[index++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	array[index] = NULL;
	return (array);
}
