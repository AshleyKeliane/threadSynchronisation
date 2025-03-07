/*   Noms et prenoms: Manjanjoh Tamanjong Ashley Keliane  */
/*   NO etudiant: 300327351   */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int turn; // var globales
int a;  
int b;    


void *thr0(void *arg) {
    pthread_mutex_t lock; 
    for (int i = 0; i < a; i++) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (turn == 0) { // Check if it's this thread's turn
                b += 1;
                printf("Thr0, (b+1=%d)\n", b);
                turn = 1; // Set turn to the next thread
                pthread_mutex_unlock(&lock);
                break;
            }
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

void *thr1(void *arg) {
    pthread_mutex_t lock; //var mutex local
    for (int i = 0; i < a; i++) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (turn == 1) {
                b += 2;
                printf("Thr1, (b+2=%d)\n", b);
                turn = 2;
                pthread_mutex_unlock(&lock);
                break;
            }
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

void *thr2(void *arg) {
    pthread_mutex_t lock; 
    for (int i = 0; i < a; i++) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (turn == 2) {
                b += 3;
                printf("Thr2, (b+3=%d)\n", b);
                turn = 3;
                pthread_mutex_unlock(&lock);
                break;
            }
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

void *thr3(void *arg) {
    pthread_mutex_t lock; 
    for (int i = 0; i < a; i++) {
        while (1) {
            pthread_mutex_lock(&lock);
            if (turn == 3) {
                b += 4;
                printf("Thr3, (b+4=%d)\n", b);
                turn = 0; // Loop back to the first thread
                pthread_mutex_unlock(&lock);
                break;
            }
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}


void fibonacciCalcul(int val) {

int prev1 = 1;
int prev2 = 1;

for (int i = 1; i <= val; i++) {
    

  if (i > 2) {
      int curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
      printf("%d ", curr);
  }
  else if (i == 1)
      printf("%d ", prev2);
  else if (i == 2)
      printf("%d ", prev1);
}

}



int main(){
    pthread_mutex_t lock;

    int vala, valb, thrNum;
    printf("Enter an integer a value : ");
    scanf("%d", &vala);
    printf("Enter an integer b value : ");
    scanf("%d", &valb);
    printf("Enter the thread # to start first (0 to 3) : ");
    scanf("%d", &thrNum);

    turn =thrNum;
    a=vala;
    b=valb;


        pthread_t threads[4];    // main thread creating 4 other threads
        int thread_ids[4] = {0, 1, 2, 3};

        // Initialize the mutex
        pthread_mutex_init(&lock, NULL);
        
        pthread_create(&threads[0], NULL, thr0, &thread_ids[0]); 
        pthread_create(&threads[1], NULL, thr1, &thread_ids[1]); 
        pthread_create(&threads[2], NULL, thr2, &thread_ids[2]); 
        pthread_create(&threads[3], NULL, thr3, &thread_ids[3]); 



        for (int i = vala-1; i < vala+4; i++) {
            pthread_join(threads[(i+1)%4], NULL);  //wait for threads to finish
            }


            // Clean up mutex
            pthread_mutex_destroy(&lock);
            printf("Parent, (b=%d)\n", b);


            fibonacciCalcul(b);
            return 0;

    }

    




