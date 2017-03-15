/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:48:01 by abenea            #+#    #+#             */
/*   Updated: 2017/01/07 19:27:18 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_rev(char *str, int len)
{
	int			start;
	int			end;
	char		temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
		start++;
		end--;
	}
}

static void		ft_iszero(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
}

static void		ft_intmin(char *str, int n)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
	}
}

static int		ft_count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*ptr;
	int			isneg;

	if (!(ptr = (char *)malloc(sizeof(char) * ft_count(n) + 1)))
		return (0);
	i = 0;
	isneg = 0;
	ft_iszero(ptr, n);
	ft_intmin(ptr, n);
	if (n < 0 && n > -2147483648)
	{
		isneg = 1;
		n = -n;
	}
	while (n != 0 && n != -2147483648)
	{
		ptr[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (isneg)
		ptr[i++] = '-';
	ptr[ft_strlen(ptr)] = '\0';
	ft_rev(ptr, i);
	return (ptr);
}
