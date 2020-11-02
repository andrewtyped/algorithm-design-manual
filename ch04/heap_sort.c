#include <stdio.h>
#include <stdlib.h>

#define PQ_SIZE 100

typedef int item_type;

typedef struct {
    item_type q[PQ_SIZE+1]; // body of queue
    int n;                  // number of elements
} priority_queue;

/*
* SUMMARY
* Gets the index of the parent to the element at index n. Each level of the queue has 2^n items, so diving by 2 will find the index.
*/
int pq_parent(int n) {
    if (n == 1) {
        return (-1);
    }

    return ((int) n/2);
}

/*
* SUMMARY
* Gets the index of the left child to the element at n.
*/
int pq_young_child(int n) {
    return (2 * n);
}

void pq_swap(priority_queue *q, int childP, int parentP) {
    item_type temp = q->q[parentP];
    q->q[parentP] = q->q[childP];
    q->q[childP] = temp;
}

void bubble_up(priority_queue *q, int p) {
    int parentP = pq_parent(p);

    if (parentP == -1) {
        //At root of heap, no parent;
        return;
    }

    if(q->q[parentP] > q->q[p]) {
        pq_swap(q,p,parentP);
        bubble_up(q, parentP);
    }
}

void pq_insert(priority_queue *q, item_type x) {
    if (q->n >= PQ_SIZE) {
        printf("Warning: priority queue overflow insert x=%d\n", x);
        return;
    }

    q->n = (q->n) + 1;
    q->q[q->n] = x;
    bubble_up(q, q->n);
}

void pq_init(priority_queue *q) {
    q->n = 0;
}

void make_heap(priority_queue *q, item_type s[], int n) {
    int i;

    pq_init(q);
    for (i=0; i < n; i++) {
        pq_insert(q, s[i]);
    }
}

void print_heap(priority_queue *q) {
    for(int i = 1; i <= q->n; i++) {
        printf("%d \n", q->q[i]);
    }
}

int main() {
    priority_queue *q = malloc(sizeof *q);

    item_type s[10] = {10,1,2,3,4,5,6,7,8,9};

    make_heap(q,s,10);
    print_heap(q);
    return 0;
}















