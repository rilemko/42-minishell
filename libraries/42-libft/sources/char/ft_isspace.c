/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:56:36 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:28:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isspace(int character)
{
	if (character == '\t' || character == '\n' || character == '\v'
		|| character == '\f' || character == '\r' || character == ' ')
		return (TRUE);
	return (FALSE);
}
