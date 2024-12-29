/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:34 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/02 16:27:31 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info   --> Allocate unused memory
//nmemb  --> Array of n elements
//size   --> Size in bytes of each element
//return --> Success (Pointer to the allocated memory)
//return --> Failure (NULL)

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;
	size_t	i;
	char	*ptr_c;

	if ((nmemb == 0) || (size == 0))
	{
		nmemb = 1;
		size = 0;
	}
	total = (nmemb * size);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ptr_c = (char *)ptr;
	i = 0;
	while (i < total)
	{
		ptr_c[i] = '\0';
		i++;
	}
	ptr = (void *)ptr_c;
	return (ptr);
}

// #include "ft_bzero.c"

// int	main(void)
// {
//     int *a;
//     int *b;
//     int i;
//     int n;

//     a = (int *)ft_calloc(n, sizeof(int));
//     b = (int *)calloc(n, sizeof(int));
//     i = 0;
//     n = 5;
//     while (i > n)
//     {
//         printf("ft_calloc[%i] = %i, calloc[%i] = %i\n", i, a[i], i, b[i]);
//         i++;
//     }
//     free(a);
//     free(b);
//     return (0);
// }
