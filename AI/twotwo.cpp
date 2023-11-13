#include<bits/stdc++.h>
using namespace std;
int main()
{


    int cnt=1;
    for(int f=1; f<=1; f++)
        for(int t=0; t<=9; t++)
            for(int o=0; o<10; o++)
                for(int u=0; u<10; u++)
                    for(int w=0; w<10; w++)
                        for(int r=0; r<10; r++)
                            if(o+o>=10 && w+w>=10 && t+t>=10)    {
                                int two1=100*t+10*w+o;
                                int two2=two1;
                                int four=1000*f+100*o+10*u+r;
                                set<int>s;
                                s.insert(t);
                                s.insert(w);
                                s.insert(o);
                                s.insert(f);
                                s.insert(r);
                                s.insert(u);
                                if(s.size()==6) {
                                    if(two1+two2==four) {
                                        cout<<" TWO = "<<two1<<endl;
                                        cout<<" TWO = "<<two1<<endl;
                                        cout<<"--------------"<<endl;
                                        cout<<"FOUR = "<<four<<endl;
                                        cout<<endl;
                                        exit(0);
                                    }
                                }
                            }
    return 0;
}
