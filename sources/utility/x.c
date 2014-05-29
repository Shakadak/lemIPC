/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:45:46 by npineau           #+#    #+#             */
/*   Updated: 2014/05/29 17:47:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int		x_int(int err, int res, char *str)
{
	if (res == err)
	{
		perror(str);
		exit (1);
	}
	return (res);
}

void	*x_void(void *err, void *res, char *str)
{
	if (res == err)
	{
		perror(str);
		exit (1);
	}
	return (res);
}
