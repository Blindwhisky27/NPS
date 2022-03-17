#include <stdio.h>
int main()
{
    int sd[4], rd[4], sp[3], rp[3], r[7];

    printf("Enter 4 bit data word:\n");
    for (int i = 3; i >= 0; i--)
        scanf("%d", &sd[i]);
    // d7 d6 d5 p4 d3 p2 p1
    // p1=d3 d5 d7
    // p2=d3 d6 d7
    // p3=d5 d6 d7;
    sp[0] = (sd[0] + sd[1] + sd[3]) % 2;
    sp[1] = (sd[0] + sd[2] + sd[3]) % 2;
    sp[2] = (sd[1] + sd[2] + sd[3]) % 2;

    printf("Hamming code: %d%d%d%d%d%d%d\n", sd[3], sd[2], sd[1], sp[2], sd[0], sp[1], sp[0]);

    printf("Enter recived 7 bit data word:\n");
    for (int i = 6; i >= 0; i--)
        scanf("%d", &r[i]);
    // d7 d6 d5 p4 d3 p2 p1
    rp[0] = (r[0] + r[2] + r[4] + r[6]) % 2;
    rp[1] = (r[1] + r[2] + r[5] + r[6]) % 2;
    rp[2] = (r[3] + r[4] + r[5] + r[6]) % 2;

    if (rp[0] == 0 && rp[1] == 0 && rp[2] == 0)
        printf("Entered 4 bit data word is error free\n");
    else
    {
        int pos = (1 * rp[0]) + (2 * rp[1]) + (4 * rp[2]);
        printf("Error is %dth bit\n", pos - 1);
    }
}