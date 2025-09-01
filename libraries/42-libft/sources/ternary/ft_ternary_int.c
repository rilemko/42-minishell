/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:15:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/17 22:55:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	ft_ternary_int() :
*	Implements ternary operators. If { condition } is true, { then } returns,
*	otherwise { otherwise } returns.
*/
int	ft_ternary_int(int condition, int then, int otherwise)
{
	if (condition)
		return (then);
	return (otherwise);
}
