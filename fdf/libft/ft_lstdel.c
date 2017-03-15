/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:34:58 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/07 17:15:45 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (!(*alst) || !del)
		return ;
	node = *alst;
	while (node)
	{
		del(node->content, node->content_size);
		free(node);
		node = node->next;
	}
	*alst = NULL;
}
