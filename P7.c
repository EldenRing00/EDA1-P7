#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Node {
    int data;
    struct Node *next;
};

// Función para agregar un nodo al final de la lista
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node *lastNode = *head;
        while (lastNode->next != *head) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = *head;
    }
}

// Función para imprimir los elementos de la lista
void printList(struct Node *head) {
    struct Node *currentNode = head;
    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("\n");
}

// Función para buscar un elemento en la lista
void searchElement(struct Node *head, int value) {
    struct Node *currentNode = head;
    do {
        if (currentNode->data == value) {
            printf("%d se encuentra en la estructura!\n", value);
            return;
        }
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("%d no se encuentra en la estructura...\n", value);
}

int main() {
    struct Node *head = NULL;
    int option, value;
    do {
        printf("Bienvenido, va a realizar una busqueda\n");
        printf("1. Insertar un elemento en la lista\n");
        printf("2. Imprimir la lista\n");
        printf("3. Buscar un elemento en la lista\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Lista: ");
                printList(head);
                break;
            case 3:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &value);
                searchElement(head, value);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida, intente de nuevo.\n");
        }
        printf("\n");
    } while (option != 4);
    return 0;
}
