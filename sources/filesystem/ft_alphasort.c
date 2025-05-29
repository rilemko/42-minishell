/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphasort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:33:37 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 13:35:33 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_alphasort() :
*	
*/
int	ft_alphasort(void *ptr1, void *ptr2)
{
	return (ft_strcmp((const char *) ptr1, (const char *) ptr2));
}
