/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:47 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 18:15:37 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "prom.h"

void		img_new(t_win *win1)
{
	char	*img;
	int		bpp;
	int		endian;

	if (!(img = mlx_new_image(win1->mlx, WIN_WIDTH, WIN_HIGHT)))
		err_ex(0);
	win1->image = mlx_get_data_addr(img, &bpp, &(win1->linesize), &endian);
	win1->img_ptr = img;
}

void		img_pxl(t_win *win1)
{
	char	*p;

	if (win1->vs->x >= WIN_WIDTH || win1->vs->y >= WIN_HIGHT || \
		win1->vs->x < 0 || win1->vs->y < 0)
		return ;
	p = win1->image;
	p += (win1->vs->x * 32 / 8) + (win1->linesize * win1->vs->y);
	*p++ = (win1->vs->color) & 0xFF;
	*p++ = (win1->vs->color >> 8) & 0xFF;
	*p = (win1->vs->color >> 16) & 0xFF;
}
