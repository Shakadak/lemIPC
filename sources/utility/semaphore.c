/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 13:34:44 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 15:24:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include "lemipc.h"

static void	wait_sem(t_env *e, int nsems)
{
	int				i;
	int				ready;
	t_sem			arg;
	struct semid_ds	buf;

	e->semid = semget(e->key, nsems, 0);
	if (e->semid < 0)
		return ;
	arg.buf = &buf;
	arg.val = 1;
	i = 10;
	ready = 0;
	while (i-- && !ready)
	{
		semctl(e->semid, nsems - 1, IPC_STAT, arg);
		if (arg.buf->sem_otime != 0)
			ready = 1;
		else
			sleep(1);
	}
	if (!ready)
	{
		errno = ETIME;
		return ;
	}
}

static void	init_sem(t_env *e, int nsems)
{
	struct sembuf	sb;
	int				err;

	sb.sem_op = 1;
	sb.sem_flg = 0;
	sb.sem_num = 0;
	while (sb.sem_num < nsems)
	{
		if (semop(e->semid, &sb, 1) == -1)
		{
			err = errno;
			semctl(e->semid, 0, IPC_RMID);
			errno = err;
			return ;
		}
		sb.sem_num++;
	}
}

void		get_sem_id(t_env *e, int nsems)
{
	e->sb.sem_num = 0;
	e->sb.sem_op = -1;
	e->sb.sem_flg = SEM_UNDO;
	e->semid = semget(e->key, nsems, IPC_CREAT | IPC_EXCL | 0666);
	if (e->semid >= 0)
		init_sem(e, nsems);
	else if (errno == EEXIST)
		wait_sem(e, nsems);
	else
		return ;
}

void		lock_sem(t_env *e, int lock)
{
	e->sb.sem_op = lock;
	x_int(-1, semop(e->semid, &e->sb, 1), "semop");
}
