#include <stdio.h>

int main() {
    char nomFichier[100] = "C:\\Users\\mkltr\\CLionProjects\\Tp5\\testecriture";

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
    return 0;
}
