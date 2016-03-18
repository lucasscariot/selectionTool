/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:43:29 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 13:10:16 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_files		*ft_new_file(t_files *files, char *n)
{
	t_files		*new_file;
	t_files		*tmp;
	static int	i;

	if (!i)
		i = 0;
	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return (NULL);
	new_file->name = ft_strdup(n);
	new_file->id = i;
	new_file->chckd = 0;
	new_file->del = 0;
	i++;
	new_file->next = NULL;
	if (!files)
		return (new_file);
	else
	{
		tmp = files;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_file;
		return (files);
	}
	return (new_file);
}

t_files		*ft_save(char **av)
{
	t_files	*file;
	int		i;

	i = 1;
	file = NULL;
	while (av[i])
		file = ft_new_file(file, av[i++]);
	if (!file)
		ft_exit(4);
	return (file);
}
