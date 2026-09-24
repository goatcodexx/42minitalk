/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 21:02:49 by sywee             #+#    #+#             */
/*   Updated: 2026/09/24 21:23:28 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char *av[])
{
    (void)av;
    (void)ac;
    int pid;
    
    pid = getpid();
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putstr_fd("\n", 1);
}