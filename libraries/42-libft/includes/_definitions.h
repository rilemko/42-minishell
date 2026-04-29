/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _definitions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:18:55 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 17:04:41 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_constants.h"

typedef int			t_bool;
typedef int			t_fd;
typedef int			t_pid;
typedef int			t_rt;

typedef struct s_lst {
	void			*content;
	struct s_lst	*next;
}	t_lst;
