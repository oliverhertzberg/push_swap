/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:56:55 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 20:34:00 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	clear_stack(t_stack **node)
{
	t_stack	*current;
	t_stack	*previous;

	current = *node;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}

void	node_insert_end(t_stack **node, int num, char **temp_array)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_double_pointer_array(temp_array);
		clear_stack(node);
		exit(1);
	}
	new_node->next = NULL;
	new_node->num = num;
	current = *node;
	if (!current)
	{
		*node = new_node;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	init_stack_a(int argc, char **argv, t_stack **stack_a, int *total)
{
	int		i;
	int		num;
	char	**temp_array;

	i = -1;
	if (argc == 1)
	{
		temp_array = ft_split(*argv, ' ');
		while (temp_array[++i])
		{
			num = ft_atoi(temp_array[i]);
			node_insert_end(stack_a, num, temp_array);
		}
		free_double_pointer_array(temp_array);
	}
	else
	{
		while (argv[++i])
		{
			num = ft_atoi(argv[i]);
			node_insert_end(stack_a, num, NULL);
		}
	}
	*total = i;
	update_positions(stack_a);
}

void	choose_algorithm(t_stack **a, t_stack **b, int *total)
{
	if (*total == 1 || is_sorted(*a))
		return ;
	else if (*total == 2)
		double_sort(a);
	else if (*total == 3)
		triple_sort(a);
	else if (*total <= 5)
		inefficient_sort(a, b, total);
	else
		efficient_sort(a, b, total);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total;

	total = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	check_arguments(argc - 1, argv + 1);
	init_stack_a(argc - 1, argv + 1, &stack_a, &total);
	choose_algorithm(&stack_a, &stack_b, &total);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
