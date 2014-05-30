/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:12:02 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 16:53:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEMIPC_H
# define	LEMIPC_H

# include <sys/sem.h>

# define	WIDTH	200
# define	HEIGHT	200

typedef union		u_sem
{
	int				val;
	struct semid_ds	*buf;
	unsigned short	*array;
}					t_sem;

typedef struct		s_env
{
	key_t			key;
	int				id;
	int				semid;
	int				msgid;
	struct sembuf	sb;
	char			*map;
}					t_env;

void				get_map(t_env *e);
void				detach_map(t_env *e);

void	clean_up(t_env *e);

void				get_sem_id(t_env *e, int nsems);
void				lock_sem(t_env *e, int lock);

int					x_int(int err, int res, char *str);
void				*x_void(void *err, void *res, char *str);

#endif
