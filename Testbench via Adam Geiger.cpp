// Via Adam Geiger

#include "myscheduler.h"
#include <time.h>

int main(int argc, char* argv[])
{
  srand(time(NULL));
  
  
  int numberOfCPUs = 5;
  // just change the policy to try different ones.
  MyScheduler ms = MyScheduler(Policy::PBS, numberOfCPUs);
  
  int totalThreads = 60;
  
  cout << "Testbench via Adam Geiger\n\n";
  
  cout << "\tUsing PBS, 5, random remaining times and arrivial time and priorities\n";
  
  for (int i = 0; i < totalThreads; i++)
	{
		ms.CreateThread(i + rand() % 5, rand() % 40, rand() % 20, i);
	}
  
	ms.Go();
  
	return 0;
}


