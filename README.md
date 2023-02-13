# Server applications

Application servers are designed to provide applications with the fundamentals that they need to make them functional and efficient.

## How it works
The user enters the number of applications and their details. 

* ID 
* Size
* Name 
* Server login time 
* Status (running or pending)
* Running time

The input time is generated automatically. The initial status of applications is 'pending'.

Right after, a random application from the server list changes status and become 'running' and the application's components will be placed in a queue. By changing the state of the application, it will be removed from the server list and inserted into the queue.

Then, the program will output the first element of the queue if the server is free to run an application. The execution time will be stored in the corresponding field of each application, while its status will be 'running'. And its execution time will also appear on the screen.

*The program is checked whether the waiting list has exceeded a predefined threshold (eg 100). In this case, potential new applications will be rejected. The introduction of new applications will only be allowed if the size of the waiting list is at least 30% less than the predetermined limit.

