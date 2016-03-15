/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/15 23:33:54 by lucas            ###   ########.fr       */
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

	(void)ac;
	(void)env;
	cursor = 0;
	files = ft_save(av);
	ft_can();
	ft_aff(files, cursor);
	while (read(0 , buffer, 3))
	{
		if (ft_key_hook(buffer, &cursor))
			ft_putstr("Check\n");
		ft_aff(files, cursor);
	}
	return (0);
}
