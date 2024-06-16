#include <stdio.h>
#include <string.h>
#include <limits.h>

// Function to compute Hamming distance between two binary strings
int hammingDistance(const char *str1, const char *str2, int length) {
    int distance = 0;
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}

// Function to compute the minimal Hamming distance for a set of binary strings
int computeMinimalHammingDistance(char strings[][100], int numStrings, int stringLength) {
    int minDistance = INT_MAX;

    // Compare each pair of strings
    for (int i = 0; i < numStrings; i++) {
        for (int j = i + 1; j < numStrings; j++) {
            int distance = hammingDistance(strings[i], strings[j], stringLength);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
    }

    return minDistance;
}

int main() {
    int numStrings, stringLength;
    printf("Enter the number of binary strings: ");
    scanf("%d", &numStrings);
    printf("Enter the length of each binary string: ");
    scanf("%d", &stringLength);

    char strings[numStrings][100];

    // Input binary strings
    for (int i = 0; i < numStrings; i++) {
        printf("Enter binary string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    // Compute minimal Hamming distance
    int minHammingDistance = computeMinimalHammingDistance(strings, numStrings, stringLength);

    printf("Minimal Hamming Distance (d_min): %d\n", minHammingDistance);

    return 0;
}
