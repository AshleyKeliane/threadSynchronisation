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
pthread_mutex_t lock;

void* threads_function(void *arg) {

         int thread_id = *(int*)arg;  //taking id of threads

         for (int i = 0; i < a; i++) {
            while (turn != thread_id); // Busy wait
            
            pthread_mutex_lock(&lock); //debut CS

            if (thread_id==0) b=b+1;
            if (thread_id==1) b=b+2;
            if (thread_id==2) b=b+3;
            if (thread_id==3) b=b+4;

            printf("Thread %d \n", thread_id);
            turn = (turn + 1) % 4; // Move to the next thread
            pthread_mutex_unlock(&lock);  // fin CS
    }

    return NULL;


    }
    
    void *thr0(void *arg) {
        int thread_id = *(int*)arg;
        pthread_mutex_lock(&lock);
        b=b+1;
        printf("Thread %d \n", thread_id);
        turn = (turn + 1) % 4; // Move to the next thread
        pthread_mutex_unlock(&lock);
        return NULL;
    }
    
    
    void *thr1(void *arg) {
        int thread_id = *(int*)arg;
        pthread_mutex_lock(&lock);
        b=b+2;
        printf("Thread %d \n", thread_id);
        turn = (turn + 1) % 4; // Move to the next thread
        pthread_mutex_unlock(&lock);
    return NULL;
    }
    

    void *thr2(void *arg) {
        int thread_id = *(int*)arg;
        pthread_mutex_lock(&lock);
        b=b+3;
        printf("Thread %d \n", thread_id);
        turn = (turn + 1) % 4; // Move to the next thread
        pthread_mutex_unlock(&lock);
    return NULL;
    }
    

    void *thr3(void *arg) {
        int thread_id = *(int*)arg;
        pthread_mutex_lock(&lock);
        b=b+4;
        printf("Thread %d \n", thread_id);
        turn = (turn + 1) % 4; // Move to the next thread
        pthread_mutex_unlock(&lock);
    return NULL;
    }



int main(){
    

        pthread_t threads[4];    // main thread creating 4 other threads
        int thread_ids[4] = {0, 1, 2, 3};

        // Initialize the mutex
        pthread_mutex_init(&lock, NULL);
        
        pthread_create(&threads[0], NULL, thr0, &thread_ids[0]); 
        pthread_create(&threads[1], NULL, thr1, &thread_ids[1]); 
        pthread_create(&threads[2], NULL, thr2, &thread_ids[2]); 
        pthread_create(&threads[3], NULL, thr3, &thread_ids[3]); 



        for (int i = 0; i < 4; i++) {
            pthread_join(threads[i], NULL);
            }


            // Clean up mutex
            pthread_mutex_destroy(&lock);

    }

    




