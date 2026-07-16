/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjacinto <hjacinto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:18:12 by hjacinto          #+#    #+#             */
/*   Updated: 2026/05/14 18:18:12 by hjacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
t_list	*lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->content = content;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list *head = lstnew("First");
	head->next = lstnew("Second");
	head->next->next = ft_lstnew("Third");

	t_list *last = ft_lstlast(head);
	if (!last)
		return (1);
	
	t_list *tmp;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	return (0);
}
*/