#include <stdio.h>
#include <string.h>

int main(int args) {
    char nomFichier[100] = "C:/Users/mkltr/CLionProjects/Tp5/testecriture";

    FILE *file;
    file = fopen(nomFichier,"r");
    char fileContent[100]="";
    if (file== NULL) {
        printf("Error: File not found.");
        return 1;
    }

    while (fgets(fileContent, 100, file) != NULL){
        printf("%s",fileContent);
    }

    FILE *fileWriting;

    fileWriting= fopen(nomFichier,"w");

    char chosesAEcrire[]="";
    printf("Saisis ce que tu veux écrire dans ce fichier");

    fgets(chosesAEcrire,100,stdin);

    fprintf(fileWriting,"%s",chosesAEcrire);

    fclose(file);
    fclose(fileWriting);
    return 0;
}
