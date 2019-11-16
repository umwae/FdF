/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:05 by jsteuber          #+#    #+#             */
/*   Updated: 2019/04/06 15:55:07 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"

static int	ishex(char c)
{
	if (c == ',' || ft_isdigit(c) == 1 || (c >= 'a' && c <= 'f') || \
	(c >= 'A' && c <= 'F') || c == 'x' || c == ' ')
		return (0);
	return (1);
}

void		validate(char *line)
{
	char	*p;

	p = line;
	while (*p)
	{
		if (ishex(*p) == 1)
			err_ex(1);
		p++;
	}
}
