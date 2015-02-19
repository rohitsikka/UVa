#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int n,coach;
    stack<int> s;
    while(scanf("%d",&n)&&n)
    {
        while(true)
        {
            while(s.size() > 0) s.pop();
            int j=1;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&coach);
                if(coach==0)
                    break;
                while(j<=coach)
                {
                    s.push(j);
                    j++;
                }
                if(s.top()==coach)
                    s.pop();
            }
            if(coach==0)
                break;
            if(s.size()==0)
                printf("Yes");
            else
                printf("No");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
