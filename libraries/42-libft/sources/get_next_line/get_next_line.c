/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:08:11 by mconreau          #+#    #+#             */
/*   Updated: 2023/02/05 16:39:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *current, char *cache);
static int	ft_read(int fd, char *cache);
static char	*ft_return(char *current, char *cache, int clear);

char	*get_next_line(int fd)
{
	static char	cache[512][BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) == -1)
		return (NULL);
	line = malloc(0);
	ft_bzero(line, ft_strlen(line) + 1);
	while (1)
	{
		if (ft_strchr(cache[fd], '\n'))
			return (ft_get_line(line, cache[fd]));
		line = ft_get_line(line, cache[fd]);
		ft_read(fd, cache[fd]);
		if (ft_strlen(cache[fd]) == 0)
			break ;
	}
	if (ft_strlen(line))
		return (ft_return(line, cache[fd], 1));
	free(line);
	return (NULL);
}

static char	*ft_get_line(char *current, char *cache)
{
	char	*line;
	size_t	tsize;
	size_t	ssize;

	tsize = ft_strlen(cache);
	if (ft_strchr(cache, '\n'))
		tsize = ft_strpos(cache, '\n') + 1;
	tsize += ft_strlen(current) + 1;
	line = malloc(tsize * sizeof(char));
	ssize = ft_strlcpy(line, current, tsize);
	ft_strlcpy(&line[ssize], cache, tsize - ssize);
	if (ft_strchr(cache, '\n'))
		ft_strlcpy(cache, &cache[ft_strpos(cache, '\n') + 1],
			BUFFER_SIZE - ft_strpos(cache, '\n'));
	free(current);
	return (line);
}

static int	ft_read(int fd, char *cache)
{
	ft_bzero(&cache[read(fd, cache, BUFFER_SIZE)], 1);
	return (ft_strlen(cache));
}

static char	*ft_return(char *current, char *cache, int clear)
{
	if (clear > 0)
		ft_bzero(cache, ft_strlen(cache));
	return (current);
}
