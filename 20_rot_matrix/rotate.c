#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void rotate(char matrix[10][10])
{
  int N = 10;
  for (int layer = 0; layer < N / 2; ++layer)
    {
      int maxValue = N-layer-1;
      int minValue = layer;
      for(int i = minValue; i < maxValue; ++i)
	{
	  int offset = i - minValue;
	  //temporary top value
	  char top = matrix[minValue][minValue + offset];
	  //top = left
	  matrix[minValue][minValue+offset] = matrix[maxValue - offset][minValue];
	  //left = bottom
	  matrix[maxValue-offset][minValue] = matrix[maxValue][maxValue-offset];
	  //bottom = right
	  matrix[maxValue][maxValue - offset] = matrix[minValue + offset][maxValue];
	  //right = top
	  matrix[minValue + offset][maxValue] = top;

	}
    }
}
