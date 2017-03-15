/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:17:00 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:48:42 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!s1 || !s2)
		return (0);
	if (n)
	{
		p1 = (unsigned char*)s1;
		p2 = (unsigned char*)s2;
		if (n == 0)
		{
			if (*p1 != *p2)
				return (*--p1 - *--p2);
		}
		while (n--)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
		}
	}
	return (0);
}
