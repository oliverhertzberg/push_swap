/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:26 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 19:58:18 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct t_stack
{
	int				num;
	int				position;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

typedef struct s_variables
{
	t_stack	*current;
	t_stack	*min;
	t_stack	*max;
	t_stack	*top_node;
	t_stack	*bot_node;
	t_stack	*node_in_line;
	int		final_rb;
	int		num;
	int		length;
	int		return_ra;
	int		return_rb;
	bool	chunk_sorted;
	int		chunk_size;
	int		chunk_amt;
	int		len_stack;
	int		rotate_amt;
	int		start;
	int		end;
	int		last;
	int		i;
	int		total;
	int		node_position;
	int		*sorted_copy;
	int		top_cost;
	int		bot_cost;
	int		cost;
	bool	ra;
	bool	rb;
}	t_variables;

// Get Stuff
void	get_start_end_index(int *start, int *end, int total);
int		get_chunk_amt(int total);
t_stack	*get_max(t_stack *node);
int		get_last(t_stack *node);
t_stack	*get_last_node(t_stack *node);
void	get_sorted_copy(int *arr, int N, t_stack *a);
int		calculate_cost(t_stack **a, t_stack *node);

// Checker functions
void	check_arguments(int argc, char **argv);
int		is_sorted(t_stack *stack);
int		check_for_big_num(char *string);

// Stack Operations
void	ft_swap(t_stack **node);
void	ft_push(t_stack **push_from, t_stack **push_to);
void	ft_rotate(t_stack **node);
void	ft_reverse_rotate(t_stack **node);
void	update_positions(t_stack **a);
int		stack_len(t_stack **node);
void	final_rotation_b(int trb);
int		rotate_a(t_stack **a, int node_position);
int		rotate_b(t_stack **b);
t_stack	*get_top_node(t_stack **a, int sorted_copy[], int length);
t_stack	*get_bot_node(t_stack **a, int sorted_copy[], int length);
void	insert_num(t_stack **a, t_stack **b, int *trb);
void	insert_max(t_stack **a, t_stack **b, t_stack *max, int *trb);
void	insert_min(t_stack **a, t_stack **b, t_stack *min, int *trb);
void	clear_stack(t_stack **node);
// Stack Operations + Printf
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rra_sa(t_stack **a);
void	ra_sa(t_stack **a);
// Stack Operations - Printf
void	ra_no_write(t_stack **a, int *return_ra);
void	rra_no_write(t_stack **a, int *return_ra);
void	rb_no_write(t_stack **b, int *return_rb);
void	rrb_no_write(t_stack **b, int *return_rb);
void	pb_no_write(t_stack **a, t_stack **b);

// Sorting Functions
void	double_sort(t_stack **stack);
void	triple_sort(t_stack **a);
void	inefficient_sort(t_stack **a, t_stack **b, int *total);
int		efficient_sort(t_stack **a, t_stack **b, int *total);
void	quick_sort(int arr[], int N);

// Other
void	write_instructions(int *chunk_rb, int *tra, int *trb);
void	write_ra(int *tra);
void	write_rra(int *tra);
void	write_rrb(int *chunk_rb);
void	write_rb(int *trb);
void	write_rrr(int *trb, int *tra);
void	write_rr(int *trb, int *tra);
void	free_double_pointer_array(char **array);

#endif