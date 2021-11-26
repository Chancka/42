/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:06:35 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/26 11:55:13 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(unsigned int c);

int				ft_isprint(unsigned int c);

size_t			ft_strlen(const char *str);

void			*ft_memset(void *p, int v, size_t len);

void			ft_bzero(void *s, size_t len);

void			*ft_memcpy(void *dest, const void *src, size_t len);

void			*ft_memmove(void *dest, const void *src, size_t len);

unsigned int	ft_strlcat(char *dest, const char *src, size_t size);

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);

int				ft_toupper(int c);

int				ft_tolower(int c);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle, size_t len);

int				ft_atoi(const char *str);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdup(const char *s1);

#endif
