/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:33:08 by agrumbac          #+#    #+#             */
/*   Updated: 2017/02/18 14:29:17 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (!(*s ^ (0xf & c)))
			return (s);
		s++;
	}
	if (!(*s ^ (0xf & c)))
		return (s);
	return (0);
}
