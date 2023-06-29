//
// Created by richard on 2023/6/28.
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS     5
struct thread_data{
  int thread_id;
  char* message;
};

void *PrintHello(void *threadarg)
{
  auto my_data= (struct thread_data*) threadarg;
  cout<<"thread ID :"<< my_data->thread_id<<endl;
  cout<<"Message :"<<my_data->message<<endl;
  pthread_exit(nullptr);
}

int main(int argc, char* argv[])
{
  pthread_t threads[NUM_THREADS];
  struct thread_data td[NUM_THREADS];
  int rc;
  int i;
  for(i=0;i<NUM_THREADS;++i)
  {
    cout<<"main(): create threads"<< i <<endl;
    td[i].thread_id = i;
    td[i].message = (char*)"This is message";
    rc = pthread_create(&threads[i], nullptr,PrintHello,(void*)&td[i]);
    if(rc)
    {
      cout<<"error cannot create threads"<<rc<<endl;
      exit(-1);
    }
  }
  pthread_exit(nullptr);
}