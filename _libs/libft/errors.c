/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_errors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 10:48:50 by tmercier      #+#    #+#                 */
/*   Updated: 2022/11/13 10:48:50 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	exit_message(char *s, int code)
{
	ft_printf("%s%s", RED, s);
	exit(code);
}

void message_perror(char *msg) {
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	perror("");
}

void exit_perror(char *msg, int code) {
	message_perror(msg);
	exit(code);
}
