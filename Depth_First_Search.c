#include <stdio.h>
        if (head == NULL) continue;

        int swapped;
        do {
            swapped = 0;
            Node* curr = head;

            while (curr->next != NULL) {
                if (curr->vertex > curr->next->vertex) {
                    // swap values
                    int temp = curr->vertex;
                    curr->vertex = curr->next->vertex;
                    curr->next->vertex = temp;
                    swapped = 1;
                }
                curr = curr->next;
            }
        } while (swapped);
    }
}

// DFS function
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize adjacency list and visited array
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort adjacency list
    sortAdjList(V);

    int start;
    scanf("%d", &start);

    DFS(start);

    return 0;
}

