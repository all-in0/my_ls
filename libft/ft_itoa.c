/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:12 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:12:09 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*rev;

	rev = (char *)malloc(ft_strlen(str) + 1);
	if (!rev)
		return (0);
	j = ft_strlen(str);
	i = 0;
	while (j > 0)
	{
		rev[i] = str[j - 1];
		i++;
		j--;
	}
	rev[i] = 0;
	free(str);
	return (rev);
}

char			*ft_itoa(long long n)
{
	int			i;
	char		*str;
	int			neg;
	long long	ncpy;

	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	i = 0;
	neg = 0;
	ncpy = n;
	ncpy = ncpy < 0 ? -ncpy : ncpy;
	if (n < 0)
		neg = 1;
	if (!(str = (char *)malloc(20)))
		return (0);
	while (ncpy >= 10)
	{
		str[i++] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	str[i] = ncpy % 10 + '0';
	if (neg == 1)
		str[++i] = '-';
	str[i + 1] = 0;
	return (ft_strrev(str));
}
