#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

typedef struct node *GNODE;

GNODE graph[20] = {NULL};


GNODE createNode(int v) {
    GNODE newNode = (GNODE)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void addAtEnd(int src, int dest) {
    GNODE newNode = createNode(dest);

    if (graph[src] == NULL) {
        graph[src] = newNode;
    } else {
        GNODE temp = graph[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}


void print(int *N) {
    for (int i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);
            GNODE temp = graph[i];
            while (temp != NULL) {
                printf("%d	", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}


void insertVertex(int *N) {
    int edges, v;

    (*N)++;

    printf("Enter number of edges from existing vertices to new vertex : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }
        addAtEnd(v, *N);
    }

    printf("Enter number of edges from new vertex to existing vertices : ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d", &v);
        if (v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            (*N)--;
            return;
        }
        addAtEnd(*N, v);
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}
