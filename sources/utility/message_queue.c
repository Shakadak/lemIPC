/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/30 17:04:12 by npineau           #+#    #+#             */
/*   Updated: 2014/05/30 17:19:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/msg.h>
#include "lemipc.h"

void	init_queue(t_env *e)
{
	e->msgid = x_int(-1, msgget(e->key, 0666 | IPC_CREAT), "msgget");
}
