#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX 5

struct Queue {
    int front, rear;
    int items[QUEUE_MAX];
};

typedef struct Queue queue_t;

void queue_insert(queue_t * q, int elm){
    if (q->rear == QUEUE_MAX - 1) {
        q->rear = 0; 
    } else {
        q->rear += 1;
    }

    q->items[q->rear] = elm;
    // forma mais rebuscada q->items[++q->rear] = elm;
}

int queue_remove(queue_t * q){
    if (q->front == QUEUE_MAX - 1) {
        q->front = 0; 
    } else {
        q->front += 1;
    }
    
    return q->items[q->front];
}

bool is_empty(queue_t * q){
    return q->rear == q->front;
}

int queue_print(queue_t * q){
	int i = 0;
	printf("[");
	for(i = 0; i<QUEUE_MAX; i++){
		printf(" %d ", q->items[i]);
	}
	printf("]");
	printf("\n");
	printf("Front = %d  Rear = %d\n", q->front, q->rear);
}

int main() {
    queue_t q;
    // inicialização da Fila
    q.front = QUEUE_MAX-1;
    q.rear = QUEUE_MAX-1;
    
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
    
    return 0;
}
