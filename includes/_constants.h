/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _constants.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:45:18 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 17:07:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define TOKEN_000					'\0'
#define TOKEN_009					'\t'
#define TOKEN_012					'\n'
#define TOKEN_032					' '
#define TOKEN_034					'\''
#define TOKEN_035					'#'
#define TOKEN_036					'$'
#define TOKEN_038					'&'
#define TOKEN_039					'\"'
#define TOKEN_040					'('
#define TOKEN_041					')'
#define TOKEN_042					'*'
#define TOKEN_045					'-'
#define TOKEN_058					':'
#define TOKEN_059					';'
#define TOKEN_060					'<'
#define TOKEN_061					'='
#define TOKEN_062					'>'
#define TOKEN_063					'?'
#define TOKEN_124					'|'
#define TOKEN_137					'_'
#define TOKEN_176					'~'

#define SIGNAL_MODE_DEFAULT			0
#define SIGNAL_MODE_CONCATE			1
#define SIGNAL_MODE_RUNTIME			2

#define MAX_EVAR_SIZE				32760
#define MAX_FILE_OPEN				1024
#define MAX_LINE_SIZE				262145
#define MAX_OPTS_SIZE				1024
#define MAX_PATH_SIZE				4097
#define MAX_TOKN_SIZE				1024

#define FALSE						0
#define TRUE						1
#define FAILURE			  	   		-1
#define SUCCESS						1

#define TERM_BCOLOR_BLU				"\001\e[1;34m\002"
#define TERM_BCOLOR_CYA				"\001\e[1;36m\002"
#define TERM_BCOLOR_GRN				"\001\e[1;32m\002"
#define TERM_BCOLOR_PUR				"\001\e[1;35m\002"
#define TERM_BCOLOR_RED				"\001\e[1;31m\002"
#define TERM_BCOLOR_WHT				"\001\e[1;37m\002"
#define TERM_BCOLOR_YEL				"\001\e[1;33m\002"
#define TERM_NCOLOR_BLU				"\001\e[0;34m\002"
#define TERM_NCOLOR_CYA				"\001\e[0;36m\002"
#define TERM_NCOLOR_GRN				"\001\e[0;32m\002"
#define TERM_NCOLOR_PUR				"\001\e[0;35m\002"
#define TERM_NCOLOR_RED				"\001\e[0;31m\002"
#define TERM_NCOLOR_WHT				"\001\e[0;37m\002"
#define TERM_NCOLOR_YEL				"\001\e[0;33m\002"

#define TERMINAL_CCLEAR				"\001\e[1;1H\e[2J\002"
#define TERMINAL_CRESET				"\001\e[0m\002"

#ifndef OXTABS
# define OXTABS						6144
#endif
