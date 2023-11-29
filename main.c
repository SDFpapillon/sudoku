#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int sudoku[9][9];

/*Affiche la grille actuelle du sudoku passé en paramètre*/
void afficherSudoku(sudoku s)
{
  // TODO: à implémenter
}

/*Vérifie s'il est valide de poser la valeur n en x et y en fonction des éléments déjà présents sur la ligne */
bool estValideH(sudoku s, int x, int y, int n)
{
    for(int i = 0; i<9; i++){
        if (n == s[x][i]){
            return false;
        }
    }

  return true;
}

/*Vérifie s'il est valide de poser la valeur n en x et y en fonction des éléments déjà présents sur la colonne*/
bool estValideV(sudoku s, int x, int y, int n)
{
    for(int i = 0; i<9; i++){
        if (n == s[i][y]){
            return false;
        }
    }

  return true;
}

/*Vérifie s'il est valide de poser la valeur n en x et y en fonction des éléments déjà présents sur la région (3x3)*/
bool estValideR(sudoku s, int x, int y, int n)
{



  return false;
    // TODO: à implémenter
}


/* Vérifie s'il est valide de poser la valeur n en x et y en fonction de tous les éléments déjà présents
appelle les fonctions estValideH, estValideV, estValideR, */
bool estValide(sudoku s, int x, int y, int n)
{

  return false;
    // TODO: à implémenter
}

/*nombre de cases encore vides sur la grille de sudoku */
int compterLibres(sudoku s)
{

  return 42;
  // TODO: à implémenter
}


int resoudreSudoku(sudoku s)
{
  // TODO: à implémenter - (BONUS)

  return 0;

}

/* Demande une action de résolution à l'utilisateur·rice
*
* Modifie les variables globales entreeX, entreeY, entreeV
* (coordonnées x et y et valeur) On utilise des pointeurs car
* on ne sait pas "retourner un triplet",*/
/*Cette fonction vous est donnée*/

bool lireAction(int* entreeX, int* entreeY, int* entreeV)
{
  printf("Quelle case voulez-vous modifier?\n");
  printf("ligne=?");
  scanf("%d",entreeX);
  printf("colonne=?");
  scanf("%d",entreeY);
  printf("valeur=?");
  scanf("%d",entreeV);

  // Un peu de vérifications pour ne pas faire n'importe quoi.
  if (*entreeX <0 || *entreeX > 8 || *entreeY <0 || *entreeY > 8
      || *entreeV <1 || *entreeV >9){
    printf("demande d'action invalide (on sort des bornes)\n");
    return false;
  }

  return true;
}


/* Dans ce main, on affiche le sudoku à résoudre, et
   l'utilisateur·rice essaie de le résoudre interactivement en donnant
   x, y et une valeur, tant qu'il ne reste pas de case vide.
   On passe sudoku1 en paramètre de chacune des fonctions.
*/
int main()
{
  // Nous vous fournissons un sudoku à résoudre.
  sudoku sudoku1 = {
    { 0, 9, 4, 2, 0, 6, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 4, 0, 1, 0 },
    { 7, 8, 0, 3, 0, 0, 2, 0, 0 },
    { 0, 4, 3, 0, 7, 5, 1, 8, 2 },
    { 8, 5, 6, 0, 3, 2, 9, 0, 4 },
    { 0, 0, 0, 0, 9, 8, 0, 6, 0 },
    { 0, 0, 7, 8, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 3, 4, 0, 7},
    { 4, 6, 0, 0, 0, 0, 0, 3, 1}
  };

  // Solution du sudoku1 -
  /*
    3 9 4 2 1 6 7 5 8
    6 2 5 7 8 4 3 1 9
    7 8 1 3 5 9 2 4 6
    9 4 3 6 7 5 1 8 2
    8 5 6 1 3 2 9 7 4
    1 7 2 4 9 8 5 6 3
    2 3 7 8 4 1 6 9 5
    5 1 8 9 6 3 4 2 7
    4 6 9 5 2 7 8 3 1
  */


  // TODO : implémenter l'interaction avec l'utilisateur·rice
  // pour réaliser le jeu interactif.

  return 0;
}
