/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:22:34 by lucas             #+#    #+#             */
/*   Updated: 2016/03/16 16:17:31 by lucas            ###   ########.fr       */
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
	system("clear");
	while (files != NULL)
	{
		if (files->id == cursor)
			ft_putcolor(files->name, SOULIGNE);
		else
		{
			if (files->chckd)
				ft_putcolor(files->name, BLUE);
			else
				ft_putstr_fd(files->name, fd);
		}
		if (files->id < listlen)
		{
			ft_putstr("  ");
			ft_putnchar(' ', maxlen - ft_strlen(files->name));
		}
		if (i >= (int)(w.ws_col / (maxlen + 7)))
		{
			ft_putchar('\n');
			i = 0;
		}
		else
			i++;
		files = files->next;
	}
	//printf("Maxlen = %zu\n", maxlen);
	//printf ("lines %d\n", w.ws_row);
	//printf ("columns %d\n", w.ws_col);
	return (0);
}
