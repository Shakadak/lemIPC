/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:27:36 by npineau           #+#    #+#             */
/*   Updated: 2014/05/29 18:06:01 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include "lemipc.h"

int	main(int ac, char **av)
{
	char	*map;

	map = get_map(av[0]);
	x_int(-1, shmdt(data), "shmdt");
	return (0);
}
