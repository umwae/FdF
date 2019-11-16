/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:59 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/09 17:36:47 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "prom.h"

static int	key_action2(int keycode, t_win *win1)
{
	if (keycode == 43)
	{
		win1->sf -= 1;
		if (win1->zoom > 1)
			win1->zoom -= 0.15;
		draw_edges(win1, ' ');
	}
	if (keycode == 47)
	{
		win1->sf += 1;
		win1->zoom += 0.15;
		draw_edges(win1, ' ');
	}
	return (0);
}

int			key_action(int keycode, t_win *win1)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		draw_edges(win1, 'U');
	if (keycode == 125)
		draw_edges(win1, 'D');
	if (keycode == 123)
		draw_edges(win1, 'L');
	if (keycode == 124)
		draw_edges(win1, 'R');
	if (keycode == 69)
	{
		win1->zoom += 1;
		draw_edges(win1, ' ');
	}
	if (keycode == 78)
	{
		if (win1->zoom > 1)
			win1->zoom -= 1;
		draw_edges(win1, ' ');
	}
	return (key_action2(keycode, win1));
}
