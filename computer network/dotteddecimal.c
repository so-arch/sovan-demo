#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary (8 bits)
void decimalToBinary(unsigned int decimal, char *binary) {
    int i = 7;
    while (decimal > 0) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i--;
    }
    // Add leading zeros if necessary
    while (i >= 0) {
        binary[i] = '0';
        i--;
    }
}

// Function to convert dotted decimal IP address to 32-bit binary IP address
void ipToBinary(const char *ip, char *binaryIp) {
    unsigned int octets[4];
    sscanf(ip, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]);
    for (int i = 0; i < 4; i++) {
        char binaryOctet[9]; // 8 bits + '\0'
        decimalToBinary(octets[i], binaryOctet);
        strcat(binaryIp, binaryOctet);
    }
}

// Function to determine the class of the IP address
char determineClass(const char *binaryIp) {
    if (binaryIp[0] == '0') {
        return 'A';
    } else if (binaryIp[1] == '0') {
        return 'B';
    } else if (binaryIp[2] == '0') {
        return 'C';
    } else if (binaryIp[3] == '0') {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    char ip[16];
    char binaryIp[33]; // 32 bits + '\0'
    char ipClass;

    // User input for IP address
    printf("Enter the IP address in dotted decimal format: ");
    scanf("%15s", ip);

    // Convert IP address to binary
    ipToBinary(ip, binaryIp);

    // Determine the class of the IP address
    ipClass = determineClass(binaryIp);

    // Print the result
    printf("\nIP Address: %s\n", ip);
    printf("32-bit Binary IP Address: %s\n", binaryIp);
    printf("Class of IP Address: %c\n", ipClass);

    return 0;
}
