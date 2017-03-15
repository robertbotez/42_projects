/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:26:10 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:48:49 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!dest || !src)
		return (0);
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}
