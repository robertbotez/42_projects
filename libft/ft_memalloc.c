/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:31:31 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/07 18:41:12 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*str;

	if (!(str = malloc(sizeof(str) * size)))
		return (0);
	if (str)
		ft_bzero(str, size);
	return (str);
}
