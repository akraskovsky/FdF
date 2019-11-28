/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:23:21 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/28 17:23:30 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double  percent(int start, int finish, int point)
{
	double	len;
	double	current;

	len = finish - start;
	current = point - start;
	return ((len == 0) ? 1.0 : (current/len));
}

int		ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}