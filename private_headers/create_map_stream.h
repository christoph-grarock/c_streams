/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_stream.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:09:34 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/27 14:38:59 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"

typedef struct s_map
{
	void		*(*mapper)(void *);
	void		(*clear_mapper_elem)(void *);
	void		*last_elem;
	t_stream	*source;
}	t_map;
