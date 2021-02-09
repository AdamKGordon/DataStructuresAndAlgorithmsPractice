#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 231A


int main(int argc, char** argv)
{
    int i,j;
    int lines;
    int line_values[3];
    int total=0;

    scanf("%d", &lines);
    for(i=0; i<lines; i++) {
        scanf("%d%d%d", &line_values[0], &line_values[1], &line_values[2]);
        if (line_values[0]+line_values[1]+line_values[2]>1) {
            total++;
        }
    }

    printf("%d", total);

    return 0;
}