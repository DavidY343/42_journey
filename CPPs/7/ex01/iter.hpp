/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:16:47 by david             #+#    #+#             */
/*   Updated: 2025/08/12 20:16:48 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void iter(T *array, size_t length, F func)
{
	if (!array || length == 0)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
