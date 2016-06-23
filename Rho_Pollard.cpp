#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<math.h>

using namespace std;


int gcd_Binario(int x, int y)
{
    if(x>y)
    {
        int z;
        z=x;
        x=y;
        y=z;
    }
    int g=1;
    while((x&1)==0 && (y&1)==0)
    {
        x=x>>1;
        y=y>>1;
        g*=2;

    }
    while(x!=0)
    {
         while((x&1)==0)
         {
             x=x>>1;
         }
          while((y&1)==0)
          {
              y=y>>1;
          }
          int t=abs(x-y)>>1;
          if(x>=y)
          {
              x=t;
          }else{y=t;}
    }
    return (g*y);
}

int rho_pollard(int n)
{
    long long int a,b,d,e;
    int i;
    bool band;
    a=2;
    b=2;
    i = 1;
    band= false;
    while(band==false)
    {
        a = (a*a+1)%n;
        b = (b*b+1)%n;
        b = (b*b+1)%n;
        e=abs(a-b); 
        d= gcd_Binario(e,n);
        if(1<d&&d<n)
        {
            band = true;
            return d;
        }
        if(d>=n)
        {
            band = true;
            return -1;
        }
        i++;
    }
}

int main()
{
    int x=rho_pollard(136);
    cout<<x<<endl;
    cout<<136/x<<endl;

    return 0;
}
