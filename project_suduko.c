    #include <stdio.h>
    #include <stdbool.h>

    void Affiche_init(int M[9][9]) {
        printf("LX/CX    ");
        for (int j = 0; j < 9; j++) {
            printf("C%d ", j);
        }
        printf("\n");
        for (int i = 0; i < 9; i++) {
            printf("L%d \t", i);
            for (int j = 0; j < 9; j++) {
                if((j%3==0)&&(j!=0))
                printf("[");        
                else
                printf("|");
                printf("%d ", M[i][j]);
            }
            printf("\n");
            if(((i+1)%3 ==0)&&(i!=0))
            printf("___________________________________\n");
            else
            printf("-----------------------------------\n");
        }
    }

    int Saisie_Pos() {
        int l;
        do {
            scanf("%d", &l);
        } while ((l < 0) || (l > 8));
        return l;
    }

    int Saisie_Num() {
        int n;
        do {
            printf("Donnez le numero que vous voulez entrer : \n");
            scanf("%d", &n);
        } while ((n < 1) || (n > 9));
        return n;
    }

    bool ContientZero(int M[9][9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (M[i][j] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCorrect(int M[9][9], int l, int c, int num) {
    bool s = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (M[l][j] == num || M[i][c] == num) {
                    s=false;
                    return s ;
                }
            }
        }

        int startRow = l - l % 3;
        int startCol = c - c % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (M[i + startRow][j + startCol] == num) {
                     s=false;
                    return s;
                }
            }
        } 
        return s;
    
     
}

    int main() {
        int matrice[9][9] = {
            {0, 0, 0, 0, 0, 3, 9, 0, 8},
            {0, 6, 9, 0, 7, 0, 0, 0, 0},
            {0, 0, 0, 6, 0, 0, 5, 0, 0},
            {0, 2, 3, 0, 0, 7, 0, 8, 0},
            {0, 4, 0, 0, 0, 0, 0, 1, 0},
            {0, 9, 0, 3, 0, 0, 6, 2, 0},
            {0, 0, 1, 0, 0, 6, 0, 0, 0},
            {0, 0, 0, 0, 8, 0, 1, 4, 0},
            {6, 0, 7, 4, 0, 0, 0, 0, 0}
        };
        int l, c, n, nb=3;

        Affiche_init(matrice);
        do {
            printf("Donnez la ligne de la case  que vous voulez changer : \n");
            l = Saisie_Pos();
            printf("Donnez la colonne de la case  que vous voulez changer : \n");
            c = Saisie_Pos();
            n = Saisie_Num();
            if (isCorrect(matrice, l, c, n)==true)
                {matrice[l][c] = n;}
            else
            {nb--;
            printf("Ce numero est invalide\n ");
            printf("Il reste seulement %d essai(s)\n", nb);}

            printf("Nouvelle matrice :\n");
            Affiche_init(matrice);
        } while (ContientZero(matrice)==true && (nb > 0 && nb <= 3 ));
            if (ContientZero(matrice)==false)
        printf("Félicitations, vous avez gagné !\n");
        else
        {printf("Malheureusement, vous avez perdu !\n"); 
        }

        return 0;
    }
