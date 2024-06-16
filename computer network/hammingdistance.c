#include <stdio.h>
#include <string.h>
int hammingDist(char* str1, char* str2) {
    int i, count = 0;
    int len = strlen(str1);
    for (i = 0; i < len; i++) {
        if (str1[i] != str2[i])
            count++;
    }
    return count;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first binary string: ");
    scanf("%s", str1);

    printf("Enter the second binary string: ");
    scanf("%s", str2);

    if (strlen(str1) != strlen(str2)) {
        printf("Error: Binary strings are not of equal length.\n");
        return 1;
    }

    printf("Hamming Distance: %d\n", hammingDist(str1, str2));
    return 0;
}
