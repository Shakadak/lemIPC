/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 16:03:57 by npineau           #+#    #+#             */
/*   Updated: 2014/06/14 17:30:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <stdio.h>
#include "lemipc.h"

void	clean_up(t_env *e)
{
	struct shmid_ds	tmp;

	detach_map(e);
	x_int(-1, shmctl(e->id, IPC_STAT, &tmp), "shmctl");
	if (tmp.shm_nattch == 0)
	{
		if (msgctl(e->msgid, IPC_RMID, NULL) == -1)
			perror("msgctl");
		if (shmctl(e->id, IPC_RMID, NULL) == -1)
			perror("shmctl");
		x_int(-1, semctl(e->semid, 0, IPC_RMID), "semctl");
	}
}
