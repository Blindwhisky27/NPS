#include <stdio.h>

unsigned int checksum()
{
    int sum = 0, data;
    printf("Enter values in 16 bits: \n");
    for (int i = 0; i < 9; i++)
    {
        printf("Field[%d]: ", i + 1);
        scanf("%x", &data);
        sum = sum + (unsigned int)data;
        while (sum >> 16)
            sum = (sum & 0xFFFF) + sum >> 16;
    }
    sum = ~sum;
    return (unsigned int)sum;
}
int main()
{
    int result1, result2;
    printf("Enter senders data: ");
    result1 = checksum();
    printf("Checksum: %d\n", result1);

    printf("Enter recviers data: ");
    result2 = checksum();
    printf("Checksum: %d\n", result1);

    if (result1 == result2)
        printf("Checksum verified, data is same");
    else
        printf("Checksum didn't verified, data is not same");
    return 0;
}