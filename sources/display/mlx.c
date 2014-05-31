/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:21:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/31 17:26:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

static void		draw(t_env *e)
{
	int		i;
	int		j;
	char	buff[WIDTH * HEIGHT];

	lock_sem(e, LOCK);
	ft_strncpy(buff, e->map, WIDTH * HEIGHT);
	lock_sem(e, UNLOCK);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (buff[j + i * HEIGHT])
				mlx_pixel_put(e->mlx.mlx, e->mlx.win, j, i, 0xAAAAAA);
			else
				mlx_pixel_put(e->mlx.mlx, e->mlx.win, j, i, 0x444444);
			j++;
		}
		i++;
	}
}

static int		expose_hook(t_env *e)
{
	while (77)
	{
		draw(e);
		usleep(16667);
	}
	return (0);
}

static int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		clean_up(e);
		exit (0);
	}
	return (0);
}

void			mlx(t_env *e)
{
	e->mlx.mlx = x_void(NULL, mlx_init(), "mlx_init");
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Death Match");
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	mlx_key_hook(e->mlx.win, key_hook, &e);
	mlx_expose_hook(e->mlx.win, expose_hook, &e);
	mlx_loop(e->mlx.mlx);
}
