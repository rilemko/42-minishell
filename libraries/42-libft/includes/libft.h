/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:17:23 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/25 17:04:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "_includes.h"
#include "_definitions.h"

long long	ft_atoi(const char *string);
size_t		ft_arraysize(void **array);
void		ft_bzero(void *pointer, size_t size);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_chrcat(char *dst, char character, size_t dstsize);
void		ft_free(void *pointer);
void		ft_free_deep(void **pointer);
int			*ft_intdup(int i);
t_bool		ft_isalnum(int character);
t_bool		ft_isalpha(int character);
t_bool		ft_isascii(int character);
t_bool		ft_isdigit(int character);
t_bool		ft_islower(int character);
t_bool		ft_isprint(int character);
t_bool		ft_isspace(int character);
t_bool		ft_isupper(int character);
char		*ft_itoa(int number);
void		ft_lstadd_back(t_lst **lst, t_lst *new);
void		ft_lstadd_front(t_lst **lst, t_lst *new);
void		ft_lstclear(t_lst **lst, void (*del)(void *));
void		ft_lstdelone(t_lst *lst, void (*del)(void *));
t_lst		*ft_lstfromarr(t_lst **lst, char **array);
t_lst		*ft_lstget(t_lst *lst, size_t index);
void		*ft_lstgetcontent(t_lst *lst, size_t index);
int			ft_lstgetindex(t_lst *lst, void *content, size_t size);
t_lst		*ft_lstlast(t_lst *lst);
size_t		ft_lstsize(t_lst *lst);
char		**ft_lsttoarr(t_lst *lst);
void		ft_lstunlist(t_lst **lst, size_t index, void (*del)(void *));
t_lst		*ft_lstnew(void *content);
void		*ft_memchr(const void *pointer, int c, size_t size);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t size);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_mempos(const void *pointer, int c, size_t size);
void		*ft_memrev(void *pointer, size_t size);
void		*ft_memset(void *pointer, int c, size_t len);
size_t		ft_nbrlen(long number);
void		ft_qsort(void **base, int (*compare)(void *, void *), int count);
char		**ft_split(char const *string, char separator);
char		*ft_strchr(const char *string, int character);
int			ft_strcmp(const char *string1, const char *string2);
size_t		ft_strcnt(const char *string, char separator);
char		*ft_strdup(const char *string);
char		*ft_strjoin(char const *str1, char const *str2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *string);
char		*ft_strltrim(const char *string, const char *set);
char		*ft_strmjoin(char const *str1, char const *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strpos(const char *string, int character);
char		*ft_strrchr(const char *string, int character);
char		*ft_strrev(char *string);
char		*ft_strrtrim(const char *string, const char *set);
char		*ft_strtrim(char const *string, char const *set);
char		*ft_substr(char const *string, unsigned int start, size_t len);
void		*ft_ternary(int condition, void *then, void *otherwise);
int			ft_ternary_int(int condition, int then, int otherwise);
char		ft_tolower(int character);
char		ft_toupper(int character);
char		*get_next_line(int fd);
