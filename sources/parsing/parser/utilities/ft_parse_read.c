/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:19:29 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/17 18:59:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_process(t_lne *lne, t_bool cut);

/*
*	ft_parse_read() :
*
*/

void	ft_parse_read(t_lne *lne, t_bool cut)
{
	if (lne->seg.rdr.is_started == TRUE
		&& ft_strlen(lne->seg.rdr.arg.content) > 0)
	{
		ft_process(lne, cut);
		if (lne->is_validate == TRUE)
			st_arg_clear(&lne->seg.rdr.arg);
	}
}

static void	ft_process(t_lne *lne, t_bool cut)
{
	if (lne->seg.rdr.read_error == TRUE)
		return (ft_prs_reading_err(lne, cut));
	if (lne->seg.rdr.read_comment == TRUE)
		return (ft_prs_reading_cmt(lne, cut));
	if (lne->seg.rdr.read_herestr == TRUE)
		return (ft_prs_reading_str(lne, cut));
	if (lne->seg.rdr.read_delimiter == TRUE)
		return (ft_prs_reading_del(lne, cut));
	if (lne->seg.rdr.read_heredoc == TRUE)
		return (ft_prs_reading_doc(lne, cut));
	if (lne->seg.rdr.read_redirection_i == TRUE)
		return (ft_prs_reading_rfi(lne, cut));
	if (lne->seg.rdr.read_redirection_o == TRUE)
		return (ft_prs_reading_rfo(lne, cut));
	if (lne->seg.rdr.read_options == TRUE)
		return (ft_prs_reading_opt(lne, cut));
	if (lne->seg.rdr.read_variable == TRUE)
		return (ft_prs_reading_var(lne, cut));
	if (lne->seg.rdr.read_command == TRUE)
		return (ft_prs_reading_cmd(lne, cut));
	ft_prs_reading_arg(lne, cut);
}
