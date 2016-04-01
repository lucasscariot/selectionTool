/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:22:34 by lucas             #+#    #+#             */
/*   Updated: 2016/04/01 15:49:24 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_affiche(t_files *files, int cursor, int fd)
{
	ft_index(files);
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
	t_files			*tmp;
	size_t			maxlen;
	int				i;
	struct winsize	w;
	int				fd;

	i = 0;
	!(fd = open("/dev/tty", O_WRONLY)) ? ft_exit(1) : 0;
	ioctl(0, TIOCGWINSZ, &w);
	tmp = files;
	maxlen = 0;
	while (files != NULL && ++i > -1)
	{
		if (ft_strlen(files->name) > maxlen)
			maxlen = ft_strlen(files->name);
		files = files->next;
	}
	ft_putstr_fd("\033c", fd);
	(int)w.ws_col <= (int)maxlen || (int)w.ws_row <= i ?
ft_putstr_fd("Term Size\nProblem\n", fd) : ft_affiche(tmp, cursor, fd);
	close(fd);
	return (0);
}
