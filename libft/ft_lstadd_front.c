/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:50:38 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 17:37:02 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	t_list *new;
// 	t_list  *list;

// 	list = (t_list *)0x1234;
// 	list = malloc(sizeof(t_list));
// 	new = malloc(sizeof(t_list));

// 	(*list).content = "fwuebfe";
// 	list->next = NULL;
// 	new->content = "ewnuewtr";
// 	new->next = NULL; 
// 	ft_lstadd_front(&list, new);
// }