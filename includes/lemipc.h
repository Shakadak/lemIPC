/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:12:02 by npineau           #+#    #+#             */
/*   Updated: 2014/05/29 18:47:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEMIPC_H
# define	LEMIPC_H

# define	WIDTH	200
# define	HEIGHT	200

typedef struct	s_env
{
	key_t		key;
	int			id;
	char		*map;
}				t_env;

void	get_map(char *file, t_env *e);
void	detach_map(t_env *e);
void	destroy_map(t_env *e);
int		x_int(int err, int res, char *str);
void	*x_void(void *err, void *res, char *str);

#endif
