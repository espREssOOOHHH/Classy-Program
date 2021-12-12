#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

template<typename T,typename ...Args>
class Magics{
    public:
        T magics;
        void show(Args...args){
            cout<<"Magics: T is "<<magics<<' '<<endl<<"args count "<<sizeof...(args)<<endl;
        }
};

using M=Magics<int,int,int,int>;

template<typename T,typename...Args>
void printf_more(T t0,Args...t){
    cout<<"param:"<<t0<<'\t';
    if constexpr(sizeof...(t))
        printf_more(t...);
}

template<typename...T>
auto sum_all(T...t){
    return (t+...);
}



class newFeatures{
public:
    newFeatures()=default;
    newFeatures& operator=(const newFeatures&)=delete;
    constexpr int fibonacci(const int n){
        return n==1 or n==2?1:fibonacci(n-1)+fibonacci(n-2);
    };

    void printArray(std::initializer_list<int> list){
        for(int i:list){cout<<' '<<i<<' ';}
    };
    std::tuple<int,double,string> f(){
        return make_tuple(1,2.5,"hello");
    };
    auto adds(auto a,auto b){
        return a+b;
    }

    enum class new_enums:unsigned int{
        tie,
        bos,
        ken=29,
        pis=29
    }
};



int main()
{
    newFeatures n;
    vector<int> s={1,2,3,4,5};
    n.printArray({2,5});
    if(vector<int>::iterator pt=find(s.begin(),s.end(),3);pt!=s.end())
        cout<<"5_contained vector finded"<<endl;
    int array[n.fibonacci(5)];

    auto[x,y,z]=n.f();
    cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<endl;

    auto alpha=n.fibonacci(2);
    auto beta=5.3;
    decltype(alpha+beta) c;
    cout<<std::is_same<decltype(beta),decltype(alpha)>::value<<endl;
    
    if constexpr(1+2)
        cout<<n.adds(alpha,beta)<<endl;

    M m;
    m.magics=2;
    m.show(2,4,6);

    printf_more(2,4,6,8,3.32,"dfjh");
    
    cout<<endl<<"sum_all values:"<<sum_all(2,4,7,3.4)<<endl;

     

    
    return 0;
}