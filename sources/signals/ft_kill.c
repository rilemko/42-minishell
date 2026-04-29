/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/13 23:38:18 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_kill() :
*	Send the signal { signal } to the process referred to by { process_id }.
*	(i) : See ft_perror() for error on failure.
*/
t_rt	ft_kill(pid_t process_id, int signal)
{
	if (process_id != FAILURE)
		if (kill(process_id, signal) != FAILURE)
			return (SUCCESS);
	return (FAILURE);
}
