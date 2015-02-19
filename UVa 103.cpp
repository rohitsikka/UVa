#include<iostream>
#include<cstdlib>
#include<sstream>
#include<cstdio>
#include<cstdio>
#include<algorithm>
using namespace std;

int k,n;
string str[31];
stringstream oss;

struct boxes
{
    int pos;
    int dim[12];
}box[31];

bool comp(int n1,int n2)
{
    for(int i=0;i<k;i++)
        if(box[n1].dim[i]<=box[n2].dim[i])
            return false;
    return true;
}
void printPath(int parent[],int i)
{
    if(parent[i]==i)
    {
        cout<<box[i].pos<<" ";
        return;
    }
    printPath(parent,parent[i]);
    cout<<box[i].pos<<" ";
}
void LIS()
{
    int L[31],parent[31];
    for(int i=0;i<n;i++)
    {
        L[i]=1;
        parent[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
             if(comp(i,j)&&L[i]<L[j]+1)
            {

                parent[i]=j;
                L[i]=L[j]+1;
            }
        }

    }
    int max=0;
    for(int i=1;i<n;i++)
        if(L[max]<L[i])
            max=i;
    cout<<L[max]<<"\n";
    printPath(parent,max);
    cout<<"\n";
}



int main()
{
    freopen("temp.txt","r",stdin);
    while(cin>>n)
    {
        cin>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
                cin>>box[i].dim[j];
            box[i].pos=i+1;
            sort(box[i].dim,box[i].dim+k);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                    if(comp(i,j))
                        swap(box[i],box[j]);
            }
        }

       LIS();
    }
    return 0;
}
