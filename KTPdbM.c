#include <stdio.h>
#include <string.h>

typedef struct {
    char NIK[20];
    char Nama[255]; 
    char TTL[512];
    char JK[2];
    char Alamat[512];
    char Agama[64];
    char Pekerjaan[128];
} KTP;

KTP listData[64];
int tailIndex = -1;

int addData(char NIK[20],char Nama[255],char TTL[512],char JK[10],char Alamat[512], char Agama[64],char Pekerjaan[128]) {
    strcpy(listData[tailIndex+1].NIK,NIK);
    strcpy(listData[tailIndex+1].Nama,Nama);
    strcpy(listData[tailIndex+1].TTL,TTL);
    strcpy(listData[tailIndex+1].JK,JK);
    strcpy(listData[tailIndex+1].Alamat,Alamat);
    strcpy(listData[tailIndex+1].Agama,Agama);
    strcpy(listData[tailIndex+1].Pekerjaan,Pekerjaan);


    // printf("%s",listData[0].NIK);

    tailIndex += 1;

    return 0;
}

int removeData(char NIK[20]) {
    
    int dataIndex = -1;
    for (int i = 0; i < tailIndex + 1; i++) {
        if (strcmp(listData[i].NIK,NIK) == 0) {
            dataIndex = i;
        }
    }

    if (dataIndex == -1) {
        printf("data not found\n");
        return -1;
    }


    strcpy(listData[dataIndex].NIK,"NIL");
    strcpy(listData[dataIndex].Nama,"NIL");
    strcpy(listData[dataIndex].TTL,"NIL");
    strcpy(listData[dataIndex].JK,"NIL");
    strcpy(listData[dataIndex].Alamat,"NIL");
    strcpy(listData[dataIndex].Agama,"NIL");
    strcpy(listData[dataIndex].Pekerjaan,"NIL");


    // printf("%s",listData[0].NIK);
    return 1;
}

int showData(int index) {
    KTP dataNow = listData[index];
    printf("NIK: %s\nNama: %s\nTTL: %s\nJK: %s\nAlamat: %s\nAgama: %s\nPekerjaan: %s\n",dataNow.NIK,dataNow.Nama,dataNow.TTL,dataNow.JK,dataNow.Alamat,dataNow.Agama,dataNow.Pekerjaan);
}


int searchData(char NIK[20],int show) {
    int dataIndex = -1;
    for (int i = 0; i < tailIndex + 1; i++) {
        if (strcmp(listData[i].NIK,NIK) == 0) {
            dataIndex = i;
        }
    }
    if (dataIndex == -1) {
        printf("data not found\n");
        return -1;
    }

    printf("found data with NIK (%s) at index: %d\n",NIK, dataIndex);
    if (show) {
        showData(dataIndex);
    }
    return 1;
}

int main() {
    while (1) {
        char command[20];
        printf("\nenter command: "); scanf("%s",&command);
        if (strcmp(command,"add") == 0) {
            char NIK[20];
            char Nama[255]; 
            char TTL[512];
            char JK[2];
            char Alamat[512];
            char Agama[64];
            char Pekerjaan[128];
            
            printf("NIK: "); scanf("%s",&NIK);
            printf("Nama: ");scanf("%s",&Nama);
            printf("TTL: ");scanf("%s",&TTL);
            printf("JK(L/P): ");scanf("%s",&JK);
            printf("Alamat: ");scanf("%s",&Alamat);
            printf("Agama: ");scanf("%s",&Agama);
            printf("Pekerjaan: ");scanf("%s",&Pekerjaan);
            addData(NIK,Nama,TTL,JK,Alamat,Agama,Pekerjaan);
    
        } else if (strcmp(command,"remove") == 0) {
            char NIK[20];
            printf("enter NIK you want to remove: ");scanf("%s", &NIK);
            removeData(NIK);
    
        } else if (strcmp(command,"search") == 0) {
            char NIK[20];
            int show;
            printf("enter NIK you want to search: ");scanf("%s", &NIK);
            printf("want to show the data? (1 yes / 2 no): ");scanf("%d", &show);
            searchData(NIK,show);
    
        } else if (strcmp(command,"end") == 0) {
            break;
        }
    }


    return 1;
}



// int main() {
//     addData("a","a","a","a","a","a","a");
//     addData("b","b","b","b","b","b","b");
//     searchData("a",0);
//     searchData("b",1);
//     removeData("a");
//     searchData("a",1);
//     searchData("b",1);
    


//     return 1;

// }

