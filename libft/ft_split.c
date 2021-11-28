/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:32:14 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/28 15:20:07 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		start;
	int		end;

	dest = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !dest)
		return (NULL);
	start = 0;
	i = 0;
	while (i < word_count(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		dest[i] = ft_substr(s, start, (end - start));
		start = end;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
