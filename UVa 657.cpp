#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
int w,h,t,counter;
vi arr;
char g[60][60];
const int dr[]={0,0,1,-1};
const int dc[]={1,-1,0,0};
bool color[60][60];
void floodFill2(int r,int c)
{

    if(r<0||c<0||r>=h||c>=w)
        return;
    if(g[r][c]=='X')
    {
        g[r][c]='*';
        for(int i=0;i<4;i++)
            floodFill2(r+dr[i],c+dc[i]);
    }
}
void floodFill(int r,int c)
{

    if(r<0||c<0||r>=h||c>=w||color[r][c])
        return;
    color[r][c]=true;

    if(g[r][c]=='X')
    {
        counter++;
        g[r][c]='*';
        for(int i=0;i<4;i++)
            floodFill2(r+dr[i],c+dc[i]);
    }
    if(g[r][c]=='*')
       for(int i=0;i<4;i++)
           floodFill(r+dr[i],c+dc[i]);

}
void solve()
{
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(!color[i][j]&&g[i][j]!='.')
            {
                counter=0;
                floodFill(i,j);
                arr.push_back(counter);
            }
    sort(arr.begin(),arr.end());
}
int main()
{
    freopen("temp.txt","r",stdin);
    t=1;
    while(scanf("%d %d",&w,&h))
    {
        if(w==0&&h==0)
            break;
        for(int i=0;i<h;i++)
            scanf("%s",g[i]);
        arr.clear();
        memset(color,0,sizeof(color));
        solve();
        printf("Throw %d\n",t++);
        printf("%d",arr[0]);
        for(int i=1;i<arr.size();i++)
           printf(" %d",arr[i]);
        printf("\n\n");
    }
    return 0;
}
