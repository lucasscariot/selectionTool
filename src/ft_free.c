/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:10:39 by lucas             #+#    #+#             */
/*   Updated: 2016/03/18 11:30:31 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_free_one(t_files *var)
{
	free(var->name);
}

void	ft_free_list(t_files *var)
{
	t_files	*next;

	while (var != NULL)
	{
		next = var->next;
		ft_free_one(var);
		free(var);
		var = next;
	}
}
