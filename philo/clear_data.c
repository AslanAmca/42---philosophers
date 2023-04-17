/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:30:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/09 19:32:05 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writer);
	pthread_mutex_destroy(&data->is_eating);
	pthread_mutex_destroy(&data->death_checker);
}

static void	free_data(t_data *data)
{
	if (data->forks != NULL)
		free(data->forks);
	if (data->philosophers != NULL)
		free(data->philosophers);
}

void	clear_data(t_data *data)
{
	destroy_mutexes(data);
	free_data(data);
}
