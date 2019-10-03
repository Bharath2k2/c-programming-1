#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void rotate(char matrix[10][10]) // can add int N as the dimension parameter
{
    // If we take one of the parameters of the symmetrical array as N
    //if(N%2==0)
    // {
    //     int coefficient = N/2;
    // } else 
    // {
    //     int coefficient = (N-1)/2;
    // }
    int N = 10; //x 10
    for (int layer = 0; layer < N / 2; ++layer) 
    { 
        int maxValue = N-layer-1;
        int minValue = 0+layer;
        for(int offset = layer; offset <= maxValue; ++offset)
        {
            //temporary top value 
            char top = matrix[minValue][minValue + offset];
            //left = top
            matrix[minValue][minValue+offset] = matrix[maxValue - offset][minValue];
            //bottom to left
            matrix[maxValue][maxValue-offset] = matrix[maxValue-offset][minValue];
            //right to bottom
            matrix[maxValue - offset][minValue] = matrix[minValue + offset][maxValue];
            //top to right
            matrix[minValue + offset][maxValue] = top;

        }
    } 
}