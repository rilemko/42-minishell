/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cfg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:49:07 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/22 18:44:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_cfg_creation(t_cfg *cfg);

void	st_cfg_clear(t_cfg *cfg)
{
	st_rdl_clear(&cfg->rdl);
	ft_lstclear(&cfg->tokens, ft_free);
}

void	st_cfg_initialize(t_cfg *cfg)
{
	st_rdl_initialize(&cfg->rdl);
	cfg->builtins = ";echo;cd;pwd;export;unset;env;exit;";
	cfg->file_history = "storage/.history";
	cfg->tokens = NULL;
	st_cfg_creation(cfg);
}

static void	st_cfg_creation(t_cfg *cfg)
{
	ft_tkn_add(&cfg->tokens, TOKEN_000, &ft_prs_process_000, 1, "newline");
	ft_tkn_add(&cfg->tokens, TOKEN_009, &ft_prs_process_009, 1, "tabulation");
	ft_tkn_add(&cfg->tokens, TOKEN_012, &ft_prs_process_012, 1, "newline");
	ft_tkn_add(&cfg->tokens, TOKEN_032, &ft_prs_process_032, 1, " ");
	ft_tkn_add(&cfg->tokens, TOKEN_034, &ft_prs_process_034, 1, "\'");
	ft_tkn_add(&cfg->tokens, TOKEN_035, &ft_prs_process_035, 1, "#");
	ft_tkn_add(&cfg->tokens, TOKEN_036, &ft_prs_process_036, 1, "$");
	ft_tkn_add(&cfg->tokens, TOKEN_038, &ft_prs_process_038, 2, "&");
	ft_tkn_add(&cfg->tokens, TOKEN_039, &ft_prs_process_039, 1, "\"");
	ft_tkn_add(&cfg->tokens, TOKEN_040, &ft_prs_process_040, 1, "(");
	ft_tkn_add(&cfg->tokens, TOKEN_041, &ft_prs_process_041, 1, ")");
	ft_tkn_add(&cfg->tokens, TOKEN_042, &ft_prs_process_042, 1, "*");
	ft_tkn_add(&cfg->tokens, TOKEN_045, &ft_prs_process_045, 1, "-");
	ft_tkn_add(&cfg->tokens, TOKEN_059, &ft_prs_process_059, 2, ";");
	ft_tkn_add(&cfg->tokens, TOKEN_060, &ft_prs_process_060, 3, "<");
	ft_tkn_add(&cfg->tokens, TOKEN_061, &ft_prs_process_061, 0, "=");
	ft_tkn_add(&cfg->tokens, TOKEN_062, &ft_prs_process_062, 2, ">");
	ft_tkn_add(&cfg->tokens, TOKEN_124, &ft_prs_process_124, 2, "|");
	ft_tkn_add(&cfg->tokens, TOKEN_176, &ft_prs_process_176, 1, "~");
}
