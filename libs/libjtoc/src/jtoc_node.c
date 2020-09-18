/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtoc_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:46:35 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/05 23:38:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libjtoc.h"

static int	str_hash(const char *str)
{
	int	res;
	int	p;
	int	i;

	res = 0;
	p = 1;
	i = -1;
	while (str[++i])
	{
		res = (res + (str[i] - 'a') * p) % HASH_M;
		p = (p * HASH_P) % HASH_M;
	}
	return (res);
}

static int	get_next_hash(char **str)
{
	char	*dup;
	int		res;
	char	c;

	dup = *str;
	while (*dup && *dup != '.')
		++dup;
	c = 0;
	if (*dup)
	{
		c = *dup;
		*dup = '\0';
	}
	res = str_hash(*str);
	*str = c ? dup + 1 : dup;
	return (res);
}

t_jnode		*jtoc_node_create(enum e_type type, char *name, void *data)
{
	t_jnode	*res;

	if (!(res = (t_jnode *)malloc(sizeof(t_jnode))))
		return (NULL);
	res->type = type;
	res->name = ft_strdup(name);
	res->hash = str_hash(name);
	res->data = data;
	res->right = NULL;
	res->down = NULL;
	return (res);
}

void		jtoc_node_add_child(t_jnode *parent, t_jnode *child)
{
	t_jnode	*cur;

	if (!(parent->down))
	{
		parent->down = child;
		return ;
	}
	cur = parent->down;
	while (cur->right)
		cur = cur->right;
	cur->right = child;
}

t_jnode		*jtoc_node_get_by_path(t_jnode *parent, const char *path)
{
	t_jnode	*cur;
	char	*dupf;
	char	*dup;
	int		hash;

	if (!path || !parent || !(dup = ft_strdup(path)))
		return (NULL);
	dupf = dup;
	cur = parent;
	while ((hash = get_next_hash(&dup)) != 0)
	{
		cur = cur->down;
		while (cur && cur->hash != hash)
			cur = cur->right;
		if (!cur)
		{
			cur = NULL;
			break ;
		}
	}
	free(dupf);
	return (cur);
}

void		jtoc_node_clear(t_jnode *cur)
{
	if (cur->right)
		jtoc_node_clear(cur->right);
	if (cur->down)
		jtoc_node_clear(cur->down);
	free(cur->data);
	free(cur->name);
	free(cur);
}
