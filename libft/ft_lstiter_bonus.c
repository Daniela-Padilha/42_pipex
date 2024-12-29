/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:01:47 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 15:06:46 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Iterate the list and apply f on each node
//lst     --> A ptr to a node
//f       --> A ptr to the function used to iterate the list

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// static void	ft_upper(void *content)
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
// }

// #include <stdio.h>
// #include <string.h>
// #include "ft_lstnew.c"
// #include "ft_strlen.c"
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
// 	ft_lstiter(first_node, ft_upper);
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
//     // Free the node
// 	free (first_node);
// 	free (scd_node);
//     return 0;
// }
