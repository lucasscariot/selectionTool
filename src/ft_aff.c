/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:22:34 by lucas             #+#    #+#             */
/*   Updated: 2016/03/31 14:49:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_affiche(t_files *files, int cursor, int fd)
{
	ft_index(files);
	ft_putstr_fd("\033c", fd);
	while (files != NULL)
	{
		if (files->del)
			files = files->next;
		ft_print_color(files, cursor, fd);
		ft_putchar_fd('\n', fd);
		files = files->next;
	}
	return (0);
}

int		ft_aff(t_files *files, int cursor)
{
	t_files         *tmp;
	size_t          maxlen;
	int             fd;

	if (!(fd = open("/dev/tty", O_WRONLY)))
		ft_exit(1);
	tmp = files;
	maxlen = 0;
	while (files != NULL)
	{
		if (ft_strlen(files->name) > maxlen)
			maxlen = ft_strlen(files->name);
		files = files->next;
	}
	ft_affiche(tmp, cursor, fd);
	close(fd);
	return (0);
}
