# Server applications
A central server undertakes the service of a set of applications. 
Each application has the following characteristics: 

* ID 
* Size
* Name 
* Server login time 
* Status (value indicating whether the application is running, running or pending)
* Running time

## Description
The user enters the number of applications that will initially be included in the server list and their details. The input time is generated automatically, while the initial state of applications is initially awaiting status.

In a discrete time step, a random application state change from those in the list will occur. Its status will become 'running' and the application's components will be placed in a queue. By changing the state of the application, it will be removed from the list and inserted into the queue.

Your program will output the first element of the queue if the server is free to run an application. The execution time will be stored in the corresponding field of each application, while its status will be 'running'. And its execution time will also appear on the screen.

At each discrete step, it is checked whether the waiting list has exceeded a predefined threshold (eg 100). In this case, potential new applications will be rejected. The introduction of new applications will only be allowed if the size of the waiting list is at least 30% less than the predetermined limit.

