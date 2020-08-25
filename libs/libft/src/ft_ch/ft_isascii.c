/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:17:13 by sbecker           #+#    #+#             */
/*   Updated: 2018/11/27 17:49:55 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int ch)
{
	return (ch >= 0 && ch <= 127);
}
