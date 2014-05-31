/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 16:08:26 by npineau           #+#    #+#             */
/*   Updated: 2014/05/31 17:09:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "lemipc.h"

static void	place_self(t_env *e)
{
	e->map[e->player.x + e->player.y * WIDTH] = e->player.team;
}

static void	init_pos(t_env *e)
{
	int	fd;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &(e->player.x), sizeof(int));
	read(fd, &(e->player.y), sizeof(int));
	e->player.x = e->player.x % WIDTH;
	e->player.y = e->player.y % HEIGHT;
	close(fd);
	place_self(e);
}

void	play(t_env *e)
{
	while (getchar() != EOF)
	{
		lock_sem(e, LOCK);
		init_pos(e);
		lock_sem(e, UNLOCK);
	}
}
