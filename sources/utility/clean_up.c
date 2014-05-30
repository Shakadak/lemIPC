/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:03:57 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 16:39:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include "lemipc.h"

void	clean_up(t_env *e)
{
	struct shmid_ds	tmp;

	x_int(-1, shmctl(e->id, IPC_STAT, &tmp), "shmctl");
	if (tmp.shm_nattch == 0)
	{
		if (shmctl(e->id, IPC_RMID, NULL) == -1)
			perror("shmctl");
		x_int(-1, semctl(e->semid, 0, IPC_RMID), "semctl");
	}
}
