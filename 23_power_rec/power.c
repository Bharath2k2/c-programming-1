#include <stdio.h>
#include <stdlib.h>

//function using tail recursion

unsigned powerTail(unsigned n, unsigned p, unsigned ans)
{   
    if(n == 0 && p != 0)
    {
        return 0;
    }

    if(n <= 0 || p <= 0)
    {
        return ans;
    }
    
    
    return powerTail(n, p-1, n*ans);
}

unsigned power(unsigned x, unsigned y){
    return powerTail(x, y, 1);
}

//function using head recursion

// unsigned powerHead(unsigned n, unsigned p)
// {
//     if(p==0)
//     {
//         return 1;
//     }

//     return n*powerHead(n, p-1);
// }



