/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rdr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:57:51 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/07 20:45:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_rdr_clear(t_rdr *rdr)
{
	st_arg_clear(&rdr->arg);
}

void	st_rdr_initialize(t_rdr *rdr)
{
	st_arg_initialize(&rdr->arg);
	rdr->is_started = FALSE;
	rdr->read_command = TRUE;
	rdr->read_comment = FALSE;
	rdr->read_delimiter = FALSE;
	rdr->read_error = FALSE;
	rdr->read_heredoc = FALSE;
	rdr->read_herestr = FALSE;
	rdr->read_options = FALSE;
	rdr->read_redirection_i = FALSE;
	rdr->read_redirection_o = FALSE;
	rdr->read_variable = FALSE;
}
