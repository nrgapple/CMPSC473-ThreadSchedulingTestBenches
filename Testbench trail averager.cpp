// via Adam Geiger

// This testbench runs your code for [60] threads for each policy. It does this for [20] trials.
//  Then Averages the total time for each trail for each policy and prints it out.

#include "myscheduler.h"
#include <time.h>

double AvgFromList(list<int> data);
void CreateListOfThreads(list<ThreadDescriptorBlock*> &ThreadList, int size);

int main(int argc, char* argv[])
{
  int numberOfCPUs = 5;
  Policy policy = FCFS;
  string policyString;
  
  
  
  list<int> FCFSResults;
  list<int> STRFwPResults;
  list<int> STRFwoPResults;
  list<int> PSwPResults;
  
  list<int> Results[4];
  
  Results[0] = FCFSResults;
  Results[1] = STRFwPResults;
  Results[2] = STRFwoPResults;
  Results[3] = PSwPResults;
  
  list<ThreadDescriptorBlock*> all_threads;
  
	srand(time(NULL));
  
  // Change for different amount of threads.
  int totalThreads = 60;
  
  cout << "Testbench via Adam Geiger\n\n";
  
  // Change for different amount of trails.
  int trails = 20;
  
  for (int trail_i = 0; trail_i < trails; trail_i++)
  {
    CreateListOfThreads(all_threads, totalThreads);
    for (int policy_i = 0; policy_i < 4; policy_i++)
    {
      policy = (Policy)policy_i;
      cout << "-----------" << endl;
      cout << "policy: " << policy_i << " trail: " << trail_i << endl;
      cout << "-----------" << endl;
      
      MyScheduler ms = MyScheduler(policy, numberOfCPUs);
      ms.enable_debug = false;
      
      list<ThreadDescriptorBlock*>::iterator threadIter;
      threadIter = all_threads.begin();
      while(threadIter != all_threads.end())
      {
        
        ms.CreateThread((*threadIter)->arriving_time, (*threadIter)->remaining_time, (*threadIter)->priority, (*threadIter)->tid);
        threadIter++;
      }
      
      ms.Go();
      
      Results[policy_i].push_front(ms.getTimer());
    }
    all_threads.clear();
  }
  
  
  cout << "-----------" << endl;
  cout << "AVG TIME" << endl;
  cout << "-----------" << endl;
  for (int policy_i = 0; policy_i < 4; policy_i++)
  {
    cout << "\t "
      << policy_i << " "
    << AvgFromList(Results[policy_i]) << endl;
    
  }
  
  cout << endl;
	return 0;
}


double AvgFromList(list<int> data)
{
  int sum = 0;
  list<int>::iterator dataInter;
  dataInter = data.begin();
  while (dataInter != data.end())
  {
    sum += (*dataInter);
    dataInter++;
  }
  return sum / data.size();
}

void CreateListOfThreads(list<ThreadDescriptorBlock*> &ThreadList, int size)
{
  for (int thread_i = 0; thread_i < size; thread_i++)
  {
    ThreadDescriptorBlock *temp = new ThreadDescriptorBlock();
    temp->tid = thread_i;
    temp->arriving_time = thread_i + rand() % 5;
    temp->remaining_time = rand() % 40 + 1;
    temp->priority = rand() % 20;
    ThreadList.push_back(temp);
  }
  
}



