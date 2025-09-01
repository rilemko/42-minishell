/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:15:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/03/17 22:56:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	ft_ternary() :
*	Implements ternary operators. If { condition } is true, { then } returns,
*	otherwise { otherwise } returns.
*/
void	*ft_ternary(int condition, void *then, void *otherwise)
{
	if (condition)
		return (then);
	return (otherwise);
}
