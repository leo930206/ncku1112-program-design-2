#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);

    if (N <= 0 || N >= 1000) return 0;

    int X, Y, Max = -1;

    for (X = 0; X <= N; X++) 
    {
        Y = N - X;
        printf("(%d,%d)\n", X, Y);

        int XY = X*Y;
        if (XY > Max) 
        {
            Max = XY;
        }
    }

    printf("%d\n", Max);

    return 0;
}
