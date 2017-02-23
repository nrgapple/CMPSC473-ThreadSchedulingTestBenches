#CMPSC473-ThreadSchedulingTestBenches
######PSU CMPSC 473 Project Shared Testbenches Git

This Git repo is for PSU's CMPSC 473 class for the Project 1 Testbenches. If you would like to contribute, please follow the skeleton that the other TB's are using, and submit a request to merge to master. All TB's are welcome!If there is an issue with a TB, or its expected output is wrong, please issue a ticket!

All TB's follow the following format

```
// Via [YOUR NAME HERE]

#include "myscheduler.h"

int main(int argc, char* argv[])
{

	 cout << "Testbench via [YOUR NAME HERE]\n\n";

	 cout << "\tUsing [POLICY], [CPUs], [DETAILS]\n";
	 MyScheduler ms = MyScheduler(Policy::[POLICY], [CPUs]);
	 ms.CreateThread(...);
  ...
	 ms.CreateThread(...);

	 ms.Go();
	 /*Results should be:
	 (Descriptive set of results) */
  
	 return 0;
}
```

Included Testbenches:

1. **Alexandar Devic's v1.0**
  * This TB only tests the FCFS method on 1 CPU on 7 threads. Very basic.
  
2. **Kenneth Au's v1.0**
  * This TB tests the FCFS method on 1 to 3 CPU's with 3 threads.
