/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:22:34 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 14:13:48 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_aff(t_files *files, int cursor, int listlen)
{
	t_files			*tmp;
	size_t			maxlen;
	struct winsize	w;
	int				i;
	int				fd;

	if (!(fd = open("/dev/tty", O_WRONLY)))
		ft_exit(1);
	i = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	tmp = files;
	maxlen = 0;
	while (files != NULL)
	{
		if (ft_strlen(files->name) > maxlen)
			maxlen = ft_strlen(files->name);
		files = files->next;
	}
	files = tmp;
	ft_index(files);
	ft_putstr_fd("\033c", fd);
	while (files != NULL)
	{
		if (files->del)
			files = files->next;
		ft_print_color(files, cursor, fd);
		if (files->id < listlen)
		{
			ft_putstr_fd("  ", fd);
			ft_putnchar_fd(' ', maxlen - ft_strlen(files->name), fd);
		}
		//dprintf(fd, "%d >= %d\n", i, (int)(w.ws_col / (maxlen + 3)));
		if (i >= (int)(w.ws_col / (maxlen + 7)))
		{
			ft_putchar_fd('\n', fd);
			i = 0;
		}
		else
			i++;
		files = files->next;
	}
	return (0);
}
