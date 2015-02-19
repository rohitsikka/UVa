#include<stdio.h>
#include<string.h>
#define MAX 47000
int isPrime[MAX];
int primes[MAX];
int n=0;

int primaryTest(int a)
{
   if(a<MAX)   return !isPrime[a];
   int i;
   for(i=0;i<n;i++)
      if(!(a%primes[i]))   return 0;
   return 1;
}
int main()
{
   freopen("temp.txt","r",stdin);
   int i,j;
   int N;
   static int check[100000];
   memset(isPrime,0,sizeof(isPrime));
   isPrime[0]=1;
   isPrime[1]=1;
   primes[n++]=2;
   for(i=4;i<MAX;i+=2)
      isPrime[i]=1;
   for(i=3;i*i<MAX;i+=2)
   {
      if(!isPrime[i])
      {
         for(j=i*i;j<MAX;j+=i+i)
            isPrime[j]=1;
         primes[n++]=i;
      }

   }
   for(i=217;i<MAX;i+=2)
      if(!isPrime[i])  primes[n++]=i;

   int l,u;
  int minRx,minRy,maxRx,maxRy;
   int prev,curMax,curMin;
   while(scanf("%d%d\n",&l,&u)!=EOF)
   {
      N=0;
      for(i=l;i<=u;i++)
      {
          if(primaryTest(i))
            check[N++]=i;
         if(i==u) break;
      }
      if(N<2)
         puts("There are no adjacent primes.");
      else
      {
         prev=check[0];
         curMax=0;
         curMin=1e9;
         for(i=1;i<N;i++)
         {
            if(check[i]-prev>curMax)
            {
               maxRx=prev;
               maxRy=check[i];
               curMax=check[i]-prev;
            }
            if(check[i]-prev<curMin)
            {
               minRx=prev;
               minRy=check[i];
               curMin=check[i]-prev;
            }
            prev=check[i];
         }

         printf("%d,%d are closest, %d,%d are most distant.\n",minRx,minRy,maxRx,maxRy);
      }
   }
   return 0;
}
