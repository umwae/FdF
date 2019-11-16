/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draftsman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:53 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 15:54:56 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "prom.h"

static int		legal_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void		draw_line_low(t_win *win1, t_visual *w)
{
	w->y = w->y_i;
	w->x = w->x_i;
	w->dx = (w->x2_i - w->x_i);
	w->dy = (w->y2_i - w->y_i);
	w->yi = w->dy < 0 ? -1 : 1;
	w->dy = fabs(w->dy);
	w->d = 2 * w->dy - w->dx;
	while (w->x <= w->x2_i)
	{
		if (w->dx > w->dy)
			w->passed = (w->x - w->x_i) / w->dx;
		else
			w->passed = (w->y - w->y_i) / w->dy;
		w->color = getgrad(w->gradcolor1, w->gradcolor2, w->passed);
		img_pxl(win1);
		if (w->d > 0)
		{
			w->y += w->yi;
			w->d = w->d - 2 * w->dx;
		}
		w->d = w->d + 2 * w->dy;
		w->x++;
	}
}

static void		draw_line_high(t_win *win1, t_visual *w)
{
	w->y = w->y_i;
	w->x = w->x_i;
	w->dx = (w->x2_i - w->x_i);
	w->dy = (w->y2_i - w->y_i);
	w->xi = w->dx < 0 ? -1 : 1;
	w->dx = fabs(w->dx);
	w->d = 2 * w->dx - w->dy;
	while (w->y <= w->y2_i)
	{
		if (w->dx > w->dy)
			w->passed = (w->x - w->x_i) / w->dx;
		else
			w->passed = (w->y - w->y_i) / w->dy;
		w->color = getgrad(w->gradcolor1, w->gradcolor2, w->passed);
		img_pxl(win1);
		if (w->d > 0)
		{
			w->x += w->xi;
			w->d = w->d - 2 * w->dy;
		}
		w->d = w->d + 2 * w->dx;
		w->y++;
	}
}

static void		swap_points(t_visual *w)
{
	int		tmp;

	tmp = w->gradcolor1;
	w->gradcolor1 = w->gradcolor2;
	w->gradcolor2 = tmp;
	tmp = w->x_i;
	w->x_i = w->x2_i;
	w->x2_i = tmp;
	tmp = w->y_i;
	w->y_i = w->y2_i;
	w->y2_i = tmp;
}

void			draw_line_gen(t_win *win1)
{
	t_visual	*w;

	w = win1->vs;
	if (legal_abs(w->y2_i - w->y_i) <
		legal_abs(w->x2_i - w->x_i))
	{
		if (w->x_i >= w->x2_i)
			swap_points(w);
		draw_line_low(win1, w);
	}
	else
	{
		if (w->y_i >= w->y2_i)
			swap_points(w);
		draw_line_high(win1, w);
	}
}
