#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX 5

struct Queue {
    int rear;
    int items[QUEUE_MAX];
};

typedef struct Queue queue_t;

void queue_insert(queue_t * q, int elm){
    q->rear += 1;
    q->items[q->rear] = elm;
    // forma mais rebuscada q->items[++q->rear] = elm;
}

int queue_remove(queue_t * q){
    int aux = q->items[0];
    //q->items[q->front] = -1;
    /*
    for(int i = 0; i < QUEUE_MAX; i++){
        q->items[i] = q->items[i+1];
    }
    q->rear--;
    */
    for(int i = 0; i < q->rear; i++){
        q->items[i] = q->items[i+1];
		//q->items[i+1] = -1;
    }
    
    q->items[q->rear] = -1;
    q->rear--;
    //q->front += 1;
    return aux;
}

bool is_empty(queue_t * q){
    return q->rear == -1;
}

int queue_print(queue_t * q){
	int i = 0;
	printf("[");
	for(i = 0; i<QUEUE_MAX; i++){
		printf(" %d ", q->items[i]);
	}
	printf("]");
	printf("\n");
}

int main() {
    queue_t q;
    // inicialização da Fila
    //q.front = 0;
    q.rear = -1;
    
    int elm;
    
    for(int i = 0; i < QUEUE_MAX; i++){
        q.items[i] = -1;
    }
    
    queue_print(&q);
    queue_insert(&q, 10);   queue_print(&q);
    queue_insert(&q, 20);   queue_print(&q);
    queue_insert(&q, 30);   queue_print(&q);
    
    elm = queue_remove(&q);  queue_print(&q);
    elm = queue_remove(&q);  queue_print(&q);
    elm = queue_remove(&q);  queue_print(&q);

    queue_insert(&q, 40);   queue_print(&q);
    queue_insert(&q, 50);   queue_print(&q);
    
    elm = queue_remove(&q);  queue_print(&q);
    elm = queue_remove(&q);  queue_print(&q);
    printf("Rear = %d", q.rear);
    
    return 0;
}
