/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:51:31 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/04 01:24:20 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	s_signal(int signo, void *handler, bool use_siginfo);
int		ft_atoi(const char *nptr);
void	k_kill(pid_t pid, int signum, int n);
void	*ft_memset(void *s, int c, size_t n);
#endif
