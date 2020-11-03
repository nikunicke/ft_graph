/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:59:05 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/03 15:10:36 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H
# include "libft.h"
# define IDENT_MAX 256

typedef struct		s_adjlist
{
	t_list			**list;
	int				size;
	int				used;
}					t_adjlist;

typedef struct		s_graph
{
	t_adjlist		adj;
	size_t			vertices;
}					t_graph;

typedef struct		s_node
{
	void			*id;
	int				i;
	int				x;
	int				y;
	int				in;
	int				token;
}					t_node;

typedef struct		s_edge
{
	t_node			*from;
	t_node			*to;
	int				capacity;
	int				flow;
	struct s_edge	*residual;
}					t_edge;

t_graph				*init_graph(size_t vertices);
t_adjlist			*to_adj(t_graph *g);
t_node				*new_node(void *id);
size_t				get_node_index(t_node *n);
int					add_edge(t_graph *g, t_node *s, t_node *d);
void				hello(void);

#endif