/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:06:35 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/24 15:56:22 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isascii(unsigned int c);

int	ft_isprint(unsigned int c);

int	ft_strlen(char *str);

void	*ft_memset(void *p, int v, size_t len);

void	ft_bzero(void *s, size_t len);

void	*ft_memcpy(void *dest, const void *src, size_t len);

unsigned int	ft_strlcat(char *dest, const char *src, size_t size);

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);

int	ft_toupper(int c);

int	ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

#endif
