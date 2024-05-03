/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:58:37 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 14:58:37 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *str)
// {
// 	char	*s;
// 	int		i;

// 	i = 0;
// 	s = (char *)(str);
// 	while (s[i] != 0)
// 	{
// 		printf("char = %c\n", s[i]);
// 		s[i] = s[i] - 32;
// 		i++;
// 	}
// }

// int main(void)
// {
//     t_list  *one;
//     t_list  *two;
//     t_list  *three;

//     one = malloc(sizeof(t_list));
//     two = malloc(sizeof(t_list));
//     three = malloc(sizeof(t_list));

//     one->content = strdup("weufner");
//     one->next = two;
//     two->content = strdup("wioengfer");
//     two->next = three;
//     three->content = strdup("eourhtort");
//     three->next = NULL;

//     ft_lstiter(one, &f);
//     printf("%s\n", (char *)(one->content));
//     printf("%s\n", (char *)(two->content));
//     printf("%s\n", (char *)(three->content));

//     free(one->content);
//     free(two->content);
//     free(three->content);
//     free(one);
//     free(two);
//     free(three);
// }