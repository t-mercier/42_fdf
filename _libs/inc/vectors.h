/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_linkedlist.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:18:04 by tmercier      #+#    #+#                 */
/*   Updated: 2022/10/16 20:57:11 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

/*
 * len : Vector real length
 * size : Vector max size
 * esz : Element size
 */

typedef struct s_vector
{
	void	*data;
	size_t	cap;
	size_t	len;
	size_t	esz;
}			t_vector;

typedef int (*t_f_compare)(void *a, void *b);

static inline size_t min(size_t a, size_t b) {
	if (a > b)
		return (b);
	return (a);
}

t_vector *ft_vector_create(size_t esz);
t_vector	*vector_init(size_t size);
void		vector_append(t_vector *v, void *x);
void		free_vector(t_vector *v);
ssize_t ft_vector_indexof(t_vector *v, void *e, t_f_compare cmp);
void ft_vector_concat(t_vector *v, void *d, size_t n);
t_vector *ft_vec_concat_str(t_vector *v, char *s);
void ft_vector_destroy(t_vector *v);
void *ft_vector_set(t_vector *v, size_t i, void *el);
void *ft_vector_push(t_vector *v, void *el);
void *ft_vector_pop(t_vector *v);
void ft_vector_swap(t_vector *v, int a, int b);
t_vector *ft_vector_copy(t_vector *v);
void *ft_vector_get(t_vector *v, int i);
void ft_vector_grow(t_vector *v, size_t n);


#endif
