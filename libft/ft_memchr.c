/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:30:30 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:48:35 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (0);
	p = (unsigned char*)s;
	while (n > 0)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
		n--;
	}
	return (0);
}
