/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:22:34 by lucas             #+#    #+#             */
/*   Updated: 2016/03/15 10:42:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_aff(char **av, char **env)
{
	int	i;

	i = 1;
	system("clear");
	(void)env;
	while (av[i])
		ft_putendl(av[i++]);
	return (i);
}