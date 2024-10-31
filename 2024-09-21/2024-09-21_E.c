#include <stdio.h>
#include <math.h>

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    double winRate = p / 100.0;
    double loseRate = 1 - winRate;

    double finalWinRate = winRate / (1 - pow(loseRate, n + 1));

    printf("%.3f\n", finalWinRate);

    return 0;
}