/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 21:02:49 by sywee             #+#    #+#             */
/*   Updated: 2026/09/29 19:34:17 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data  g_data = {7, 0, 0};

void    sighandler(int sig, siginfo_t *info, void *text)
{
    (void)text;
    if (info->si_pid != g_data.pid)
    {
        g_data.pid = info->si_pid;
        g_data.bit = 7;
        g_data.c = 0;
    }
    // bits start with all 0 , so just pass binary 1 will do
    if (sig == SIGUSR1)
        g_data.c |= (1 << g_data.bit);
    g_data.bit--;
    // upon passing all the bits, can convert to character bc collected all 8 bits
    if (g_data.bit < 0)
    {
        if (g_data.c == '\0')
            ft_putstr_fd("\n", 1);
        else
            ft_putchar_fd(g_data.c, 1);
        g_data.c = 0;
        g_data.bit = 7;
    }
}

int main(void)
{
    int                 pid;
    struct sigaction    sa;
    
    pid = getpid();
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr_fd(pid, 1);
    ft_putstr_fd("\n", 1);
    sa.sa_sigaction = sighandler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    
}