/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:50:13 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/01 15:46:10 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Count the number of elements in a list
//lst     --> Ptr to the beginning of the list
//return  --> Success (list length)

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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
// 	printf("first node->content: %s\n", (char *)first_node->content);
// 	printf("first_node->next: %p\n\n", (void *)first_node->next);
// 	//Print the second node
// 	printf("second_node->content: %s\n", (char *)scd_node->content);
// 	printf("second_node->next: %p\n\n", (void *)scd_node->next);
// 	//Print the size of the list
// 	printf("list size: %i\n", ft_lstsize(first_node));
// 	//Free alocated node
// 	free(first_node);
// 	free(scd_node);
// 	return (0);
// }
