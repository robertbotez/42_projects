/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:36:38 by abenea            #+#    #+#             */
/*   Updated: 2017/01/07 14:14:29 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[len] != c && 0 <= len)
		len--;
	if (s[len] == (char)c)
		return ((char*)s + len);
	return (NULL);
}
