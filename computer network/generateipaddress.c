#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int ind = 0;
int ia[36];

void print(int *a){
    for(int i = 0; i < 32; i++){
        printf("%d", a[i]);
        if((i + 1) % 8 == 0 && i != 0 && i != 31)
            printf(".");
    }
    printf("\n");
}

void nextipaddress(int m){
    int b[32] = {0};
    b[31] = 1;
    int c = 0;
    int s = 0;
    for(int i = 31; i >= 0; i--){
        s = b[i] + ia[i] + c;
        c = s / 2;
        s = s % 2;
        ia[i] = s;
    }
}

void allIpaddress(int m){
    int sub = 32 - m;
    for(int i = m; i < 32; i++){
        ia[i] = 0;
    }
    printf("All the ip addresses are:\n");
    print(ia);
    for(int i = 1; i < pow(2, sub); i++){
        nextipaddress(m);
        print(ia);
    }
}

void extractipaddress(unsigned char *source_string, short *ipaddress){
    unsigned short len = 0;
    unsigned char oct[4] = {0}, cnt = 0, cnt1 = 0, i, buf[5];
    len = strlen((const char *)source_string);
    for(i = 0; i < len; i++){
        if(source_string[i] != '.'){
            buf[cnt++] = source_string[i];
        }
        if(source_string[i] == '.' || i == len - 1){
            buf[cnt] = '\0';
            cnt = 0;
            oct[cnt1++] = atoi((const char *)buf);
        }
    }
    ipaddress[0] = oct[0];
    ipaddress[1] = oct[1];
    ipaddress[2] = oct[2];
    ipaddress[3] = oct[3];
}

void convertipaddresstobinary(short *ipad){
    int sum[32] = {0}; // Changed size to 32
    int ind = 0; // Moved ind inside the function
    for(int i = 0; i < 4; i++){
        int numb = ipad[i];
        for(int j = 7; j >= 0; j--){
            sum[ind++] = (numb >> j) & 1; // Extracting each bit
        }
    }
    for(int i = 0; i < 32; i++){
        ia[i] = sum[i];
    }
}

int main(){
    unsigned char ip[20] = {0};
    int m;
    short ipaddress[4];
    printf("Enter ip address (xxx.xxx.xxx.xxx format): ");
    scanf("%s", ip);
    printf("Enter the mask address: ");
    scanf("%d", &m);
    extractipaddress(ip, &ipaddress[0]);
    convertipaddresstobinary(ipaddress);
    printf("The ip address in binary is:\n");
    print(ia);
    allIpaddress(m);
    return 0;
}
