#include<iostream>
#include<cstdio>
using namespace std;
string str;
bool isValid(int i,int j)
{
    if(i==j)
    {
        if(str[i]=='A')
            return true;
        else
            return false;
    }
    if(str[j]=='B'&&str[j-1]=='A')
        return isValid(i,j-2);

    if(str[i]=='B'&&str[j]=='A')
        return isValid(i+1,j-1);

    return false;
}
int main()
{
    freopen("temp.txt","r",stdin);
    int n;
    cin>>n;
    while(n--)
    {
        cin>>str;
        if(str.size()==1)
        {
            if(str[0]=='A')
                cout<<"SIMPLE";
            else
                cout<<"MUTANT";
        }
        else if(str.size()%2==0)
            cout<<"MUTANT";
        else if(str[str.size()-1]=='B'&&str[str.size()-2]=='A')
        {
            if(isValid(0,str.size()-3))
                cout<<"FULLY-GROWN";
            else
                cout<<"MUTANT";
        }
        else if(str[0]=='B'&&str[str.size()-1]=='A')
        {
            if(isValid(1,str.size()-2))
                cout<<"MUTAGENIC";
            else
                cout<<"MUTANT";
        }
        else
            cout<<"MUTANT";
        cout<<"\n";
    }
    return 0;
}
