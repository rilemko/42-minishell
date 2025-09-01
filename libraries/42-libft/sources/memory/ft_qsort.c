/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:53:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/10 17:06:33 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(void **base, int (*compare)(void *, void *), int count)
{
	char	*temporary;
	int		index1;
	int		index2;

	if ((*compare) != NULL)
	{
		index1 = -1;
		while (base[++index1] && (count == -1 || index1 < count))
		{
			index2 = index1;
			while (base[++index2] && (count == -1 || index2 < count))
			{
				if ((*compare)(base[index1], base[index2]) > 0)
				{
					temporary = base[index1];
					base[index1] = base[index2];
					base[index2] = temporary;
				}
			}
		}
	}
}
