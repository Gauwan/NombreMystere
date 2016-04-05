#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * Fonction contenant le choix de la difficulté
 *
 * Retour : la difficulté choisie
 */
int fctDifficulty() {
    int level = 0;
    while (level == 0)
    {
        printf("Choisir sa difficulte: \n");
        printf("1 - Facile \n");
        printf("2 - Moyen \n");
        printf("3 - Difficile \n");
        printf("Quel difficulte : ");
        scanf("%d", &level);
        switch (level)
        {
            case 1:
                level = 10;
                break;
            case 2:
                level = 100;
                break;
            case 3:
                level = 1000;
                break;
            default:
                level = 0;
                break;
        }
    }
    return level;
}

/**
 * Fonction contenant le jeu
 *
 * Paramètres : la difficulté demandée par l'utilisateur
 */
void fctGame(int difficulty) {
    //Le joueur est initialisé à -1 pour éviter d'être égal au nombre
    int player = -1;
    //Le nombre mystère est initialisé avec la difficulté
    int number = rand()%difficulty;
    //La variable games représente le compte tours
    int games = 0;

    while (player != number)
    {
        printf("Entrez un nombre entre 0 et %d : ",difficulty);
        scanf("%d", &player);
        if (player > number && player <= 100)
            printf("C'est moins. \n");
        else if (player < number && player >= 0)
            printf("C'est plus. \n");
        else if (player < 0 || player > 100)
            printf("Le nombre doit etre entre 0 et %d!\n",difficulty);

        games++;
    }

    printf("Vous avez gagne, vous avez reussi en %d coups.\n",games);
}

int main() {
    //Utilisation du temps pour la génération du nombre aléatoire
    srand(time(NULL));
    printf("Bienvenue sur Plus ou Moins! \n");
    //Booléen initialisé à "jeu en cours"
    int inGame = 1;

    while (inGame != 0)
    {
        //Appel de la fonction qui détermine la difficulté
        int difficulty = fctDifficulty();

        //Appel du jeu avec la difficulté
        fctGame(difficulty);

        //Choix de fin de jeu
        printf("Entrez 0 pour quitter (Sinon le jeu recommence).");
        scanf("%d", &inGame);
    }
    return 0;
}