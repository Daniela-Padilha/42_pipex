/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:47:02 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/01 15:44:41 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Adds new node to the beginning of the list
//lst     --> Ptr to the first link of a list
//new     --> Ptr to the node to be added

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// #include "ft_lstnew.c"
// int	main(void)
// {
// 	t_list	*first_node;
// 	t_list	*scd_node;
// 	t_list	*new_node;
// 	char	*content;

// 	content = "Hello";
// 	first_node = ft_lstnew(content);
// 	content = "World";
// 	scd_node = ft_lstnew(content);
// 	first_node->next = scd_node;
// 	content = "!!!";
// 	new_node = ft_lstnew(content);
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
// 	//Add the new node
// 	printf("	new_node\n");
// 	printf("node address: %p\n", new_node);
// 	printf("content: %s\n", (char *)new_node->content);
// 	printf("next: %p\n\n", (void *)new_node->next);
// 	//Implement function
// 	ft_lstadd_front(&first_node, new_node);
// 	//After ft_lstadd_front
// 	printf("	--AFTER--\n\n");
// 	//Add the new node
// 	printf("	new_node\n");
// 	printf("node address: %p\n", first_node);
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
// 	printf("	first_node\n");
// 	printf("node address: %p\n", first_node->next);
// 	printf("content: %s\n", (char *)first_node->next->content);
// 	printf("next: %p\n\n", (void *)first_node->next->next);
// 	//Print the second node
// 	printf("	second_node\n");
// 	printf("node address: %p\n", scd_node);
// 	printf("content: %s\n", (char *)scd_node->content);
// 	printf("next: %p\n\n", (void *)scd_node->next);
// 	//Free alocated nodes
// 	free(first_node);
// 	free(scd_node);
// 	return (0);
// }
