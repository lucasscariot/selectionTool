/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/16 16:19:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_exit(int i)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
	exit(i);
}

int		main(int ac, char **av, char **env)
{
	char		buffer[3];
	t_files		*files;
	int			cursor;
	int			maxlen;

	(void)ac;
	(void)env;
	cursor = 0;
	files = ft_save(av);
	maxlen = ft_list_len(files);
	if (!files)
	{
		ft_putstr("genius..\n");
		return (0);
	}
	ft_can();
	ft_aff(files, cursor, maxlen);
	while (read(0 , buffer, 3))
	{
		if (ft_key_hook(buffer, &cursor, maxlen))
		{
			ft_check(files, cursor);
			ft_inc_cursor(&cursor, maxlen, 0);
		}
		ft_aff(files, cursor, maxlen);
	}
	return (0);
}
