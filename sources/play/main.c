/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:27:36 by npineau           #+#    #+#             */
/*   Updated: 2014/05/29 18:46:47 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include "lemipc.h"

int	main(int ac, char **av)
{
	t_env	e;

	(void)ac;
	get_map(av[0], &e);
	detach_map(&e);
	destroy_map(&e);
	return (0);
}
