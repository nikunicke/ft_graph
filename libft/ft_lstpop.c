/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:32:29 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/02 17:05:00 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	*head = tmp->next;
	free(tmp->content);
	tmp->content = NULL;
	free(tmp);
	tmp = NULL;
}
