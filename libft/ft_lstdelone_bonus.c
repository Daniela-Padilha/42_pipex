/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:55:53 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 13:10:14 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Frees the memory of the node using del
//lst     --> The node to free
//del     --> Ptr to the function used to delete the content

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

// static void	ft_delete(void *data)
// {
// 	free(data);
// }

// #include <stdio.h>
// #include <string.h>
// #include "ft_lstnew.c"
// int	main(void)
// {
// 	t_list	*first_node;
// 	t_list	*scd_node;
// 	char	*content;

// 	content = malloc(6);
// 	strcpy(content, "Hello");
// 	first_node = ft_lstnew(content);
// 	content = malloc(6);
// 	strcpy(content, "World");
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
// 	ft_lstdelone(scd_node, ft_delete);
// 	//After ft_lstdelone
// 	printf("	--AFTER--\n\n");
// 	printf("	first_node\n");
// 	printf("node address: %p\n", first_node);
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
//  	printf("    second_node (deleted)\n");
//     printf("node address: %p\n", (void *)scd_node);
//     printf("content: [DELETED]\n");
//     printf("next: %p\n\n", (void *)scd_node->next);
//     // Free the node
// 	free(first_node->content);
// 	free(first_node);
//     return 0;
// }
