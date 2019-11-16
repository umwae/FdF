/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:20 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/30 16:25:39 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include "prom.h"

void	err_ex(int pr)
{
	if (pr == 0)
		ft_putstr("Error: memory allocation failure\n");
	if (pr == 1)
		ft_putstr("Error: invalid map\n");
	if (pr == 2)
		ft_putstr("Error: can't read from file\n");
	exit(1);
}

int		start2(t_win *win1, char dir)
{
	draw_edges(win1, dir);
	mlx_hook(win1->win, 2, 1, key_action, win1);
	mlx_loop(win1->mlx);
	return (0);
}

int		start(char *argv, char proj)
{
	t_win		*win1;
	int			fd0;
	int			fd;

	fd0 = open(argv, O_RDONLY);
	fd = open(argv, O_RDONLY);
	if (!(win1 = (t_win *)malloc(sizeof(t_win))))
		err_ex(0);
	if (!(win1->mlx = mlx_init()))
		err_ex(0);
	if (!(win1->win = mlx_new_window(win1->mlx, WIN_WIDTH, WIN_HIGHT, "FdF")))
		err_ex(0);
	if (!(win1->vs = (t_visual *)malloc(sizeof(t_visual))))
		err_ex(0);
	win1->size = SIZE_CONST;
	win1->sf = SIZE_FACTOR;
	win1->rotation = ROTATION;
	win1->order_flag = 0;
	get_grid(fd0, fd, win1);
	if (proj == 'I')
		win1->projection = 1;
	if (proj == 'C')
		win1->projection = 2;
	start2(win1, proj);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 || (ft_strncmp(argv[argc - 1], "parallel", 9) == 0))
		start(argv[1], ' ');
	else if (ft_strncmp(argv[argc - 1], "iso", 4) == 0)
		start(argv[1], 'I');
	else if (ft_strncmp(argv[argc - 1], "conic", 6) == 0)
		start(argv[1], 'C');
	else
		ft_putstr("usage: ./fdf map_file projection_type\n");
	return (0);
}
