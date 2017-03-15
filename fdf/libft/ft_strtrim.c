/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:32:11 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/07 18:38:53 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_whitesp(int c)
{
	return (c == ' ' || c == ',' || c == '\n' || c == '\t');
}

static int	ft_count(char const *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] && ft_is_whitesp(s[i]))
		i++;
	if (i == (int)ft_strlen(s))
		return (i);
	j = ft_strlen(s) - 1;
	while (s[j] && ft_is_whitesp(s[j]))
	{
		i++;
		j--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) - ft_count(s))
					+ 1)))
		return (0);
	i = 0;
	while (ft_is_whitesp(s[i]) && s[i])
		i++;
	if (i == (int)ft_strlen(s))
		return ("");
	j = 0;
	while (s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	while (ft_is_whitesp(str[j - 1]))
		j--;
	str[j] = '\0';
	return (str);
}
