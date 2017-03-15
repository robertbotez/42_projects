/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:29:16 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:48:30 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*a;
	const char	*b;

	if (!dest || !src)
		return (0);
	a = dest;
	b = src;
	while (n--)
	{
		if ((*a++ = *b++) == c)
			return (a);
	}
	return (0);
}
