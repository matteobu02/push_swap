/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:02:14 by mbucci            #+#    #+#             */
/*   Updated: 2022/01/06 15:47:30 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_stock *ptr, char **tab)
{
	int					i;
	int					s;
	unsigned long int	n;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	s = 1;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		if (str[i++] == '-')
			s = -1;
	n = 0;
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			free_error(ptr, NULL);
		n = n * 10 + (str[i++] - 48);
		if ((n > 2147483647 && s == 1) || (n > 2147483648 && s == -1))
			free_and_close(tab, ptr);
	}
	return (n * s);
}

void	free_error(t_stock *a, t_stock *b)
{
	clear_list(a);
	clear_list(b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_and_close(char **tab, t_stock *ptr)
{
	tab = ft_free_tab(tab);
	free_error(ptr, NULL);
}

void	clear_list(t_stock *ptr)
{
	t_stock	*temp;

	if (!ptr)
		return ;
	while (ptr)
	{
		temp = ptr;
		if (ptr->next)
			ptr = ptr->next;
		else
			ptr = NULL;
		free(temp);
	}
	temp = NULL;
}
