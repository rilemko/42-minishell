/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_normalize.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:44:15 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/21 12:29:49 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_interpret_normalize() :
*	
*/
void	ft_interpret_normalize(char *content)
{
	int	index;

	index = -1;
	while (content[++index])
	{
		if (content[index] == '\26')
			content[index] = TOKEN_032;
	}
}
