# roundRobin

 Application
One of the main functions of the operation system is to schedule processes that
the processor executes. One of the very popular algorithms for this scheduling
is called Round Robin, where each process enters a queue, executes in a FIFO
order, and after a specified time its execution stops and returns back at the end
of the queue if it still need time to continue execution or aborts if it has finished
its required time of execution.
You will be given a file with the name of the processes that needs execution,
time slot that it will enter the queue, and the needed time for it's execution.

 Algorithm
The given input file will have the watching time slots in the first line, then in the successive lines
you will have the name of the process, time it enters the queue, and the needed time for
execution respectively.
Your output should be the scheduling of the processes, showing when does each process abort
and when does the processor is idle (no processes in the queue).
Each process should enter the queue whenever its execution time comes.
Each process will be grant 1 time slot on execution, if its execution time finishes it will abort,
else it will be sent again to the queue and its execution time will be subtracted by 1.
