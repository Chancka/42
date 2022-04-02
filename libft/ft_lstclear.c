/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:37:56 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 14:48:02 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ini;

	if (!*lst)
		return ;
	while (*lst)
	{
		ini = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ini;
	}
	*lst = 0;
}
