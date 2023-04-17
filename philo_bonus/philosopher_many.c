/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_many.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:14:57 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/17 22:38:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	wait_and_kill_process(t_data *data)
{
	int	waitpid_return;
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		waitpid(-1, &waitpid_return, 0);
		if (waitpid_return != 0)
		{
			i = 0;
			while (i < data->number_of_philosophers)
			{
				kill(data->philosophers[i].process_id, SIGKILL);
				i++;
			}
			break ;
		}
		i++;
	}
}

static void	handle_exit(t_data *data)
{
	if (data->died_any_philosopher == 1)
	{
		clear_data(data);
		exit(1);
	}
	clear_data(data);
	exit(0);
}

static void	*died_checker(void *void_philosopher)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)void_philosopher;
	data = philosopher->data;
	while (1)
	{
		sem_wait(data->is_eating);
		if (get_time_milliseconds() - \
		philosopher->last_eating_time > data->time_to_die)
			philosopher_died(data, philosopher);
		sem_post(data->is_eating);
		if (data->died_any_philosopher == 1)
			break ;
		sem_wait(data->is_eating);
		if (data->philosopher_must_eat > 0 && \
			philosopher->eating_count >= data->philosopher_must_eat)
		{
			sem_post(data->is_eating);
			break ;
		}
		sem_post(data->is_eating);
	}
	return (NULL);
}

static void	process_handle(t_data *data, t_philosopher *philosopher)
{
	philosopher->last_eating_time = get_time_milliseconds();
	pthread_create(&philosopher->died_thread, NULL, died_checker, philosopher);
	if (philosopher->id % 2 == 1)
		usleep(15000);
	while (1)
	{
		sem_wait(data->death_checker);
		if (data->died_any_philosopher == 1)
		{
			sem_post(data->death_checker);
			break ;
		}
		sem_post(data->death_checker);
		if (data->philosopher_must_eat > 0 && \
			philosopher->eating_count >= data->philosopher_must_eat)
			break ;
		philosopher_eat(data, philosopher);
		philosopher_sleep(data, philosopher);
		philosopher_writer(philosopher, "is thinking");
	}
	pthread_join(philosopher->died_thread, NULL);
	handle_exit(data);
}

void	philosopher_many(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_milliseconds();
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i].process_id = fork();
		if (data->philosophers[i].process_id < 0)
		{
			printf("error : fork");
			i--;
			while (i >= 0)
			{
				kill(data->philosophers[i].process_id, SIGKILL);
				i--;
			}
			clear_data(data);
			return ;
		}
		if (data->philosophers[i].process_id == 0)
			process_handle(data, &data->philosophers[i]);
		i++;
	}
	wait_and_kill_process(data);
	clear_data(data);
}
