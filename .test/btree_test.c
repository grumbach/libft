/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:12:16 by agrumbac          #+#    #+#             */
/*   Updated: 2018/06/26 19:00:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdbool.h>
#include "libft.h"
#include "ft_printf.h"

/*
** --------> GO TO THE BOTTOM OF THIS FILE !!
*/

/*
** ------------------------------- malloc and free -----------------------------
*/

void					*g_allocs[42];//array containing all allocations
int						g_allocs_i = 0;
void					*g_last_freed = 0;

int						sum_allocs()//counts number of live allocations
{
	int sum = 0;
	for (size_t i = 0; i < 42; i++)
	{
		sum += !!g_allocs[i];
	}
	return (sum);
}

void					watch_free(void *p)
{
	g_last_freed = p;
	for (size_t i = 0; i < 42; i++)
	{
		if (g_allocs[i] == p)
		{
			free(p);
			g_allocs[i] = 0;
			return;
		}
	}
	assert(false);//assert never read this code
}

void					*watch_malloc(size_t size)
{
	void * ptr = ft_memalloc(size);
	g_allocs[g_allocs_i++] = ptr;
	return (ptr);
}

/*
** ------------------------------- tree funcs ----------------------------------
*/

typedef struct			s_test_btree
{
	struct s_test_btree		*left;   //struct s_btree	* left
	struct s_test_btree		*right;  //struct s_btree	* right
	char					*value;
	int						token;
	int						reserved;
}						t_test_btree;

t_test_btree			*g_tree;//Global tree used for tests

t_test_btree			*generate_n_tree(int n)
{
	t_test_btree		*root;

	root = watch_malloc(sizeof(*root));
	if (n > 0)
	{
		root->left = generate_n_tree(n - 1);
		root->right = generate_n_tree(n - 1);
	}
	root->token = 42;
	root->reserved = n;
	return (root);
}

void					build_tree()
{
	ft_bzero(&g_allocs, sizeof(g_allocs));
	g_tree = generate_n_tree(3);
}

void					count_tree(t_test_btree *a)
{
	static int i = 0;

	a->token = i++;
}

void					check_count_tree(t_test_btree *a)
{
	static int i = 0;

	assert(a->token == i++);
}

int						cmp_tree(t_test_btree *a, t_test_btree *b)
{
	return !(a->token == b->token);
}

void					print_tree(t_test_btree *a)//Wunused
{
	ft_printf("\n{%p}[%d]", a, a->token);
}

/*
** ------------------------------- tests ---------------------------------------
*/

bool		test_ft_btree_find()
{
	t_test_btree		*mpinson = g_tree->right->left->right;
	t_test_btree		cheater = {0, 0, 0, -42, 0};
	t_test_btree		*found;

	mpinson->token = -42;
	found = ft_btree_find(g_tree, &cheater, &cmp_tree);
	assert(found == mpinson);

	cheater.token = -2;
	found = ft_btree_find(g_tree, &cheater, &cmp_tree);
	assert(found == NULL);
	return (true);
}

bool		test_ft_btree_iter()
{
	ft_btree_iter(g_tree, &count_tree);
	ft_btree_iter(g_tree, &check_count_tree);
	return (true);
}

bool		test_ft_btree_del()
{
	void *target = g_tree->left->left->left;
	ft_btree_del(&g_tree->left->left->left, &watch_free);
	assert(g_tree->left->left->left == NULL);
	assert(g_last_freed == target);
	return (true);
}

bool		test_ft_btree_recursivedel()
{
	void *target = g_tree;

	ft_btree_recursivedel(&g_tree, &watch_free);
	assert(g_tree == NULL);
	assert(g_last_freed == target);
	assert(sum_allocs() == 0);
	return (true);
}

/*
** ------------------------------- MAIN ----------------------------------------
*/

# define TEST(func) \
	ft_printf("| Tests  %42s  ", #func); \
	ft_printf("%s |\n", test_ ## func() ? "✅" : "");

int			main(void)
{
	ft_printf(" ------------------ ft_btree Tests --------------------  \n");

	build_tree();
	TEST(ft_btree_find)
	TEST(ft_btree_iter)
	TEST(ft_btree_del)
	TEST(ft_btree_recursivedel)

	ft_printf(" ------------------------------------------------------ \n");
	return (0);
}
