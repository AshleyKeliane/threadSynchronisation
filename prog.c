/*   Noms et prenoms: Manjanjoh Tamanjong Ashley Keliane  */
/*   NO etudiant: 300327351   */

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int turn;
int a; // Number of full cycles
int b;

void* threads_function(void *arg) {
        pthread_mutex_t lock;

         int thread_id = *(int*)arg;  //taking id of threads

         for (int i = 0; i < a; i++) {
            while (turn != thread_id); // Busy wait
            
            pthread_mutex_lock(&lock);

            if (thread_id==0) b=b+1;
            if (thread_id==1) b=b+2;
            if (thread_id==2) b=b+3;
            if (thread_id==3) b=b+4;

            printf("Thread %d \n", thread_id);
            turn = (turn + 1) % 4; // Move to the next thread
            pthread_mutex_unlock(&lock);
    }

    return NULL;


    }



int main(){



        pthread_t threads[4];    // main thread creating 4 other threads
        int thread_ids[4] = {0, 1, 2, 3};

        for (int i = 0; i < 4; i++) {
            pthread_create(&threads[i], NULL, threads_function, &thread_ids[i]); 
            }



        for (int i = 0; i < 4; i++) {
            pthread_join(threads[i], NULL);
            }

    }

    




