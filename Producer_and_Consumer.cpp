#include <iostream>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <stdlib.h>
using namespace std;
bool flag=true;
#define MAXV 10
int items = 0, spaces = 2;
class datam
{
    public:
    void insert(int value_,unsigned long id_)
    {
        value.push_back(value_);
        id.push_back(id_);
    }
    bool is_full(void)
    {
        return value.size()<MAXV?false:true;
    }
    bool is_empty(void)
    {
        return value.size()==0?true:false;
    }
    int pop_and_show(void)
    {
        if(value.empty() or id.empty())
        return -1;
        else
        {        
        int value_;
        unsigned long id_;
        value_=value.back();
        value.pop_back();
        id_=id.back();
        id.pop_back();
        cout<<"value="<<value_<<", id="<<id_<<endl;
        }
        return 1;

    }
    private:
    vector<int> value;
    vector<unsigned long> id;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;  
pthread_cond_t emptys = PTHREAD_COND_INITIALIZER;  

datam d;

void *producer(void *arg)
{

    while(flag)
    {
        pthread_mutex_lock(&mutex);
        while(d.is_full()){pthread_cond_wait(&full,&mutex);}

        int value=rand()%1000;
        unsigned long id=pthread_self();
        /*items++;
        spaces--;*/
        d.insert(value,id);
        printf( "producer %zu ,value is %d\n", pthread_self(),value);
        pthread_cond_signal(&emptys);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    while(flag)
    {
        pthread_mutex_lock(&mutex);
        while(d.is_empty()){pthread_cond_wait(&emptys,&mutex);}
        printf( "consumer %zu  ", pthread_self());
        d.pop_and_show();
       /* items--;
        spaces++;*/
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main()
{
   srand((unsigned)time(NULL));
   flag=true;
   cout<<"hello"<<endl;
   pthread_t a1,a2,b1,b2;
   pthread_create(&a1,NULL,producer,NULL);
   pthread_create(&a2,NULL,producer,NULL);
   pthread_create(&b1,NULL,consumer,NULL);
   pthread_create(&b2,NULL,consumer,NULL);
   sleep(1);
   flag=false;
   pthread_join(a1,NULL);
   pthread_join(a2,NULL);
   pthread_join(b1,NULL);
   pthread_join(b2,NULL);
   return 0;
}