/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:23:21 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/11 13:15:19 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double  percent(t_pix start, t_pix finish, t_pix point)
{
	double	len;
	double	current;

	if (abs(finish.x - start.x) > abs(finish.y - start.y))
	{
		len = finish.x - start.x;
		current = point.x - start.x;
	}
	else
	{
		len = finish.y - start.y;
		current = point.y - start.y;
	}
	return ((len == 0) ? 1.0 : (current / len));
}

int		ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}

int		key_pressed(int key, void *param)
{
	void	*dummy;
	
	dummy = param;
	ft_putnbr(key);
	ft_putendl(" was pressed");
	if (key == 53)
		exit(0);
	return (0);
}