#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
  
    printf("max int = %d  and its size = %d\n", a, sizeof(a));
    printf("max float = %f  and its size = %d\n", b, sizeof(b));
    printf("max double = %f  and its size = %d\n", c, sizeof(c));
    return 0;
}
