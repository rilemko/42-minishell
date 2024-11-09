/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:29:25 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:27:30 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isalpha(int character)
{
	if (ft_islower(character) || ft_isupper(character))
		return (TRUE);
	return (FALSE);
}
