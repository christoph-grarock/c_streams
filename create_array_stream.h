/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_stream.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrarock <cgrarock@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:47:10 by cgrarock          #+#    #+#             */
/*   Updated: 2026/10/22 15:47:40 by cgrarock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ARRAY_STREAM_H
# define CREATE_ARRAY_STREAM_H

typedef struct s_arr_context
{
	void	*backing_arr;
	size_t	elem_size;
	size_t	elem_count;
	size_t	current_idx;
}	t_arr_context;

#endif
