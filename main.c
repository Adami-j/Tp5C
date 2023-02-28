#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void creerFIchier();
int recupereCSV();
int main(int args) {
    char nomFichierr[100] = "C:/Users/mkltr/CLionProjects/Tp5/testecriture";

    FILE *file;
    file = fopen(nomFichierr,"r");
    char fileContent[100]="";
    if (file== NULL) {
        printf("Error: File not found.");
        return 1;
    }

    //FILE *fileWriting;

    //fileWriting= fopen(nomFichier,"w");

    char chosesAEcrire[]="";
    //printf("Saisis ce que tu veux écrire dans ce fichier");

   // fgets(chosesAEcrire,100,stdin);

    //fprintf(fileWriting,"%s",chosesAEcrire);

    fclose(file);
   // fclose(fileWriting);

    char nomFichier[100] = "C:/Users/mkltr/CLionProjects/Tp5/testecriture";
    char buffer[100] = "";
    FILE *fileGo;
    fileGo = fopen(nomFichier, "r+b");
    fseek(fileGo, 0, SEEK_SET);
    int c;
    while ((c = fgetc(fileGo)) != EOF) {
        fputc(toupper(c), fileGo);
    }
    fseek(fileGo, 0, SEEK_SET);
    while (fgets(buffer, 100, fileGo)) {
        printf("%s", buffer);
    }

    fclose(fileGo);
    creerFIchier();
    recupereCSV();
    return 0;
}

void creerFIchier(){
    FILE *fileNew;
    char nomFichier[100] = "C:/Users/mkltr/CLionProjects/Tp5/testCreation";
    fileNew = fopen(nomFichier,"w+");

    char phrase[]="Salut zoubi";
    char phrasse[]="Salut zoubite";
    fgets(phrase,100,fileNew);
    fprintf(fileNew,"%s\n",phrase);

    printf("%d\n", ftell(fileNew));
    fseek(fileNew, 0, SEEK_SET);
    printf("%d\n", ftell(fileNew));
    fprintf(fileNew,"%s\n",phrasse);

    fclose(fileNew);
}

int recupereCSV(){
    struct Personne {
        char nom[50];
        char prenom[50];
        int age;
        char email[100];
    };
    int MAX_PERSONNES = 5;

    struct Personne personne[5];

    FILE *fileNew;
    char buffer[100]="";
    int nbp = 0;
    char nomFichier[100] = "C:/Users/mkltr/CLionProjects/Tp5/test.csv";
    fileNew = fopen(nomFichier,"r");
    struct Personne personnes[MAX_PERSONNES];
    int nb_personnes = 0;

    char ligne[200];
    while (fgets(ligne, sizeof(ligne), fileNew) != NULL) {
        char* nom = strtok(ligne, ";");
        char* prenom = strtok(NULL, ";");
        char* age_str = strtok(NULL, ";");
        char* email = strtok(NULL, ";");

        int age = atoi(age_str);

        struct Personne p;
        strcpy(p.nom, nom);
        strcpy(p.prenom, prenom);
        p.age = age;
        strcpy(p.email, email);

        personnes[nb_personnes++] = p;
    }



    for (int i = 0; i < nb_personnes; i++) {
        printf("%s %s (%d ans) - %s\n", personnes[i].prenom, personnes[i].nom, personnes[i].age, personnes[i].email);
    }
     struct Personne p2;
    strcpy(p2.nom, "Doe");
    strcpy(p2.prenom, "John");
    p2.age = 30;
    strcpy(p2.email, "john.doe@gmail.com");

     fileNew = fopen(nomFichier,"a");
    if (fileNew == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fileNew, "%s;%s;%d;%s\n", p2.nom, p2.prenom, p2.age, p2.email);

    fclose(fileNew);

    fclose(fileNew);


    return 0;
}

