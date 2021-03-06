/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:25:23 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/19 16:14:07 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static t_edge		*new_edge(t_node *from, t_node *to, int capacity)
{
	t_edge	*edge;

	if (!(edge = malloc(sizeof(t_edge))))
		return (NULL);
	edge->from = from;
	edge->to = to;
	edge->capacity = capacity;
	edge->flow = 0;
	edge->residual = NULL;
	return (edge);
}

t_node				*new_node(void *id)
{
	static size_t	i;
	t_node			*node;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->id = id;
	node->i = i;
	node->x = 0;
	node->y = 0;
	node->token = 0;
	node->in = 0;
	i++;
	return (node);
}

static t_adjlist	init_adjlist(size_t s)
{
	t_adjlist	adj;

	if (!(adj.list = ft_memalloc(sizeof(t_list *) * s)))
		return (adj);
	adj.size = s;
	adj.used = 0;
	return (adj);
}

t_graph				*init_graph(size_t vertices)
{
	t_graph	*g;

	if (!(g = ft_memalloc(sizeof(t_graph))))
		return (NULL);
	g->adj = init_adjlist(vertices);
	if (!(((t_adjlist *)g)->list))
		return (NULL);
	g->vertices = vertices;
	return (g);
}

int					add_edge(t_graph *g, t_node *s, t_node *d)
{
	t_adjlist	*a;
	t_edge		*to;
	t_edge		*from;

	if (!g || !s || !d)
		return (0);
	if (!(to = new_edge(s, d, 1)))
		return (0);
	if (!(from = new_edge(d, s, 1)))
		return (0);
	from->residual = to;
	to->residual = from;
	a = (t_adjlist *)g;
	ft_lstadd(&a->list[s->i], ft_lstcontent(to));
	ft_lstadd(&a->list[d->i], ft_lstcontent(from));
	return (0);
}
