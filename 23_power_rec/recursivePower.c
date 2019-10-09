#include <stdio.h>
#include <stdlib.h>

//function using tail recursion

unsigned powerTail(unsigned n, unsigned p, unsigned ans)
{   
    if(p == 0)
    {
        return ans;
    }
    return powerTail(n, p-1, n*ans);
}

unsigned powerWrapper(unsigned n, unsigned p){
    powerTail(n, p, 1);
}

//function using head recursion

unsigned powerHead(unsigned n, unsigned p)
{
    if(p==0)
    {
        return 1;
    }

    return n*powerHead(n, p-1);
}

int main(void)
{
    printf("5 to the power of 4 = %d\n",powerWrapper(5,4));
}

