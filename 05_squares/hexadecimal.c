#include <stdio.h>
#include <stdlib.h>

//function that determines if coord is in range between offset (inclusive) and offset + size (exclusive)
// if so return 1, else return 0;
int isInRange (int coord, int offset, int size) {
    return coord >= offset && coord < offset + size ? 1 : 0;
}

//function which determines if the coordinate is at the border of offset or offset + size
// if so return 1, else return 0
int isAtBorder (int coord, int offset, int size) {
    return coord == offset || coord == offset + size ? 1 : 0;
}

//compute max of two values
int maxValue (int a, int b) {
    return a > b ? a : b;
}

void squares (int size1, int x_offset, int y_offset, int size2) {

    //compute the max of size1 and (x_offset + size2) call this w(idth)
    int width =  maxValue (size1, x_offset + size2);
    //compute the max of size2 and (y_offset + size2) call this h(eight) (of the screen)
    int height = maxValue (size1,  y_offset + size2);
    //count from 0 to h call it y(the y coordinate)
    for (int y = 0; y < height; ++y) {
        //count from 0 to w and call it x(the x coordinate)
        for (int x = 0; x < width; ++x) {
            
            if ( (isInRange (x, x_offset, size2) && isAtBorder (y, y_offset, size2-1)) || ((isInRange (y, y_offset, size2) && isAtBorder (x, x_offset, size2 - 1))) ){
                printf("*");
                continue;
            }
            if ( (isInRange(x, 0, size1) && isAtBorder(y, 0, size1-1)) || (isInRange (y, 0, size1) && isAtBorder (x, 0, size1-1)) ) {
                printf("#");
                continue;
            }
            printf(" ");
                
            
        }
        printf("\n");
    }
}





int main (void) {
    squares(3, 5, 8, 5);
}

