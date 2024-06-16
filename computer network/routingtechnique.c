#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine the class of an IP address
char determineClass(const char *ip) {
    unsigned int firstOctet;
    sscanf(ip, "%u", &firstOctet);
    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else {
        return 'E';
    }
}

// Function to print IP address in dotted decimal format
void printIp(const unsigned char ip[]) {
    printf("%u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
}

// Function to parse IP address from dotted decimal format to array of bytes
void parseIp(const char *ipStr, unsigned char ip[]) {
    sscanf(ipStr, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

int main() {
    char sourceIpStr[16], destinationIpStr[16];
    unsigned char sourceIp[4], destinationIp[4];

    // User input for source and destination IP addresses
    printf("Enter the source IP address in dotted decimal format: ");
    scanf("%15s", sourceIpStr);
    printf("Enter the destination IP address in dotted decimal format: ");
    scanf("%15s", destinationIpStr);

    // Determine the class of each IP address
    char sourceClass = determineClass(sourceIpStr);
    char destinationClass = determineClass(destinationIpStr);

    // Parse IP addresses to arrays of bytes
    parseIp(sourceIpStr, sourceIp);
    parseIp(destinationIpStr, destinationIp);

    // Print results
    printf("\nSource IP Address: ");
    printIp(sourceIp);
    printf("\nClass of Source IP Address: %c\n", sourceClass);

    printf("\nDestination IP Address: ");
    printIp(destinationIp);
    printf("\nClass of Destination IP Address: %c\n", destinationClass);

    return 0;
}
