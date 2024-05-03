/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:58:43 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 14:58:43 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int main(void)
// {
//     t_list  *one;
//     t_list  *two;
//     t_list  *three;
//     t_list  *print;

//     print = malloc(sizeof(t_list));
//     one = malloc(sizeof(t_list));
//     two = malloc(sizeof(t_list));
//     three = malloc(sizeof(t_list));

//     one->content = strdup("weufner");
//     one->next = two;
//     two->content = strdup("wioengfer");
//     two->next = three;
//     three->content = strdup("eourhtort");
//     three->next = NULL;

//     print = ft_lstlast(one);
//     printf("last = %s\n", (char *)print->content);

//     // free (print->content);
//     // free(print);

//     free (one->content);
//     free(one);
//     free (two->content);
//     free(two);
//     free (three->content);
//     free(three);
// }