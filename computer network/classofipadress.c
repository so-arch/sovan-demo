#include <stdio.h>

int main() {
    int octet1, octet2, octet3, octet4;

    printf("Enter the IP address (dotted decimal notation): ");
    scanf("%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    if (octet1 >= 0 && octet1 <= 127) {
        printf("Class: A\n");
        printf("Network ID: %d.0.0.0\n", octet1);
    } else if (octet1 >= 128 && octet1 <= 191) {
        printf("Class: B\n");
        printf("Network ID: %d.%d.0.0\n", octet1, octet2);
    } else if (octet1 >= 192 && octet1 <= 223) {
        printf("Class: C\n");
        printf("Network ID: %d.%d.%d.0\n", octet1, octet2, octet3);
    } else if (octet1 >= 224 && octet1 <= 239) {
        printf("Class: D\n");
        printf("Network ID: %d.%d.%d.%d (Multicast address)\n", octet1, octet2, octet3, octet4);
    } else if (octet1 >= 240 && octet1 <= 254) {
        printf("Class: E\n");
        printf("Network ID: %d.%d.%d.%d (Reserved for future use)\n", octet1, octet2, octet3, octet4);
    } else {
        printf("Invalid IP address\n");
    }

    return 0;
}
