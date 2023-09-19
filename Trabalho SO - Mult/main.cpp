#include <iostream>
#include <pthread.h>
#include <time.h>

using namespace std;

float mat1[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
float mat2[3][3] = {{9, 6, 3}, {8, 5, 2}, {7, 4, 1}};
float matRes[3][3];
float matRes2[3][3];

void *th_mult(void *arg) {


    /// MULTIPLICAÇÃO MATRICIAL
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++) {
                matRes[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matRes[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    /// MULTIPLICAÇÃO POSICIONAL
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matRes2[i][j] = mat1[i][j] * mat2[i][j];
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << matRes2[i][j] << " ";
        }
        cout << endl;
    }
    pthread_exit(0);
}

double time1, timedif;

int main()
{
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;

    pthread_t tid_mult;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid_mult, &attr, th_mult, NULL);
    pthread_join(tid_mult, NULL);

    cout << endl;
    cout << "thread finalizada";

    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    cout << endl << "tempo: " << timedif;

    return 0;
}
