/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: asaijers <asaijers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:56:49 by asaijers      #+#    #+#                 */
/*   Updated: 2022/11/29 13:55:29 by asaijers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/vectors.h"

t_vector *ft_vector_create(size_t esz) {
  t_vector *v;

  v = ft_malloc(sizeof(t_vector));
  if (!v)
    return (0);
  v->len = 0;
  v->cap = 2;
  v->esz = esz;
  v->data = ft_calloc(v->cap, v->esz);
  if (!v->data) {
    free(v);
    return (0);
  }
  return (v);
}

static size_t _round_up_to_multiple_of_2(size_t v) {
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v |= v >> 32;
  return (++v);
}

void ft_vector_grow(t_vector *v, size_t n) {
  if (!v || v->len + n < v->cap)
    return;
  v->cap = _round_up_to_multiple_of_2(v->len + n);
  v->data = ft_realloc(v->data, v->esz * v->cap, v->len * v->esz);
}
