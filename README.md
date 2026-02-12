*This proyect has been created as part of the 42 curriculum by rnuno-im*

## Description
Philo is a small project to introduce us to threads and mutexes. It's a program that simulates philosophers who eat, think, sleep, and die (if necessary). The main goal of the project is to create different threads and mutexes to handle concurrent actions without data races or deadlocks.

## Instructions
- **Compile:** 'make'
- **Run:** ./philo n_philo time_to_die time_to_eat time_to_sleep **n_of_meals(optional)**
- **Clean objects:** 'make clean'
- **Full clean:** 'make fclean'

You can test the program with for example:
- './philo 4 410 200 200 10' (must finish)
- './philo 3 310 200 100' (must die)
- './philo 10 800 200 200' (must not finish)

## Resources
- [Introduction to threads](https://www.youtube.com/watch?v=ldJ8WGZVXZk)
- [introduction to mutexes](https://www.youtube.com/watch?v=oq29KUy29iQ)

**AI usage: AI was used in a limited way, mainly to fix small errors, give some guidance during the proyet, and help with a few technical quiestions.