/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:25:23 by npimenof          #+#    #+#             */
/*   Updated: 2020/10/06 18:12:06 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

inline t_adjlist *to_adj(t_graph *g)
{
	return ((t_adjlist *)g);
}

size_t		get_node_index(t_node *n)
{
	return (n->i);
}

t_edge		*new_edge(t_node *from, t_node *to, int capacity)
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

t_node	*new_node(void *id)
{
	t_node	*node;
	static size_t	i;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->id = id;
	node->i = i;
	node->x = 0;
	node->y = 0;
	i++;
	return (node);
}

t_adjlist	init_adjlist(size_t s)
{
	t_adjlist	adj;

	if (!(adj.list = malloc(sizeof(t_list *) * s)))
		return adj;
	ft_bzero(adj.list, s);
	adj.size = s;
	adj.used = 0;
	return (adj);
}

t_graph	*init_graph(int vertices)
{
	t_graph	*g;

	if (!(g = malloc(sizeof(t_graph))))
		return (NULL);
	g->adj = init_adjlist(vertices);
	if (!(to_adj(g)->list))
		return (NULL);
	g->vertices = vertices;
	return (g);
}

int		add_edge(t_graph *g, t_node *s, t_node *d)
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

void	hello(void)
{
	printf("Hello World\n");
}