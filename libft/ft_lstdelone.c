/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:58:28 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 14:58:28 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	del(void *something)
// {
// 	free(something);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
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

//     printf("%s\n", (char *)(two->content));
//     printf("%s\n", (char *)(three->content));
//     ft_lstdelone(one, &del);

//     free(two->content);
//     free(three->content);
//     free(two);
//     free(three);
// }