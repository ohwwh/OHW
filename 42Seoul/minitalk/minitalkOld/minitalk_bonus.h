/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:43:03 by hoh               #+#    #+#             */
/*   Updated: 2022/05/31 17:43:43 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include "libohw/includes/libft.h"
# include "libohw/includes/ft_printf.h"

typedef struct s_global_set {
	sig_atomic_t	length;
	sig_atomic_t	state;
	sig_atomic_t	ch;
	char			*str;
	sig_atomic_t	old;
	sig_atomic_t	pid;
	sig_atomic_t	k;
	sig_atomic_t	erno;
}t_global_set;

#endif
