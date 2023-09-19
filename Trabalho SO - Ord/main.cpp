#include <iostream>
#include <pthread.h>
#include <time.h>

using namespace std;

    int arr[200];

void *th_ord (void *arg) {
    for (int i = 0; i < 200; i++) {
        arr[i] = 200 - i;
    }

    for (int i = 0; i < 200; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    // Ordenando o vetor usando Bubble Sort
    for (int i = 0; i < 200 - 1; i++) {
        for (int j = 0; j < 200 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Trocando os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Imprimindo o vetor ordenado
    for (int i = 0; i < 200; i++) {
        cout << arr[i] << " ";
    }
     pthread_exit(0);
}

double time1, timedif;

int main()
{
    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;

    pthread_t tid_ord;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid_ord, &attr, th_ord, NULL);
    pthread_join(tid_ord, NULL);

    cout << endl;
    cout << "thread finalizada";

    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    cout << endl << "tempo: " << timedif;

    return 0;
}
