/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:02:25 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/07 18:42:34 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_lstadd_end(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}
