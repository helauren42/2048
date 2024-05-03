/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:46:06 by tzanchi           #+#    #+#             */
/*   Updated: 2024/04/05 21:40:16 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isspace returns 1 if character c is a space. Space includes space,
form-feed\f, new line \n, carriage return \r, horizontal tab \t and  vertical
tab\v*/
int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
