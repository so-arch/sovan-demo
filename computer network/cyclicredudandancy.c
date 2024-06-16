#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xorOperation(char *dividend, const char *divisor, int length) {
    for (int i = 0; i < length; i++) {
        dividend[i] = dividend[i] == divisor[i] ? '0' : '1';
    }
}

// Function to perform the division and obtain the CRC remainder
void computeCRC(char *data, char *divisor, char *remainder, int dataLen, int divisorLen) {
    char temp[dataLen + divisorLen - 1];
    strcpy(temp, data);
    
    for (int i = 0; i < divisorLen - 1; i++) {
        temp[dataLen + i] = '0';  // Append zeros at the end of data
    }

    for (int i = 0; i < dataLen; i++) {
        if (temp[i] == '1') {  // Perform division if the bit is 1
            xorOperation(temp + i, divisor, divisorLen);
        }
    }

    strncpy(remainder, temp + dataLen, divisorLen - 1);
    remainder[divisorLen - 1] = '\0';  // Null terminate the remainder
}

int main() {
    char data[100], divisor[100], remainder[100];
    int dataLen, divisorLen;

    // Input the data and divisor (generator polynomial)
    printf("Enter the data: ");
    scanf("%s", data);
    printf("Enter the divisor (generator polynomial): ");
    scanf("%s", divisor);

    dataLen = strlen(data);
    divisorLen = strlen(divisor);

    // Compute the CRC remainder
    computeCRC(data, divisor, remainder, dataLen, divisorLen);

    printf("CRC Remainder: %s\n", remainder);

    // Append remainder to data to get the transmitted frame
    char transmittedFrame[dataLen + divisorLen - 1];
    strcpy(transmittedFrame, data);
    strcat(transmittedFrame, remainder);

    printf("Transmitted frame: %s\n", transmittedFrame);

    // Simulate received data (for demonstration purposes, we assume it's received correctly)
    char receivedData[dataLen + divisorLen - 1];
    strcpy(receivedData, transmittedFrame);
    
    printf("Received data: %s\n", receivedData);

    // Verify at receiver's end by recomputing the CRC
    char receiverRemainder[100];
    computeCRC(receivedData, divisor, receiverRemainder, dataLen + divisorLen - 1, divisorLen);

    // If remainder is all zeros, then no error
    int error = 0;
    for (int i = 0; i < divisorLen - 1; i++) {
        if (receiverRemainder[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Error detected in received data.\n");
    } else {
        printf("No error detected in received data.\n");
    }

    return 0;
}
