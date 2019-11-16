/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:05 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 15:54:06 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"

char				*findhex(char *p)
{
	while (*p != '\0' && *p != ' ')
	{
		if (*p == ',')
			return (p + 3);
		p++;
	}
	return (NULL);
}

int					getcolor(char *p)
{
	int		conv;

	if (p == NULL)
		return (DEFAULT_COLOR);
	conv = ft_atoi_base(p, 16);
	return (conv);
}

static int			blender(int sc1, int sc2, double passed)
{
	return ((1 - passed) * sc1 + passed * sc2);
}

int					getgrad(int color1, int color2, double passed)
{
	int		red;
	int		green;
	int		blue;

	if (color1 == color2)
		return (color1);
	red = blender((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, passed);
	green = blender((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, passed);
	blue = blender(color1 & 0xFF, color2 & 0xFF, passed);
	return ((red << 16) | (green << 8) | blue);
}
