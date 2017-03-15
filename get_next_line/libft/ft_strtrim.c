/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:34:02 by abenea            #+#    #+#             */
/*   Updated: 2017/01/07 17:30:14 by abenea           ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	while (ft_is_whitesp(s[i]) && s[i])
		i++;
	j = ft_strlen(s) - 1;
	return (j - i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * ft_count(s) + 1)))
		return (0);
	i = 0;
	while (ft_is_whitesp(s[i]))
		i++;
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
