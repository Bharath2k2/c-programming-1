#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int main(void)
{   
    int rightAnswers = 0;
    if(power(0,0) == 1)
    {
      rightAnswers++;
    }       
    if(rightAnswers == 1)
    {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
    
}