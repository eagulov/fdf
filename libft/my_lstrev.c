/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:40:45 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/02 18:03:06 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_lstrev(t_list **alst)
{
	t_list *prev;
	t_list *cur;
	t_list *next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}
