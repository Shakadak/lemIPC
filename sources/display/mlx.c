/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 14:21:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/31 15:41:57 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mlx(t_env *e)
{
	e->mlx.mlx = mlx_init()
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Death Match");
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
}
