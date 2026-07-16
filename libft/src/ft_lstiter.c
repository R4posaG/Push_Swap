/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:18:25 by hjacinto          #+#    #+#             */
/*   Updated: 2026/05/14 18:18:25 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((lst != NULL) && (f != NULL))
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
