/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:35:21 by abenea            #+#    #+#             */
/*   Updated: 2017/01/07 19:23:16 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_count_words(char const *s, char c)
{
	int		words;

	while (*s && *s == c)
		s++;
	if (*s)
		words = 1;
	else
		words = 0;
	while (*s)
	{
		if (s[1] && s[1] != c && *s == c)
			++words;
		s++;
	}
	return (words);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*start;
	int		words;

	if (!s || !c)
		return (NULL);
	words = ft_count_words((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words((char *)s, c) + 1));
	start = (char *)s;
	if (!tab)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(tab++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		s++;
	}
	if (start != s)
		*(tab++) = ft_strsub(start, 0, s - start);
	*tab = NULL;
	return (tab - words);
}
