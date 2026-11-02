/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_skip_n.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:53:50 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/22 15:55:13 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_SKIP_N_H
# define CREATE_SKIP_N_H

typedef struct s_skip_n
{
	size_t		skip;
	size_t		idx;
	t_stream	*source;
}	t_skip_n;

#endif
