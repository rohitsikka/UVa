#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct block
{
    int x;
    int y;
    int z;
}arr[210];
int n,j;

bool compatibilityComp(block a,block b)
{
    return ((a.x>b.x)&&(a.y>b.y))||((a.x>b.y)&&(a.y>b.x));
}
int comp(const void *x,const void *y)
{
    block *a=(block*)x;
    block *b=(block*)y;
    if(a->x>b->x)
        return 1;
    else if(a->x<b->x)
        return -1;
    if(a->y>b->y)
        return 1;
    else if(a->y<b->y)
        return -1;
    if(a->z>b->z)
        return 1;
    else if(a->z<b->z)
        return -1;
}
int solve()
{
    int L[210];
    for(int i=0;i<j;i++)
    {
        L[i]=arr[i].z;
        for(int k=0;k<i;k++)
        {
            if(compatibilityComp(arr[i],arr[k]))
                L[i]=max(L[i],L[k]+arr[i].z);
        }
    }
    int maximum=L[0];
    for(int i=1;i<j;i++)
        maximum=max(maximum,L[i]);
    return maximum;
}
int main()
{
    freopen("temp.txt","r",stdin);
    int x,y,z;
    int t=1;
    while(cin>>n&&n)
    {
        j=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            cin>>y;
            cin>>z;
            arr[j].x=x;   arr[j].y=y;   arr[j].z=z;
            j++;

            arr[j].x=x;   arr[j].y=z;   arr[j].z=y;
            j++;

            arr[j].x=y;   arr[j].y=x;   arr[j].z=z;
            j++;

            arr[j].x=y;   arr[j].y=z;   arr[j].z=x;
            j++;

            arr[j].x=z;   arr[j].y=y;   arr[j].z=x;
            j++;

            arr[j].x=z;   arr[j].y=x;   arr[j].z=y;
            j++;
        }

        qsort(arr,j,sizeof(block),comp);
        cout<<"Case "<<t<<": maximum height = "<<solve()<<"\n";
        t++;
    }
    return 0;
}
