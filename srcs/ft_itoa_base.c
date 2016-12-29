/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:14:59 by exam              #+#    #+#             */
/*   Updated: 2016/12/29 20:06:21 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		numb_len(unsigned int value, unsigned int base)
{
	int	len;

	len = 1;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

static void		baserot(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9')
		{
			str[i] = 'A' + str[i] - '9' - 1;
		}
		i++;
	}
}

static char		*itoa_base(unsigned int value, unsigned int base)
{
	char	*str;
	int		i;
	int		len;

	len = numb_len(value, base);
	i = 1;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (value >= base)
	{
		str[len - i] = (value % base) + '0';
		value = value / base;
		i++;
	}
	str[len - i] = (value % base) + '0';
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		str = ft_itoa(value);
	else
		str = itoa_base(value, base);
	if (base > 10)
		baserot(str);
	return (str);
}
