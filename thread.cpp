
//
// Created by richard on 2023/6/28.
//
#include <pthread.h>
#include <iostream>
using namespace std;
enum {NUM_THREADS=5};

void* say_hello(void* args)
{
  cout<<"hello Runoob!"<<endl;
  cout<<endl;
  return nullptr;
}
int main(int argc, char* argv[]){
  pthread_t  tids[NUM_THREADS];
  for(int i = 0; i < NUM_THREADS; ++i)
  {
//    thread	指向线程标识符指针。
//    attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
//    start_routine	线程运行函数起始地址，一旦线程被创建就会执行。
//    arg	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。
    if(auto ret = pthread_create(&tids[i],nullptr,say_hello,nullptr) != 0)
      cout<< "pthread_create error: error_code"<<ret<<endl;
  }
  pthread_exit(nullptr);
}