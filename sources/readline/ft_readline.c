/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:38:20 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 14:39:31 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	ft_readline() :
*	Displays a prompt { prompt } then reads a line on STDIN_FILENO with
*	the "readline" library. Write the read content to { buffer }. Make sure
*	{ buffer } is long enough.
*	(i): The "readline" library integrates history management.
*/
t_rt	ft_readline(const char *prompt, char *buffer)
{
	char	*content;
	size_t	length;

	content = readline(prompt);
	if (content != NULL)
	{
		length = ft_strlen(content);
		if (buffer != NULL && length > 0)
			ft_strlcpy(buffer, content, length + 1);
		ft_free((void *) content);
		return (SUCCESS);
	}
	return (FAILURE);
}

/*
*	ft_readline_nl() :
*	Abort reading. Go to the next line, display the prompt on the new line
*	and wait for input. The line content can be prefilled with { content }.
*/
void	ft_readline_nl(const char *content)
{
	ft_write(STDOUT_FILENO, "\n");
	ft_readline_sl(content);
}

/*
*	ft_readline_sl() :
*	Abort reading, erase the current line. Redisplay the prompt and wait for
*	input. The line content can be prefilled with { content }.
*/
void	ft_readline_sl(const char *content)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	ft_write(STDOUT_FILENO, content);
}
