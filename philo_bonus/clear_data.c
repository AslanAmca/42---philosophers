/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:30:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/04/16 23:21:20 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->writer);
	sem_close(data->is_eating);
	sem_close(data->death_checker);
	sem_unlink("forks");
	sem_unlink("writer");
	sem_unlink("is_eating");
	sem_unlink("death_checker");
}

static void	free_data(t_data *data)
{
	if (data->philosophers != NULL)
		free(data->philosophers);
}

void	clear_data(t_data *data)
{
	destroy_semaphores(data);
	free_data(data);
}
