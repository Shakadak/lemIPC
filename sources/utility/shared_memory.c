/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:30:13 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 16:54:15 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "lemipc.h"

static void	init_map(t_env *e)
{
	e->id = x_int(-1, shmget(e->key, WIDTH * HEIGHT, 0666 | IPC_CREAT), "shmget");
	e->map = x_void((void *)-1, shmat(e->id, NULL, 0), "shmat");
	ft_bzero(e->map, WIDTH * HEIGHT);
}

void		get_map(t_env *e)
{
	if ((e->id = shmget(e->key, WIDTH * HEIGHT, 0)) == -1)
	{
		if (errno == ENOENT)
			init_map(e);
		else
			x_int(-1, -1, "shmget");
	}
	else
		e->map = x_void((void *)-1, shmat(e->id, NULL, 0), "shmat");
}

void		detach_map(t_env *e)
{
	x_int(-1, shmdt(e->map), "shmdt");
}
