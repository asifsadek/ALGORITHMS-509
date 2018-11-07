#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>

 int primes[3020000],nprime;
 int marked[1000000];
void prime(int  n)
{
  int j ,i, limit = sqrt(n*1) + 2 ;
    marked[1] = 1 ;
    primes[nprime++] = 2;
    for(int i = 4 ; i <= n ; i += 2) marked[i] = 1 ;

    for(i = 3 ; i <= n ; i += 2)
    {
        if(!marked[i])
        {
            primes[nprime++] = i ;
            if(j <= limit)
            {
                for( j= j*j;j<= n ; j+= j* 2)
                {
                    marked[j] = 1;
                }
            }
        }
    }
    /*for(int  a = 0 ; a < nprime ; a++)
    {
        printf("%d ",primes[a]);
    } */
}
void factor( int n)
{
    prime(n);
    int  lim , i , j ;
    for(i = 0 ; i < n/2 +1;i++)
    {
        if(n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
            {
                printf("%d ",primes[i]);
                n = n / primes[i];
            }
        }
    }
}
int main()
{
     int n ;
    scanf("%d",&n);
    factor(n);
    return 0;
}
