/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:37 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 15:54:40 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"
#include <math.h>

static void		add_offsets(t_win *win1, t_visual *w)
{
	w->x_d += win1->x_offset;
	w->y_d += win1->y_offset;
	w->x2_d += win1->x_offset;
	w->y2_d += win1->y_offset;
	w->x_i = w->x_d;
	w->y_i = w->y_d;
	w->x2_i = w->x2_d;
	w->y2_i = w->y2_d;
}

void			draw_x_str(t_win *win1, int i, int x_len, t_visual *w)
{
	int			j;
	double		coef;

	j = 0;
	coef = win1->size / win1->zoom;
	while (x_len--)
	{
		w->x_d = (win1->grid)[i][j].x * win1->zoom;
		w->y_d = (win1->grid)[i][j].y * win1->zoom;
		w->x2_d = (win1->grid)[i][j + 1].x * win1->zoom;
		w->y2_d = (win1->grid)[i][j + 1].y * win1->zoom;
		w->pxl = &(win1->grid)[i][j];
		w->gradcolor1 = (win1->grid)[i][j].color;
		w->gradcolor2 = (win1->grid)[i][j + 1].color;
		if (win1->projection == 2)
		{
			w->x_d /= fabs((win1->grid)[i][j].z - win1->sf) * coef;
			w->y_d /= fabs((win1->grid)[i][j].z - win1->sf) * coef;
			w->x2_d /= fabs((win1->grid)[i][j + 1].z - win1->sf) * coef;
			w->y2_d /= fabs((win1->grid)[i][j + 1].z - win1->sf) * coef;
		}
		add_offsets(win1, w);
		draw_line_gen(win1);
		j++;
	}
}

void			draw_y_str(t_win *win1, int i, int x_len, t_visual *w)
{
	int			j;
	double		coef;

	j = 0;
	coef = win1->size / win1->zoom;
	while (x_len--)
	{
		w->x_d = (win1->grid)[i][j].x * win1->zoom;
		w->y_d = (win1->grid)[i][j].y * win1->zoom;
		w->x2_d = (win1->grid)[i + 1][j].x * win1->zoom;
		w->y2_d = (win1->grid)[i + 1][j].y * win1->zoom;
		w->pxl = &(win1->grid)[i][j];
		w->gradcolor1 = (win1->grid)[i][j].color;
		w->gradcolor2 = (win1->grid)[i + 1][j].color;
		if (win1->projection == 2)
		{
			w->x_d /= fabs((win1->grid)[i][j].z - win1->sf) * coef;
			w->y_d /= fabs((win1->grid)[i][j].z - win1->sf) * coef;
			w->x2_d /= fabs((win1->grid)[i + 1][j].z - win1->sf) * coef;
			w->y2_d /= fabs((win1->grid)[i + 1][j].z - win1->sf) * coef;
		}
		add_offsets(win1, w);
		draw_line_gen(win1);
		j++;
	}
}

void			draw_x_rev(t_win *win1, int i, int x_len, t_visual *w)
{
	double		coef;

	coef = win1->size / win1->zoom;
	while (x_len > 0)
	{
		w->x_d = (win1->grid)[i][x_len].x * win1->zoom;
		w->y_d = (win1->grid)[i][x_len].y * win1->zoom;
		w->x2_d = (win1->grid)[i][x_len - 1].x * win1->zoom;
		w->y2_d = (win1->grid)[i][x_len - 1].y * win1->zoom;
		w->pxl = &(win1->grid)[i][x_len];
		w->gradcolor1 = (win1->grid)[i][x_len].color;
		w->gradcolor2 = (win1->grid)[i][x_len - 1].color;
		if (win1->projection == 2)
		{
			w->x_d /= fabs((win1->grid)[i][x_len].z - win1->sf) * coef;
			w->y_d /= fabs((win1->grid)[i][x_len].z - win1->sf) * coef;
			w->x2_d /= fabs((win1->grid)[i][x_len - 1].z - win1->sf) * coef;
			w->y2_d /= fabs((win1->grid)[i][x_len - 1].z - win1->sf) * coef;
		}
		add_offsets(win1, w);
		draw_line_gen(win1);
		x_len--;
	}
}

void			draw_y_rev(t_win *win1, int i, int x_len, t_visual *w)
{
	double		coef;

	coef = win1->size / win1->zoom;
	while (x_len >= 0)
	{
		w->x_d = (win1->grid)[i][x_len].x * win1->zoom;
		w->y_d = (win1->grid)[i][x_len].y * win1->zoom;
		w->x2_d = (win1->grid)[i - 1][x_len].x * win1->zoom;
		w->y2_d = (win1->grid)[i - 1][x_len].y * win1->zoom;
		w->pxl = &(win1->grid)[i][x_len];
		w->gradcolor1 = (win1->grid)[i][x_len].color;
		w->gradcolor2 = (win1->grid)[i - 1][x_len].color;
		if (win1->projection == 2)
		{
			w->x_d /= fabs((win1->grid)[i][x_len].z - win1->sf) * coef;
			w->y_d /= fabs((win1->grid)[i][x_len].z - win1->sf) * coef;
			w->x2_d /= fabs((win1->grid)[i - 1][x_len].z - win1->sf) * coef;
			w->y2_d /= fabs((win1->grid)[i - 1][x_len].z - win1->sf) * coef;
		}
		add_offsets(win1, w);
		draw_line_gen(win1);
		x_len--;
	}
}
