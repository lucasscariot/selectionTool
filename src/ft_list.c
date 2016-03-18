/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 16:36:14 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 11:29:08 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_swap_cpy(t_files *dest, t_files *src)
{
	dest->name = ft_strdup(src->name);
}

void	ft_swap_list(t_files *f, t_files *s)
{
	t_files	*tmp;

	if (!f && !s)
		return ;
	tmp = (t_files*)malloc(sizeof(t_files));
	ft_swap_cpy(tmp, s);
	ft_free_one(s);
	ft_swap_cpy(s, f);
	ft_free_one(f);
	ft_swap_cpy(f, tmp);
	ft_free_one(tmp);
	free(tmp);
}
