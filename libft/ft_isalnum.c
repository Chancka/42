/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:38 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/23 10:09:51 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isdigit(int c);
int	ft_isalpha(int c);

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
