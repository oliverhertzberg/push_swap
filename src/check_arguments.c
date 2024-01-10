/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:56:43 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 19:54:10 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_integer(long num, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '-')
			i++;
		if (!ft_isdigit(string[i++]))
			return (0);
	}
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	return (0);
}

int	is_duplicate(long num, char **array)
{
	int		num_count;
	long	num_cmp;
	int		i;

	num_count = 0;
	i = -1;
	while (array[++i])
	{
		num_cmp = ft_atoi(array[i]);
		if (num == num_cmp)
		{
			num_count++;
			if (num_count > 1)
				return (1);
		}
	}
	return (0);
}

void	check_one_arg(char *argv)
{
	char	**temp_array;
	int		i;
	long	num;

	temp_array = ft_split(argv, ' ');
	i = -1;
	while (temp_array[++i])
	{
		if (check_for_big_num(temp_array[i]) == 1)
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		num = ft_atoi(temp_array[i]);
		if (!is_integer(num, temp_array[i]) || is_duplicate(num, temp_array))
		{
			free_double_pointer_array(temp_array);
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
	free_double_pointer_array(temp_array);
}

void	check_multiple_args(char **argv)
{
	long	num;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (check_for_big_num(argv[i]) == 1)
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		num = ft_atoi(argv[i]);
		if (!is_integer(num, argv[i]) || is_duplicate(num, argv))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
}

void	check_arguments(int argc, char **argv)
{
	if (argc == 1)
		check_one_arg(*argv);
	else
		check_multiple_args(argv);
}
