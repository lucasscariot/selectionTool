/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:58 by lucas             #+#    #+#             */
/*   Updated: 2016/04/01 16:29:35 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av, char **env)
{
	char		buffer[3];

	(void)ac;
	g_cursor = 0;
	g_files = ft_save(av);
	g_maxlen = ft_list_len(g_files);
	if (!g_files)
		ft_exit(4);
	ft_signal();
	ft_secure(env);
	ft_can();
	ft_aff(g_files, g_cursor);
	while (read(0, buffer, 3))
	{
		g_maxlen = ft_list_len(g_files);
		ft_key_hook(g_files, buffer, &g_cursor, g_maxlen);
		ft_aff(g_files, g_cursor);
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
	}
	return (0);
}
