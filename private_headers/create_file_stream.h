/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_stream.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:56:00 by cgrarock          #+#    #+#             */
/*   Updated: 2026/11/02 10:53:25 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "streams.h"

typedef struct s_file_context
{
	int		file_id;
	size_t	buffer_size;
	char	*buffer;
	size_t	last_read;
	size_t	idx;
	void	(*on_destruct)(int fd);
}	t_file_context;
