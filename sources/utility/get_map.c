/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:33:56 by npineau           #+#    #+#             */
/*   Updated: 2014/05/29 18:01:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "lemipc.h"

static char	*init_map(key_t key)
{
	int		shmid;
	char	*data;

	shmid = x_int(-1, shmget(key, WIDTH * HEIGHT, 0666 | IPC_CREAT), "shmget");
	else
		data = x_void((void *)-1, shmat(shmid, NULL, 0), "shmat");
	ft_bzero(data, WIDTH * HEIGHT);
	return (data);
}

char		*get_map(char *file)
{
	key_t	key;
	int		shmid;
	char	*data;

	key = x_int(-1, ftok("unavailabe", 'N'), "ftok");
	if ((shmid = shmget(key, WIDTH * HEIGHT, 0)) == -1)
	{
		if (errno == ENOENT)
			return (init_map(key));
		else
			x_int(-1, -1, "shmget");
	}
	else
		return (x_void((void *)-1, shmat(shmid, NULL, 0), "shmat"));
}
