/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:03:45 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/05 16:07:13 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Iterates the list and applies f, creating a new list. 
//            Deletes the content of a node if needed.
//lst     --> Ptr to the node to iterate
//f       --> Ptr to the function used to iterate the list
//del     --> Ptr to the function used to delete the content of a node
//return  --> Ptr to the new list

static t_list	*ft_lstcreate(t_list *list, void *(*f)(void *),
					void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*head;

	new_l = ft_lstcreate(lst, f, del);
	if (!new_l)
		return (NULL);
	head = new_l;
	lst = lst->next;
	while (lst)
	{
		new_l->next = ft_lstnew(f(lst->content));
		if (!new_l->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_l = new_l->next;
		lst = lst->next;
	}
	new_l->next = NULL;
	return (head);
}

static t_list	*ft_lstcreate(t_list *list, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*new_l;
	void	*content;

	if (!list || !f || !del)
		return (NULL);
	content = f(list->content);
	new_l = ft_lstnew(content);
	if (!new_l)
	{
		del(content);
		return (NULL);
	}
	return (new_l);
}

// static void	*ft_upper(void *content)
// {
// 	char	*str;
// 	int	i;

// 	str = (char *)content;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] >= 97 && str[i] <= 122)
// 		{
// 			str[i] -= 32;
// 		}
// 		i++;
// 	}
// 	return ((void *)str);
// }

// static void	ft_delete(void *data)
// {
// 	free(data);
// }

// #include <stdio.h>
// #include <string.h>
// #include "ft_lstnew.c"
// #include "ft_lstclear.c"
// #include "ft_lstdelone.c"
// #include "ft_strlen.c"
// int	main(void)
// {
// 	t_list	*first_node;
// 	t_list	*scd_node;
// 	t_list	*new_node;
// 	char	*content;

// 	content = malloc(6);
// 	strcpy(content, "hello");
// 	first_node = ft_lstnew(content);
// 	content = malloc(6);
// 	strcpy(content, "world");
// 	scd_node = ft_lstnew(content);
// 	first_node->next = scd_node;
// 	//Print the content of the first node
// 	printf("	--BEFORE--\n\n");
// 	printf("	first_node\n");
// 	printf("node address: %p\n", first_node);
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
// 	//Print the second node
// 	printf("	second_node\n");
// 	printf("node address: %p\n", scd_node);
// 	printf("content: %s\n", (char *)scd_node->content);
// 	printf("next: %p\n\n", (void *)scd_node->next);
// 	new_node = ft_lstmap(first_node, ft_upper, ft_delete);
// 	//After
// 	printf("	--AFTER--\n\n");
// 	printf("	first_node\n");
// 	printf("node address: %p\n", first_node);
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
//  	printf("    second_node\n");
//     printf("node address: %p\n", (void *)scd_node);
//     printf("content: %s\n", (char *)scd_node->content);
//     printf("next: %p\n\n", (void *)scd_node->next);
//  	printf("    new_node\n");
//     printf("node address: %p\n", (void *)new_node);
//     printf("content: %s\n", (char *)new_node->content);
//     printf("next: %p\n\n", (void *)new_node->next);
//     // Free the node
// 	free (first_node);
// 	free (scd_node);
// 	free (new_node);
//     return 0;
// }
