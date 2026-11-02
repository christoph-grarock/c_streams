/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_take_n.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:47:06 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/27 14:19:50 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"

typedef struct s_take_n
{
	size_t		take;
	size_t		idx;
	t_stream	*source;
}	t_take_n;
