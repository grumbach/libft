/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 18:30:39 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/27 00:20:13 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arraygrow(t_array *array)
{
	void		*tmp;

	if (!array)
		return (0);
	tmp = array->content;
	array->content = ft_memalloc(array->typesize * (array->arraysize * 2));
	if (!(array->content))
		return (0);
	ft_memcpy(array->content, tmp, (array->typesize * array->arraysize));
	array->arraysize *= 2;
	free(tmp);
	return (1);
}

t_array		*ft_arrayadd(t_array *array, void *new, int index, size_t size)
{
	int		i;

	i = 0;
	if (!new || !array)
		return (NULL);
	while (array->arraysize - index < (int)size)
		if (!(ft_arraygrow(array)))
			return (NULL);
	ft_memcpy(array->content + (index * array->typesize), new, \
		size * array->typesize);
	return (array);
}