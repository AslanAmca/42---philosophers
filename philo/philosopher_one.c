/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:01:33 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/15 00:27:12 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*philosopher_one_func(void *void_philosopher)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)void_philosopher;
	data = philosopher->data;
	pthread_mutex_lock(&data->forks[0]);
	philosopher_writer(philosopher, "has taken a fork");
	pthread_mutex_unlock(&data->forks[0]);
	philosopher_wait(data, data->time_to_die);
	philosopher_writer(philosopher, "died");
	return (NULL);
}

void	philosopher_one(t_data *data)
{
	data->start_time = get_time_milliseconds();
	if (pthread_create(&data->philosophers[0].thread_id, NULL, \
	philosopher_one_func, &data->philosophers[0]) != 0)
	{
		printf("error : pthread_create");
		clear_data(data);
		return ;
	}
	pthread_join(data->philosophers[0].thread_id, NULL);
	clear_data(data);
}
