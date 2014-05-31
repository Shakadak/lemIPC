/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 13:36:31 by npineau           #+#    #+#             */
/*   Updated: 2014/05/31 14:16:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemipc.h"

static void	usage(char *file)
{
	ft_putstr("Usage: ");
	ft_putstr(file);
	ft_putendl(" --gfx | <team_number>");
	exit(1);
}

void		get_options(int ac, char **av, t_env *e)
{
	if (ac != 2)
		usage(av[0]);
	else if (ft_strequ(av[1], "--gfx"))
		e->type = 1;
	else if (ft_isx(av[1], ft_isdigit))
	{
		e->type = 0;
		e->player.team = ft_atoi(av[1]);
	}
	else
		usage(av[0]);
}
