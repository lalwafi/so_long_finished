/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:18:57 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 22:50:43 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthex(unsigned long arg, char x);
int	ft_putnbr(int n);
int	ft_putptr(void *arg);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);

#endif