#include <stdio.h>
int main()
{
    printf("%d\n", 8 & 4);  // 1000 * 0100 = 0000 (0)   AND
    printf("%d\n", 8 | 4);  // 1010 * 0100 = 1110 (14)  OR
    printf("%d\n", 8 ^ 4);  // 1010 * 0100 = 1110 (14)  XOR
    printf("%d\n", 8 >> 2); // 8 / 2^2 = 2
    printf("%d\n", 5 << 1); // 5 * 2^1 = 10
    printf("%d\n", ~0);     // ~0 = -1 = 1111...1111 (2's complement)
}
