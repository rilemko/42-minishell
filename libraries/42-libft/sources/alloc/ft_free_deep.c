/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_deep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:16:57 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:22:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_deep(void **pointer)
{
	int	index;

	if (pointer != NULL)
	{
		index = -1;
		while (pointer[++index])
			ft_free(pointer[index]);
		ft_free(pointer);
	}
}
