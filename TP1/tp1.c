#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>


// N 

bool premierN(long int N) {
    
    for (long int i = 2; i < N; i++) { 
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;

}

// N/2

bool premierNsur2(long int N) {
    
    for (long int i = 2; i < (N/2); i++) { 
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;

}

// sqrt(N)

bool premierSqrtN(long int N) {
    long int sq = sqrt(N);
    for (long int i = 2; i <sq ; i++) { 
        if (N % i == 0)
        {
            return false;
        }
    }
    return true;
    
}


// Time execution Algo

double testAlgo(bool (*callback)(long int), long int N)
{
    double debut = clock();

    callback(N);

    double fin = clock();
    return (fin - debut) / CLOCKS_PER_SEC;
}





int main() {
    FILE *fpt;
    
    fpt = fopen("MyFile.csv", "w+");
    fprintf(fpt, "'valeur', 'N', 'N/2', 'racine de N'\n");
    fclose(fpt);

    fpt = fopen("MyFile.csv", "a+");

    for (long int i = 22091; i < 90202; i=i+200)
    {
        double temps1 = testAlgo(premierN, i); 
        double temps2 = testAlgo(premierNsur2, i); 
        double temps3 = testAlgo(premierSqrtN, i); 

        fprintf(fpt, "%ld, %f, %f, %f", i, temps1, temps2, temps3);
        fprintf(fpt, "\n");
    }

    fclose(fpt);
    

    return 0;
}
