/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:43:30 by lscariot          #+#    #+#             */
/*   Updated: 2016/04/01 13:58:01 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_index(t_files *files)
{
	int i;

	i = 0;
	while (files)
	{
		if (files->del == 0)
		{
			files->id = i;
			i++;
		}
		files = files->next;
	}
}

void	ft_del_list(t_files *var, int cursor)
{
	t_files	*save;
	t_files	*tmp;
	int		hoo;

	hoo = cursor;
	tmp = var;
	if (ft_list_len(var) == 0)
		ft_exit(0);
	if (hoo == 0)
	{
		ft_swap_list(var, var->next);
		ft_del_list(var, cursor + 1);
		return ;
	}
	while (--hoo)
		var = var->next;
	if (!var)
		return ;
	save = var->next;
	var->next = var->next->next;
	ft_free_one(save);
	free(save);
}

t_files	*ft_del_one(t_files *file)
{
	t_files *tmp;

	tmp = file->next;
	file->del = 1;
	free(file->name);
	free(file);
	return (tmp);
}
