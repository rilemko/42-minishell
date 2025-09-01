/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:49:09 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/20 17:00:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_tio_creation(t_tio *tio);

void	st_tio_clear(t_tio *tio)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &tio->termios_old);
}

void	st_tio_initialize(t_tio *tio)
{
	tcgetattr(STDIN_FILENO, &tio->termios_old);
	ft_memcpy(&tio->termios_new, &tio->termios_old, sizeof(struct termios));
	ft_memcpy(&tio->termios_rtm, &tio->termios_old, sizeof(struct termios));
	st_tio_creation(tio);
}

static void	st_tio_creation(t_tio *tio)
{
	tio->termios_new.c_lflag &= ~(ECHOCTL);
	tio->termios_new.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &tio->termios_new);
}
