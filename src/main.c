/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/24 00:18:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void sig_handler(int signo)
{
	if (signo == SIGWINCH)
		ft_aff(files, cursor, maxlen);
}

int		main(int ac, char **av)
{
	char		buffer[3];

	(void)ac;
	cursor = 0;
	files = ft_save(av);
	maxlen = ft_list_len(files);
	if (!files)
		ft_exit(4);
	signal(SIGWINCH, sig_handler);
	ft_can();
	ft_aff(files, cursor, maxlen);
	while (read(0 , buffer, 3))
	{
		maxlen = ft_list_len(files);
		ft_key_hook(files, buffer, &cursor, maxlen);
		ft_aff(files, cursor, maxlen);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
