#include <stdio.h>
#include <string.h>


typedef struct 
{
    char nama[25];
    int jarak;
} DataOrang;

DataOrang Listpeserta[100];
int tailListpeserta = -1;


int Banyakpeserta = 8;

int fileReader() {
    FILE* file = fopen("no2.txt","r");
    
    char nama[25];
    int jarak = 0;

    while (!feof(file)) {
        fscanf(file,"%s %d",&nama,&jarak);

        strcpy(Listpeserta[tailListpeserta+1].nama,nama);
        Listpeserta[tailListpeserta+1].jarak = jarak;

        tailListpeserta++;

        // printf("%s %d\n",nama,jarak);
    }


    fclose(file);
}

int main() {

    fileReader();


    for (int i = 0; i < tailListpeserta; i++ ) {
        for (int j = 0; j < tailListpeserta; j++){
            if (Listpeserta[j].jarak < Listpeserta[j+1].jarak) {

                int tempJarak = Listpeserta[j].jarak; 
                char tempNama[25];
                strcpy(tempNama,Listpeserta[j].nama);
                
                Listpeserta[j].jarak = Listpeserta[j+1].jarak ;
                strcpy(Listpeserta[j].nama,Listpeserta[j+1].nama);
                
                Listpeserta[j+1].jarak = tempJarak;
                strcpy(Listpeserta[j+1].nama,tempNama);
                // char tempNama = Listpeserta[i].jarak; 
            }
            // printf("%s %d", Listpeserta[i].nama,Listpeserta[i].jarak);
        }  
    }

    
    DataOrang best[10];
    char namaskrg[25];

    for (int i = 0; i < tailListpeserta+1; i++) {
        
    }

    // for (int i = 0; i < 8; i++ ) {
    //     // for (int j = 0; j < tailListpeserta; j++)
    //     for (int j = 0; j < tailListpeserta+1; j++) {
    //         // strcpy(namaskrg,)
    //     }
    //     printf("%s %d\n", Listpeserta[i].nama,Listpeserta[i].jarak);
    // }

    // for (int i = 0; i < tailListpeserta+1; i++) {
    //     if (strcmp(Listpeserta[i].nama,"no") == 0) {
    //         continue;
    //     } else {
    //         // char namaskrg[25];
    //         strcpy(namaskrg,Listpeserta[i].nama);
    //     }
    //     for (int j = i+1; j < tailListpeserta+1; j++) {
    //         if (strcmp(Listpeserta[j].nama,namaskrg) == 0) {
    //             strcpy(Listpeserta[j].nama,"no");
    //         } else {
                
    //             printf("%s %d\n", Listpeserta[j].nama,Listpeserta[j].jarak);
    //         }
    //     }
    // }


    



}
