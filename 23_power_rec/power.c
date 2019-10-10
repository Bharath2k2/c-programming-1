#include <stdio.h>
#include <stdlib.h>

//function using tail recursion

unsigned powerTail(unsigned x, unsigned y, unsigned ans)
{   
    if(x == 0 && y != 0)
    {
        return 0;
    }

    if(x <= 0 || y <= 0)
    {
        return ans;
    }
    
    
    return powerTail(x, y-1, x*ans);

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



