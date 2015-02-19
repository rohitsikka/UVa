#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    long long int n1,n2;
    while(cin>>n1)
    {
        cin>>n2;
        cout<<n1*n2*2<<"\n";
    }
    return 0;
}
