/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fac.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:50:34 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/18 18:27:00 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fac(int n)
{
	if (n < 0 || n > 12)
		return (-1);
	if (n == 1)
		return (1);
	else
		return (n * ft_fac(n - 1));
}
