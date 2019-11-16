/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:10 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/14 18:13:08 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"
#include <stdlib.h>

static void		grid_line(char *line, int j, t_win *win1)
{
	char			**arr;
	int				i;
	t_pixel			*pxl_str;
	int				line_len_ct;

	i = 0;
	arr = ft_strsplit(line, ' ');
	if ((pxl_str = (t_pixel *)malloc(sizeof(t_pixel) * win1->x_len)) == NULL)
		err_ex(0);
	line_len_ct = win1->x_len;
	while (line_len_ct--)
	{
		(pxl_str + i)->x = i - win1->x_len / 2;
		(pxl_str + i)->y = j - win1->y_len / 2;
		if (!arr[i])
			err_ex(1);
		(pxl_str + i)->z = ft_atoi(arr[i]) / Z_DIVISOR;
		(pxl_str + i)->color = getcolor(findhex(arr[i]));
		i++;
	}
	ft_arrfree(&arr, win1->x_len);
	(win1->grid)[j] = pxl_str;
}

static void		calc_display_position(t_win *win1)
{
	if (WIN_WIDTH / win1->x_len < WIN_HIGHT / win1->y_len)
		win1->zoom = WIN_WIDTH * SCALE / win1->x_len;
	else
		win1->zoom = WIN_HIGHT * SCALE / win1->y_len;
	if (win1->zoom < 0.001)
		win1->zoom = 0.001;
	win1->x_offset = WIN_WIDTH / 2;
	win1->y_offset = WIN_HIGHT / 2;
}

static void		get_grid2(char *line, int fd, t_win *win1)
{
	int		yos;

	yos = 0;
	if (!(win1->grid = (t_pixel **)malloc(sizeof(t_pixel *) * win1->y_len)))
		err_ex(0);
	calc_display_position(win1);
	while (get_next_line(fd, &line) == 1)
	{
		grid_line(line, yos, win1);
		yos++;
		free(line);
	}
	close(fd);
	img_new(win1);
}

void			get_grid(int fd0, int fd, t_win *win1)
{
	char		*line;
	int			yc;

	yc = 0;
	if (get_next_line(fd0, &line) == 1)
	{
		yc++;
		validate(line);
	}
	else
		err_ex(2);
	win1->x_len = ft_ctwords(line, ' ');
	free(line);
	while (get_next_line(fd0, &line) == 1)
	{
		yc++;
		validate(line);
		free(line);
	}
	win1->y_len = yc;
	close(fd0);
	get_grid2(line, fd, win1);
}
