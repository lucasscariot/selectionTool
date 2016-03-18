/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:43:30 by lscariot          #+#    #+#             */
/*   Updated: 2016/03/18 11:48:23 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_index(t_files *files)
{
	int	i;

	i = 0;
	while (files)
	{
		files->id = i;
		files = files->next;
		i++;
	}
}

int		ft_del_list(t_files *files, int cursor)
{
	t_files *tmp;

	tmp = files;
	while (cursor > 0)
	{
		files = files->next;
		cursor--;
	}
	files->next = ft_del_one(files);
	ft_index(tmp);
	return (0);
}

t_files	*ft_del_one(t_files *file)
{
	t_files *tmp;

	tmp = file->next;
	free(file->name);
	free(file);
	return (tmp);
}
