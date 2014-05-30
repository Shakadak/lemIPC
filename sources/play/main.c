/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:27:36 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 17:19:32 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include "lemipc.h"

static void	init_env(t_env *e, char *file)
{
	e->key = x_int(-1, ftok(file, 'N'), "ftok");
	init_queue(e);
	get_map(e);
	get_sem_id(e, 1);
}

int			main(int ac, char **av)
{
	t_env	e;

	(void)ac;
	init_env(&e, av[0]);
	detach_map(&e);
	clean_up(&e);
	return (0);
}
