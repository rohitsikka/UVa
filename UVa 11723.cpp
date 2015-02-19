#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int R,N,ans,i=1;
    cin>>R;
    cin>>N;
    while(R!=0&&N!=0)
    {
        ans=ceil((float)(R-N)/N);
        if(ans<=26)
            cout<<"Case "<<i<<":"<<" "<<ans<<"\n";
        else
             cout<<"Case "<<i<<":"<<" "<<"impossible\n";
        cin>>R;
        cin>>N;
        i++;
    }
    return 0;
}
