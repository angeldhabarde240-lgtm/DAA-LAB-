#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
 Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    //write your code here...
    Node* newNode = createNode(v);

    if (adjList[u] == NULL) {
        adjList[u] = newNode;
    } else {
        Node* temp = adjList[u];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
	}    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    //write your code here...
    for (int i = 0; i < V; i++) {
        Node* current = adjList[i];

        while (current != NULL) {
            Node* minNode = current;
            Node* temp = current->next;

            while (temp != NULL) {
                if (temp->vertex < minNode->vertex) {
                    minNode = temp;
                }
                temp = temp->next;
            }

            // Swap vertex values
            int t = current->vertex;
            current->vertex = minNode->vertex;
            minNode->vertex = t;

            current = current->next;
        }
	}
}

// Depth-First Search (DFS) function
void DFS(int start) {
visited[start] = 1;
}
