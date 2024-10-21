#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

// SOMME DE I3
void somme_i3_ON(long int N) {
    
    long int somme = 0;

    for (int i = 0; i < N; i++)
    {
        somme += i*i*i;
    }
    
}


// SOMME DE I3
void somme_i3_O1(long int N) {

    long int somme = (N * (N - 1) / 2);
    somme = somme * somme;

}



// SOMME DE I2
void somme_i2_ON(long int N) {
    
    long int somme = 0;

    for (int i = 0; i < N; i++)
    {
        somme += i*i;
    }
    
}

void somme_i2_O1(long int N) {
    
    long int somme = (N * (N - 1) * (2 * N - 1)) / 6;
    
}

// SOMME DE I

void somme_i_ON(long int N) {
    
    long int somme = 0;

    for (int i = 0; i < N; i++)
    {
        somme += i;
    }
    
}

void somme_i_O1(long int N) {

    long int somme = (N * (N - 1)) / 2; 
}

// TEST ALGO

double testAlgo(void (*callback)(long int), long int N)
{
    double debut = clock();

    callback(N);

    double fin = clock();
    return (fin - debut) / CLOCKS_PER_SEC;
}


int main() {

    // DECLARATION
    FILE *fpt;
    FILE *fpt1;
    FILE *fpt2;

    // FPT

    fpt = fopen("somme_i.csv", "w+");
    fpt1 = fopen("somme_i2.csv", "w+");
    fpt2 = fopen("somme_i3.csv", "w+");

    //FPRINTF

    fprintf(fpt, "valeur, O(N), O(1)\n");
    fprintf(fpt1, "valeur, O(N), O(1)\n");
    fprintf(fpt2, "valeur, O(N), O(1)\n");

    //FCLOSE

    fclose(fpt);
    fclose(fpt1);
    fclose(fpt2);

    //FOPEN APPEND

    fpt = fopen("somme_i.csv", "a+");
    fpt1 = fopen("somme_i2.csv", "a+");
    fpt2 = fopen("somme_i3.csv", "a+");

    //FPRINTF AND TEST ALGOS

    for (long int i = 22091; i < 60000; i=i+200)
    {
        double temps1 = testAlgo(somme_i_ON, i); 
        double temps2 = testAlgo(somme_i_O1, i);
        
        double temps11 = testAlgo(somme_i2_ON, i); 
        double temps12 = testAlgo(somme_i2_O1, i); 

        double temps21 = testAlgo(somme_i3_ON, i);
        double temps22 = testAlgo(somme_i3_O1, i);
        

        fprintf(fpt, "%ld, %f, %f", i, temps1, temps2);
        fprintf(fpt1, "%ld, %f, %f", i, temps11, temps21);
        fprintf(fpt2, "%ld, %f, %f", i, temps21, temps22);


        fprintf(fpt, "\n");
        fprintf(fpt1, "\n");
        fprintf(fpt2, "\n");
    }

    fclose(fpt);
}
