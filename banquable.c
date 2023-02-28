//
// Created by mkltr on 2/28/2023.
//
#include <stdlib.h>
#include <stdio.h>

struct ST_Compte {
    char NomClient[32];
    int Solde;
    int NbreOperations;
};


void SaisieCompte(struct ST_Compte *compte);

void AfficherCompte(struct ST_Compte *compte) ;
void AjoutCompte(char *nomFichier, struct ST_Compte *compte);

        int main(){
    FILE *banqueTxt;
    char fichierChemin[25] ="C:\\Users\\mkltr\\CLionProjects\\Tp5\\banque.txt";
    banqueTxt= fopen(fichierChemin,"r");

    printf("coucou");
    return 0;
}

// Fonction pour saisir les informations d'un compte
void SaisieCompte(struct ST_Compte *compte) {
    printf("Nom du client : ");
    scanf("%s", compte->NomClient);
    printf("Solde du compte : ");
    scanf("%d", &compte->Solde);
    printf("Nombre d'opérations : ");
    scanf("%d", &compte->NbreOperations);
}

// Fonction pour afficher les informations d'un compte
void AfficherCompte(struct ST_Compte *compte) {
    printf("Nom du client : %s\n", compte->NomClient);
    printf("Solde du compte : %d\n", compte->Solde);
    printf("Nombre d'opérations : %d\n", compte->NbreOperations);
}

// Fonction pour ajouter les informations d'un compte dans le fichier
void AjoutCompte(char *nomFichier, struct ST_Compte *compte) {
    FILE *fichier = fopen(nomFichier, "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(fichier, "%s;%d;%d\n", compte->NomClient, compte->Solde, compte->NbreOperations);
    fclose(fichier);
}