# Philosophers

**Philosophers** is a system programming project from Ecole 42 that explores the concept of concurrent programming by simulating the classic **Dining Philosophers Problem**. The project requires the use of threads and synchronization techniques to handle shared resources and avoid deadlocks.

## Project Overview

The **Philosophers** project consists of a simulation where several philosophers are seated around a table, each with a fork on either side. Philosophers alternate between thinking, eating, and sleeping. To eat, a philosopher must pick up both forks (shared resources) at the same time, leading to potential deadlocks and resource contention.

The project is divided into two parts:

- **Mandatory Part**: Implemented using **threads** and **mutexes** for synchronization.
- **Bonus Part**: Implemented using **processes** and **semaphores** for synchronization.

## Objectives

- **Concurrency**: Understand and manage concurrent processes or threads.
- **Synchronization**: Safely manage access to shared resources (forks) using synchronization mechanisms.
- **Deadlock Avoidance**: Implement strategies to avoid deadlocks and ensure that all philosophers get a chance to eat.
- **Efficiency**: Ensure that the simulation runs efficiently without unnecessary delays.

## Mandatory Part: Threads and Mutexes

In the mandatory part of the project, each philosopher is represented by a separate thread. Forks (shared resources) are protected using mutexes to prevent race conditions and ensure safe access.

Key elements of the mandatory part:
- **Threads**: Each philosopher runs in its own thread.
- **Mutexes**: Used to lock and unlock forks (shared resources) to prevent multiple philosophers from accessing them simultaneously.
- **Philosopher Lifecycle**: Each philosopher alternates between thinking, eating, and sleeping, trying to avoid starvation and deadlocks.

## Bonus Part: Processes and Semaphores

In the bonus part of the project, philosophers are implemented as separate processes, and semaphores are used to control access to forks.

Key elements of the bonus part:
- **Processes**: Each philosopher is a separate process, and inter-process communication is managed using semaphores.
- **Semaphores**: Control access to the forks and prevent multiple philosophers from accessing the same fork simultaneously.
- **Enhanced Synchronization**: Semaphores allow for more advanced synchronization, ensuring that philosophers don't deadlock or starve.

## How to Use

1. **Compiling the Project**:
	Use `make` to compile both the mandatory and bonus parts of the project:
	```bash
	make
	```
2. Running the Mandatory Version (Threads and Mutexes):
	```bash
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
	# example
	./philo 5 800 200 200
	```

3. Running the Bonus Version (Processes and Semaphores):
	```bash
	./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
	# example
	./philo_bonus 5 800 200 200
	```

## Parameters

| Parameter                                      | Description                                                                                      |
|------------------------------------------------|--------------------------------------------------------------------------------------------------|
| `<number_of_philosophers>`                     | The number of philosophers and forks.                                                            |
| `<time_to_die>`                                | Time (in milliseconds) a philosopher can go without eating before they die.                      |
| `<time_to_eat>`                                | Time (in milliseconds) a philosopher spends eating.                                               |
| `<time_to_sleep>`                              | Time (in milliseconds) a philosopher spends sleeping.                                             |
| `[number_of_times_each_philosopher_must_eat]`  | (Optional) The number of times each philosopher must eat before the simulation ends. If not provided, the simulation will continue indefinitely until a philosopher dies. |


## Learning Outcomes
By completing the Philosophers project, you will gain a deeper understanding of:
1. Concurrency and parallelism: Handling multiple threads or processes running simultaneously.
2. Synchronization techniques: Using mutexes and semaphores to manage access to shared resources.
3. Deadlock prevention: Strategies to avoid deadlocks in concurrent programming.
4. Thread vs. Process: Understanding the differences between thread-based and process-based concurrency models.
