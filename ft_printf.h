/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kziari <kziari@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:48:32 by kziari            #+#    #+#             */
/*   Updated: 2023/11/20 15:47:53 by kziari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_str_print(int length, const char *str);
int		ft_dec_print(int length, int num);
int		ft_hex_print(int length, unsigned int hex, char c);
int		ft_ptr_print(int length, unsigned long long hex);
int		ft_u_print(int length, unsigned int ui);
int		ft_char_print(int length, char c);
char	*ft_hextoa(unsigned long long hex, char c);
char	*ft_uitoa(unsigned int n);
int		ft_format(int length, va_list args, char c);
int		ft_printf(const char *str, ...);

#endif
