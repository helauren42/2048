/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:23:40 by helauren          #+#    #+#             */
/*   Updated: 2023/05/15 15:35:47 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_createnew(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*newnode;
	t_list	*head;

	nlst = ft_createnew();
	if (!nlst)
		return (NULL);
	head = nlst;
	while (lst != NULL)
	{
		newnode = ft_createnew();
		if (!newnode)
		{
			del(nlst);
			return (NULL);
		}
		head->content = f(lst->content);
		head->next = newnode;
		head = head->next;
		lst = lst->next;
	}
	head->next = NULL;
	return (nlst);
}

// void *append_lol(void *str)
// {
// 	char    *lolstring;
// 	int 	i;

// 	i = 0;
// 	lolstring = malloc(sizeof(char) * ft_strlen((char *)str) + 5);
// 	while (((char *)str)[i])
// 	{
// 		lolstring[i] = ((char *)str)[i];
// 		i++;
// 	}
// 	lolstring[i++] = ' ';
// 	lolstring[i++] = 'l';
// 	lolstring[i++] = 'o';
// 	lolstring[i++] = 'l';
// 	lolstring[i++] = 0;
// 	return (lolstring);
// }

// void delete(void *head)
// {
// 	if (((t_list *) head)->next != NULL)
// 		delete(((t_list *) head)->next);
// 	((t_list *) head)->content = NULL;
// }

// void delete_content(void *head)
// {
// 	if (((t_list *) head)->next != NULL)
// 		delete_content(((t_list *) head)->next);
// 	free(((t_list *) head)->content);
// 	((t_list *) head)->content = NULL;
// }

// int main(void)
// {
// 	t_list *nlist;
// 	t_list *list;
// 	t_list *new;
// 	t_list *newest;
// 	char *new_str;

// 	list = ft_lstnew("node 3");
// 	new = ft_lstnew("node 2");
// 	newest = ft_lstnew("node 1");
// 	ft_lstadd_front(&list, new);
// 	ft_lstadd_front(&list, newest);

// 	printf("%s\n", (char *) list->content);
// 	printf("%s\n", (char *) list->next->content);
// 	printf("%s\n", (char *) list->next->next->content);
// 	nlist = ft_lstmap(list, &append_lol, &delete);
// 	printf("%s\n", (char *) nlist->content);
// 	printf("%s\n", (char *) nlist->next->content);
// 	printf("%s\n", (char *) nlist->next->next->content);

// 	delete(list);
// 	delete_content(nlist);
// 	return (0);
// }