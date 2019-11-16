/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:43 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 20:13:51 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"
#include "mlx.h"
#include <stdlib.h>

static void		order_str(t_win *win1, t_visual *w)
{
	int			i;
	int			x_len;
	int			y_len;

	y_len = win1->y_len - 1;
	i = 0;
	while (y_len--)
	{
		x_len = win1->x_len - 1;
		if (win1->x_len > 1 && \
			((win1->grid)[0][0].z >= (win1->grid)[0][x_len].z))
			draw_x_rev(win1, i, x_len, w);
		else
			draw_x_str(win1, i, x_len, w);
		draw_y_str(win1, i, x_len + 1, w);
		i++;
	}
	x_len = win1->x_len - 1;
	draw_x_str(win1, i, x_len, w);
}

static void		order_rev(t_win *win1, t_visual *w)
{
	int			i;
	int			x_len;
	int			y_len;

	y_len = win1->y_len - 1;
	i = 0;
	while (y_len > 0)
	{
		x_len = win1->x_len - 1;
		if (win1->x_len > 1 && \
			((win1->grid)[0][0].z <= (win1->grid)[0][x_len].z))
			draw_x_str(win1, y_len, x_len, w);
		else
			draw_x_rev(win1, y_len, x_len, w);
		draw_y_rev(win1, y_len, x_len, w);
		y_len--;
		i++;
	}
	x_len = win1->x_len - 1;
	draw_x_rev(win1, y_len, x_len, w);
}

static void		display(t_win *win1)
{
	int			y_len;
	t_visual	*w;

	w = win1->vs;
	y_len = win1->y_len - 1;
	mlx_destroy_image(win1->mlx, win1->img_ptr);
	img_new(win1);
	if (win1->y_len > 1 && \
		((win1->grid)[0][0].z <= (win1->grid)[y_len][0].z || \
		win1->order_flag == 1))
		order_str(win1, w);
	else
		order_rev(win1, w);
	mlx_put_image_to_window(win1->mlx, win1->win, win1->img_ptr, 0, 0);
}

void			draw_edges(t_win *win1, char dir)
{
	int			i;
	int			j;
	int			x_len;
	int			y_len;
	t_pixel		**grid;

	grid = win1->grid;
	i = 0;
	y_len = win1->y_len;
	while (y_len--)
	{
		j = 0;
		x_len = win1->x_len;
		while (x_len--)
			transform(win1, &(grid)[i][j++], dir);
		i++;
	}
	display(win1);
	if (win1->projection == 1)
		win1->projection = 0;
}
