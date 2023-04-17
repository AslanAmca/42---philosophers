/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:59:32 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/08 07:00:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (print_error("error : argument count"));
	if (init_data(&data, argv) == 0)
		return (0);
	if (data.number_of_philosophers == 1)
	{
		philosopher_one(&data);
		return (0);
	}
	philosopher_many(&data);
	return (0);
}
