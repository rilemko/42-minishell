/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:09:28 by mconreau          #+#    #+#             */
/*   Updated: 2023/04/24 13:46:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_rt	ft_glob_compare(const char *pattern, const char *content);
static t_rt	ft_glob_compare_next(const char *pattern, const char *content,
				t_bool has_wildcard);
static t_rt	ft_glob_filter(struct dirent *node);
static char	*ft_glob_process(char **matches, const char *pattern,
				const char *prefix, int *count);

/*
*	ft_glob() :
*	Writes in the array { matches } the list of entries in the filesystem 
*	matching the pattern { pattern }, sorted alphabetically.
*	(!) : This implementation of glob() function only supports wildcards in
*	the basename of the path. It processes for the current directory, any
*	absolute paths or all child relative paths of the current directory. The
*	keyword ".." is not supported to go back to the parent directory.
*	(!) : This function allocates memory in { matches }, which must be free.
*/
size_t	ft_glob(const char *pattern, char ***matches)
{
	char	dirname[MAX_PATH_SIZE];
	char	remains[MAX_PATH_SIZE];
	char	*buffer;
	int		count;

	count = 0;
	ft_dirname(pattern, dirname);
	if (pattern != NULL && ft_strlen(pattern) > 0
		&& ft_strpos(dirname, '*') == FAILURE)
	{
		ft_bzero(remains, MAX_PATH_SIZE);
		while (ft_strchr(pattern, '/') != NULL)
			ft_chrcat(remains, *pattern++, ft_strlen(remains) + 2);
		if (ft_scandir(dirname, matches,
				ft_ternary(pattern[0] != '.', &ft_glob_filter, NULL),
				&ft_alphasort) > 0)
		{
			buffer = ft_glob_process(*matches, pattern, remains, &count);
			ft_free_deep((void **) *matches);
			*(matches) = ft_split(buffer, ' ');
			ft_free((void *) buffer);
		}
	}
	return (count);
}

static char	*ft_glob_process(char **matches, const char *pattern,
	const char *prefix, int *count)
{
	char	*buffer;
	int		index;

	index = -1;
	buffer = ft_strdup("");
	while (matches[++index] && buffer != NULL)
	{
		if (ft_glob_compare(pattern, matches[index]) == FAILURE)
			continue ;
		buffer = ft_strmjoin(buffer, prefix);
		buffer = ft_strmjoin(ft_strmjoin(buffer, matches[index]), " ");
		*(count) += 1;
	}
	return (buffer);
}

static t_rt	ft_glob_compare(const char *pattern, const char *content)
{
	t_bool		has_wildcard;

	has_wildcard = FALSE;
	if (*pattern == '*')
	{
		has_wildcard = TRUE;
		while (*pattern == '*')
			if (*pattern++ == '\0')
				return (SUCCESS);
		while (*content != *pattern)
			if (*content++ == '\0')
				return (FAILURE);
	}
	return (ft_glob_compare_next(pattern, content, has_wildcard));
}

static	t_rt	ft_glob_compare_next(const char *pattern, const char *content,
	t_bool has_wildcard)
{
	char	*temporary;

	temporary = (char *) pattern;
	while (*content)
	{
		if (*pattern == '*')
			return (ft_glob_compare(pattern, content));
		if (*content != *pattern)
		{
			if (ft_strpos(content, temporary[0]) != FAILURE
				&& has_wildcard == TRUE)
				return (ft_glob_compare(temporary, ft_strchr(content,
							temporary[0])));
			return (FAILURE);
		}
		content++;
		pattern++;
	}
	while (*pattern != '\0')
		if (*pattern++ != '*')
			return (FAILURE);
	return (SUCCESS);
}

static	t_rt	ft_glob_filter(struct dirent *node)
{
	if (node->d_name[0] == '.')
		return (FAILURE);
	return (SUCCESS);
}
