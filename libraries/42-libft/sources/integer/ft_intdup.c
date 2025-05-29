/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:40:29 by mconreau          #+#    #+#             */
/*   Updated: 2022/11/28 16:17:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int i)
{
	int	*memory;

	memory = (int *) ft_calloc(1, sizeof(int));
	if (!memory)
		return (NULL);
	ft_bzero(memory, sizeof(int));
	*((int *) memory) = i;
	return (memory);
}
