/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:53:58 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 15:54:01 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"
#include <math.h>

static void		transform2(t_win *win1, t_pixel *pixel, char dir)
{
	double	x;
	double	y;
	double	z;

	x = pixel->x;
	y = pixel->y;
	z = pixel->z;
	if (dir == 'R')
	{
		pixel->x = x * cos(win1->rotation) + -z * sin(win1->rotation);
		pixel->z = x * sin(win1->rotation) + z * cos(win1->rotation);
	}
	else if (dir == 'U')
	{
		pixel->y = y * cos(win1->rotation) - z * sin(win1->rotation);
		pixel->z = y * sin(win1->rotation) + z * cos(win1->rotation);
	}
	else if (dir == 'I')
	{
		pixel->x = (x + y) * cos(0.523599);
		pixel->y = -z + (x - y) * -sin(0.523599);
		win1->order_flag = win1->projection;
	}
}

void			transform(t_win *win1, t_pixel *pixel, char dir)
{
	double	x;
	double	y;
	double	z;

	x = pixel->x;
	y = pixel->y;
	z = pixel->z;
	if (dir == 'D')
	{
		pixel->y = y * cos(win1->rotation) + z * sin(win1->rotation);
		pixel->z = -y * sin(win1->rotation) + z * cos(win1->rotation);
	}
	else if (dir == 'L')
	{
		pixel->x = x * cos(win1->rotation) + z * sin(win1->rotation);
		pixel->z = -x * sin(win1->rotation) + z * cos(win1->rotation);
	}
	else
		transform2(win1, pixel, dir);
}
