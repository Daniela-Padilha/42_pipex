/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:58:50 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 15:38:26 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Deletes and frees the memory of the whole list
//lst     --> A ptr to a node
//del     --> A ptr to the function used to delete the content

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// static void	ft_delete(void *data)
// {
// 	free(data);
// }

// #include <stdio.h>
// #include <string.h>
// #include "ft_lstnew.c"
// #include "ft_lstdelone.c"
// int	main(void)
// {
// 	t_list	*first_node;
// 	char	*content;

// 	content = malloc(6);
// 	strcpy(content, "Hello");
// 	first_node = ft_lstnew(content);
// 	first_node->next = NULL;
// 	//Print the content of the first node
// 	printf("	--BEFORE--\n\n");
// 	printf("	first_node\n");
// 	printf("node address: %p\n", first_node);
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
// 	ft_lstclear(&first_node, ft_delete);
// 	//After ft_lstdelone
// 	printf("	--AFTER--\n\n");
// 	printf("	first_node (deleted)\n");
// 	printf("node address: %p\n", (void *)first_node);
// 	printf("content: [DELETED]\n");
// 	printf("next: %p\n\n", (void *)first_node);

// }
