//
// Created by richard on 2023/6/28.
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define NUM_THREADS 5
void *wait(void* t)
{
  int i;
  long tid;
  tid = (long) t;
  sleep(1);
  cout<<"sleeping in thread "<< endl;
  cout<<"thread with id: "<<tid<<" ...exiting"<<endl;
  pthread_exit(nullptr);
}

int main()
{
  int rc;
  int i;
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;
  void* status;

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

  for(i=0;i< NUM_THREADS;i++) {
    cout << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, wait, (void*)&i);
    if (rc) {
      cout << "Error:unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  pthread_attr_destroy(&attr);
  for(i = 0; i<NUM_THREADS;++i)
  {
    rc= pthread_join(threads[i],&status);
    if(rc){
      cout<<"Error unable to join"<<rc<<endl;
      exit(-1);
    }
    cout << "Main: completed thread id :" << i ;
    cout << "  exiting with status :" << status << endl;
  }
  cout << "Main: program exiting." << endl;
  pthread_exit(nullptr);
}



