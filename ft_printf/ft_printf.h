/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:24:29 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/09/19 00:44:31 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
 
int	ft_type(const char str, va_list args);
int	ft_printf(const char *string, ...);
int	ft_putchar_c(char c);
int	ft_putptr_c(void *ptr);

#endif