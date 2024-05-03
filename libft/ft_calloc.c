/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:35:58 by helauren          #+#    #+#             */
/*   Updated: 2023/05/16 15:41:02 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nelements, int size)
{
	void	*mem;

	mem = malloc(nelements * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nelements * size);
	return (mem);
}

// int	main()
// {

// }
