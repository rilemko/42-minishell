/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:13:08 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/07 22:12:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_history_clear() :
*	Cleans the history of "readline" library. If { file_history } is specified
*	and targets an existing, writable file, empty the file.
*/
void	ft_history_clear(const char *file_history)
{
	rl_clear_history();
	if (file_history != NULL && ft_strlen(file_history) > 0)
		ft_fwrite(file_history, "", FALSE, TRUE);
}
