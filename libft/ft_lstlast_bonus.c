/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:14 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/01 15:01:08 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Return the last node of the list
//lst     --> The beginning of the list
//return  --> Success (last node)

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>
// #include "ft_lstnew.c"
// int	main(void)
// {
// 	t_list	*first_node;
// 	t_list	*scd_node;
// 	char	*content;

// 	content = "Hello";
// 	first_node = ft_lstnew(content);
// 	content = "World";
// 	scd_node = ft_lstnew(content);
// 	first_node->next = scd_node;
// 	//Print the content of the first node
// 	printf("	first_node\n");
// 	printf("content: %s\n", (char *)first_node->content);
// 	printf("next: %p\n\n", (void *)first_node->next);
// 	//Print the second node
// 	printf("	second_node\n");
// 	printf("content: %s\n", (char *)scd_node->content);
// 	printf("next: %p\n\n", (void *)scd_node->next);
// 	//Print only the last node
// 	printf("last node of the list: %p\n", ft_lstlast(first_node));
// 	//Free alocated node
// 	free(first_node);
// 	free(scd_node);
// 	return (0);
// }
