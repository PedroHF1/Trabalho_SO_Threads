#include <iostream>
#include <pthread.h>
#include <time.h>

using namespace std;

    int arr[200];

void *th_ini (void *arg) {
    for (int i = 0; i < 200; i++) {
        arr[i] = 200 - i;
    }

    for (int i = 0; i < 200; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    pthread_exit(0);
}

void *th_ord (void *arg) {
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
    pthread_exit(0);
}

void *th_print (void *arg) {
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

    pthread_t tid_ini, tid_ord, tid_print;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid_ini, &attr, th_ini, NULL);
    pthread_join(tid_ini, NULL);
    pthread_create(&tid_ord, &attr, th_ord, NULL);
    pthread_join(tid_ord, NULL);
    pthread_create(&tid_print, &attr, th_print, NULL);
    pthread_join(tid_print, NULL);

    cout << endl;
    cout << "threads finalizadas";

    timedif = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    cout << endl << "tempo: " << timedif;

    return 0;
}
