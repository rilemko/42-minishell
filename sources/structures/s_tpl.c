/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tpl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:17:08 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/07 21:05:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_tpl_clear(t_tpl *tpl)
{
	ft_lstclear(&tpl->argument, ft_free);
	ft_lstclear(&tpl->fullname, ft_free);
	ft_lstclear(&tpl->options, ft_free);
	ft_lstclear(&tpl->heredoc, ft_free);
	ft_lstclear(&tpl->pathname_file_i, ft_free);
	ft_lstclear(&tpl->pathname_file_o, ft_free);
	ft_lstclear(&tpl->variable, ft_free);
}

void	st_tpl_initialize(t_tpl *tpl)
{
	tpl->argument = NULL;
	tpl->fullname = NULL;
	tpl->heredoc = NULL;
	tpl->options = NULL;
	tpl->pathname_file_i = NULL;
	tpl->pathname_file_o = NULL;
	tpl->variable = NULL;
}
