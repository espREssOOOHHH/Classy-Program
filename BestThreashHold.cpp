#include <bits/stdc++.h>
//CCF考试 202012-2
using namespace std;

    typedef struct resul{
    int positive;
    int negative;
    }result;


int main()
{
    int line;
    cin>>line;
    long s;int t;//中间变量

    map<long,result> arra;

    for(int a=0;a<line;a++)
        {
            cin>>s>>t;
            if(!arra.count(s))
            {
                arra.insert(pair<long,result>(s,{0,0}));
            }

            if(t)
                arra[s].positive+=1;
            else
                arra[s].negative+=1;

        }

        int maxscore=0;int score=0;int maxnum=0;
        for(auto & p:arra)
        {
            score=0;
            //cout<<p.first<<' '<<p.second.positive<<p.second.negative<<endl;

            for(auto &it:arra)
                if(it.first>=p.first)
                score+=it.second.positive;
                else
                score+=it.second.negative;

            if(score>maxscore)
                maxscore=score,maxnum=p.first;
            if(score==maxscore and maxnum<p.first)
                maxscore=score,maxnum=p.first;
        }
        printf("%d",maxnum);
    return 0;
}