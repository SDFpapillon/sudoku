#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mins {
    int x;
    int y;
    int n;
    int* h;
} mins;

typedef int sudoku[9][9];

/*Affiche la grille actuelle du sudoku passé en paramètre*/
void afficherSudoku(sudoku s)
{
  {
  for (int i=0; i<9; i++){
    for (int y=0; y<9; y++){
      if (s[i][y] == 0) {
      printf("\033[31m%i ", 0);
      }
      else {
        printf("\033[0m%i ",s[i][y]);
      }
    }
    printf("\033[0m\n");
  }
}
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
    int sx = (x/3);
    int sy = (y/3);
    for (int i = 0; i<3; i++){
        for (int k = 0; k<3; k++){
            if (n == s[3*sx+i][3*sy+k]) {
                return false;
            }
        }
    }
    return true;
}


/* Vérifie s'il est valide de poser la valeur n en x et y en fonction de tous les éléments déjà présents
appelle les fonctions estValideH, estValideV, estValideR, */
bool estValide(sudoku s, int x, int y, int n)
{
  return estValideH(s, x, y, n) && estValideV(s, x, y, n) && estValideR(s, x, y, n) && s[x][y] == 0;
}

/*nombre de cases encore vides sur la grille de sudoku */
int compterLibres(sudoku s)
{
    int acc = 0;
    for (int i = 0; i < 9; i++) {
        for (int j =0; j < 9; j++) {
            if (s[i][j] == 0) {
                acc++;
            }
        }
    }

  return acc;
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


mins mini_hypo(sudoku s){
    int min=9;
    int x=10;
    int y=10;
    int* minh;
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            int a = 0;
            int h[9];
            for (int k = 0; k < 9; k++)
            {
                if (estValide(s, i, j, k)){
                    h[a] = k;
                    a++;
                }
            }
            if (a<min){
                minh = h;
                x = i;
                y = j;
            }
        }
    }
    return (mins){
        .x=x,
        .y=y,
        .n=min,
        .h=minh
    };
}


int** resoudreSudoku(sudoku s)
{
  if (compterLibres(s) == 0) {
    return s;
  }
  else {

    mins hypothese = mini_hypo(s);

    int x = hypothese.x;
    int y = hypothese.y;

    if (hypothese.n == 0){
      return s;
    }

    else if (hypothese.n == 1) {
      s[x][y] = hypothese.h[0];

      return resoudreSudoku(s);
    }
    else {
      int n = 0;
      int n_max = hypothese.n;

      for(n; n<n_max; n++) {
        s[x][y] = hypothese.h[n];
        int** s_ = malloc(10);
        s_ = resoudreSudoku(s);
        if (compterLibres(s_) == 0) {
            return s_;
        }
      }

    }

  }
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

  sudoku s = {
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

  afficherSudoku(resoudreSudoku(s));

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

  int entreeX = 0;
  int entreeY = 0;
  int entreeV = 0;
  int nombre0 = compterLibres(sudoku1);
  int nombre0_ = nombre0;

  while(nombre0 != 0) {
    printf("il vous reste, %d (%d %%) nombre a trouver \n \nvoici la grille : \n", nombre0, 100*(nombre0)/nombre0_);
    afficherSudoku(sudoku1);
    lireAction(&entreeX, &entreeY, &entreeV);



    if (estValide(sudoku1, entreeX, entreeY, entreeV)) {
        sudoku1[entreeX][entreeY] = entreeV;
        nombre0 = nombre0 - 1;
    }
    else {
        printf("entree non valide, vous vous etes trompe \n \n");
    }
  }


  printf("bravo tu as gagner! \n");

  return 0;
}
