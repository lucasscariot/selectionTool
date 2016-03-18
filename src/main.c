/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 09:14:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	char		buffer[3];
	t_files		*files;
	int			cursor;
	int			maxlen;

	(void)ac;
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
		ft_key_hook(files, buffer, &cursor, maxlen);
		ft_aff(files, cursor, maxlen);
		printf("%d %d %d\n", buffer[0], buffer[1], buffer[2]);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
