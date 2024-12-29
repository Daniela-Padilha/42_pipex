/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:56 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/01 15:39:56 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Add the new node at the end of the list
//lst     --> Ptr to the first link of a list
//new     --> Ptr to the node to be added

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

// #include <stdio.h>
// #include "ft_lstnew.c"
// #include "ft_lstlast.c"
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
// 	ft_lstadd_back(&first_node, new_node);
// 	//After ft_lstadd_back
// 	printf("	--AFTER--\n\n");
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
// 	//Free alocated nodes
// 	free(first_node);
// 	free(scd_node);
// 	free(new_node);
// 	return (0);
// }
