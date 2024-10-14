/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:53:19 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 23:16:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_fork() :
*	Create a fork and store the child process id in { process_id }.
*	(i) : See ft_perror() for error on failure.
*/
t_pid	ft_fork(t_pid *process_id)
{
	*(process_id) = fork();
	return (*(process_id));
}
