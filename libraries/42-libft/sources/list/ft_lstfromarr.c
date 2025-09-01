/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfromarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:27:09 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/15 11:41:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstfromarr(t_lst **lst, char **array)
{
	int		index;

	index = -1;
	while (array[++index])
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(array[index])));
	return (*lst);
}
