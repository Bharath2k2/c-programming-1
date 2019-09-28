#include <stdio.h>
#include <stdlib.h>

size_t checkLength(size_t tempLength, size_t newLength);

size_t maxSeq(int *array, size_t n)
{
    size_t tempLength = 0;
    size_t newLength = 0;
    size_t arraySize = sizeof(array)/sizeof(array[0]);

    if(n < 1 || array == NULL || arraySize < 1)
    {
        return 0;
    }
    for(size_t i = 0; i < n-1; ++i)
    {
        if(array[i] < array[i+1])
        {
            tempLength++;
        }
        if((array[i] > array[i+1]) || i == n-2)
        {
            newLength = checkLength(tempLength, newLength);
            tempLength = 0;
        }
    }
    if(newLength != 0){
        return newLength + 1;
    }
    return newLength;
}

size_t checkLength(size_t tempLength, size_t newLength) {
    if(tempLength > newLength)
    {
        return tempLength;
    }
    return newLength;
}

//tempPointer = &array[i];
//int *tempPointer = &array[0];
//int *newPointer = &array[0];
//newPointer = checkPointer(tempPointer, newPointer);
//int *checkPointer(int *tempPointer, int *newPointer);
