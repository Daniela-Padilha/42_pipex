/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:53:59 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/01 15:44:17 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Allocate and return a new node
//content --> Ptr to the content to creat the new node with
//return  --> Success (ptr to new node)

t_list	*ft_lstnew(void *content)
{
	t_list	*mynode;

	mynode = (t_list *)malloc(sizeof(t_list));
	if (!mynode)
		return (NULL);
	mynode->content = content;
	mynode->next = NULL;
	return (mynode);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*first_node;
// 	t_list	*scd_node;
// 	char	*content;
// 	content = "Hello";
// 	first_node = ft_lstnew(content);
// 	printf("content was set to: %s\n", content);
// 	content = "World";
// 	scd_node = ft_lstnew(content);
// 	first_node->next = scd_node;
// 	//Print the content of the first node
// 	printf("first node->content: %s\n", (char *)first_node->content);
// 	printf("first_node->next: %p\n\n", (void *)first_node->next);
// 	//Print the second node
// 	printf("content was set to: %s\n", content);
// 	printf("second_node->content: %s\n", (char *)scd_node->content);
// 	printf("second_node->next: %p\n", (void *)scd_node->next);
// 	//Free alocated node
// 	free(first_node);
// 	free(scd_node);
// 	return (0);
// }
