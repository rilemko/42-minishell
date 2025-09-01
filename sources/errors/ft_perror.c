/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:42:27 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/19 17:23:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_perror() :
*	Write error on STDERR_FILENO in the format 
*	"{ prefix }: { argument }: { message }\n". If { message } is not filled in,
*	the message will be the last error produced by the program.
*/
void	ft_perror(const char *name, const char *prefix, const char *argument,
	const char *message)
{
	char	*buffer;

	buffer = ft_strdup("");
	if (name != NULL && ft_strlen(name) > 0)
		buffer = ft_strmjoin(ft_strmjoin(buffer, name), ": ");
	if (prefix != NULL && ft_strlen(prefix) > 0)
		buffer = ft_strmjoin(ft_strmjoin(buffer, prefix), ": ");
	if (argument != NULL && ft_strlen(argument) > 0)
		buffer = ft_strmjoin(ft_strmjoin(buffer, argument), ": ");
	if (message != NULL && ft_strlen(message) > 0)
		buffer = ft_strmjoin(ft_strmjoin(buffer, message), "\n");
	else if (strerror(errno) != NULL && ft_strlen(strerror(errno)) > 0)
		buffer = ft_strmjoin(ft_strmjoin(buffer, strerror(errno)), "\n");
	ft_write(STDERR_FILENO, buffer);
	ft_free((void *) buffer);
}
