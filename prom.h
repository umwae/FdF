/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:16 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/09 19:28:08 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROM_H
# define PROM_H
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_pixel;

typedef struct		s_visual
{
	double			x_d;
	double			y_d;
	double			x2_d;
	double			y2_d;
	int				x_i;
	int				y_i;
	int				x2_i;
	int				y2_i;
	int				gradcolor1;
	int				gradcolor2;
	double			dx;
	double			dy;
	int				y;
	int				x;
	int				yi;
	int				xi;
	int				d;
	int				color;
	double			passed;
	t_pixel			*pxl;
}					t_visual;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	t_pixel			**grid;
	int				x_len;
	int				y_len;
	int				x_offset;
	int				y_offset;
	double			sf;
	t_visual		*vs;
	double			zoom;
	int				projection;
	double			size;
	double			rotation;
	char			*img_ptr;
	void			*image;
	int				linesize;
	int				order_flag;
}					t_win;

# define WIN_WIDTH 1500
# define WIN_HIGHT 1300
# define SCALE 0.25
# define SIZE_FACTOR 260
# define Z_DIVISOR 1
# define DEFAULT_COLOR 0xffffff
# define SIZE_CONST 0.1
# define ROTATION -0.1

int					start(char *argv, char pr);
int					start2(t_win *win1, char dir);
void				get_grid(int fd0, int fd, t_win *win1);
void				draw_line_gen(t_win *win1);
void				draw_edges(t_win *win1, char dir);
char				*findhex(char *p);
int					getcolor(char *p);
int					getgrad(int color1, int color2, double passed);
void				transform(t_win *win1, t_pixel *pixel, char dir);
void				validate(char *line);
void				img_new(t_win *win1);
void				img_pxl(t_win *win1);
int					key_action(int keycode, t_win *win1);
void				err_ex(int pr);
void				draw_x_str(t_win *win1, int i, int x_len, t_visual *w);
void				draw_y_str(t_win *win1, int i, int x_len, t_visual *w);
void				draw_x_rev(t_win *win1, int i, int x_len, t_visual *w);
void				draw_y_rev(t_win *win1, int i, int x_len, t_visual *w);

#endif
