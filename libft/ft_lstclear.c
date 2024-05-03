/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:35:01 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 17:35:01 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typedef struct s_list
// {
//     void            *content;
//     struct s_list   *next;
// }                   t_list;

// void    del(void *something)
// {
//     free(something);
// }

// void ft_lstdelone(t_list *lst, void (*del)(void*))
// {
//     if (lst == NULL)
//         return ;
//     del(lst->content);
//     free(lst);
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*second;

	if (lst == NULL || del == NULL)
		return ;
	second = *lst;
	while (*lst != NULL)
	{
		second = second->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = second;
	}
	*lst = NULL;
}

// int main(void)
// {
//     t_list  *one;
//     t_list  *two;
//     t_list  *three;

//     one = malloc(sizeof(t_list));
//     two = malloc(sizeof(t_list));
//     three = malloc(sizeof(t_list));

//     one->content = strdup("abc");
//     one->next = two;
//     two->content = strdup("def");
//     two->next = three;
//     three->content = strdup("ghi");
//     three->next = NULL;

//     printf("%s\n", (char *)(one->content));
//     printf("Here");
//     ft_lstclear(&two, &del);

//     free(one->content);
//     free(one);
// }