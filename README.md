# 42-Philosophers
## Objectives
- Learn the basics of threading a process.
- Work on the same memory space.
- Learn how to make threads.
- Discover the mutex, semaphore and shared memory.

## Brief explanation
### philo_one
Rules:
- One fork between each philosopher.
- Protect the forks state with a ```mutex``` for each of them.
- Each philosopher should be a ```thread```.
### Usage
```c
$>make
$>./philo_one num_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### philo_two
Rules:
- All the forks are in the middle of the table.
- Forks are represented by a ```semaphore```.
- Each philosopher should be a ```thread```.
### Usage
```c
$>make
$>./philo_two num_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### philo_three
Rules:
- All the forks are in the middle of the table.
- Forks are represented by a ```semaphore```.
- Each philosopher should be a ```process```.
### Usage
```c
$>make
$>./philo_three num_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## Resources

## Author
- ***[ichejra](https://github.com/ichejra)***
