#include <stdio.h>
#include <string.h>

#define MAX 5
#define BOOKS 3

struct Book {
    char name[20];
    int copies;
};

struct Request {
    char studentName[20];
    char bookName[20];
};

struct Book books[BOOKS] = {
    {"DSA", 2},
    {"OS", 1},
    {"DBMS", 1}
};

struct Request queue[MAX];
int front = -1, rear = -1;


int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

void enqueue(char student[], char book[]) {
    if (isFull()) {
        printf("Waiting queue is FULL!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    strcpy(queue[rear].studentName, student);
    strcpy(queue[rear].bookName, book);

    printf("Book not available. Added to waiting queue.\n");
}


void displayBooks() {
    printf("\n--- Available Books in Library ---\n");
    for (int i = 0; i < BOOKS; i++) {
        printf("%d. %s - %d copies\n",
               i + 1, books[i].name, books[i].copies);
    }
}

int findBook(char bookName[]) {
    for (int i = 0; i < BOOKS; i++) {
        if (strcmp(books[i].name, bookName) == 0)
            return i;
    }
    return -1;
}


void requestBook() {
    char student[20], book[20];

    printf("\nEnter Student Name: ");
    scanf("%s", student);

    displayBooks();
    printf("Enter Book Name: ");
    scanf("%s", book);

    int index = findBook(book);
    if (index == -1) {
        printf("Invalid book name!\n");
        return;
    }

    if (books[index].copies > 0) {
        books[index].copies--;
        printf("Book '%s' allocated to %s\n", book, student);
    } else {
        enqueue(student, book);
    }
}

void returnBook() {
    char book[20];
    printf("\nEnter Book Name to Return: ");
    scanf("%s", book);

    int index = findBook(book);
    if (index == -1) {
        printf("Invalid book name!\n");
        return;
    }

    books[index].copies++;
    printf("Book '%s' returned successfully\n", book);

    if (isEmpty())
        return;

    // Search queue for first matching request (FIFO)
    int i = front, found = -1;
    while (1) {
        if (strcmp(queue[i].bookName, book) == 0) {
            found = i;
            break;
        }
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    if (found != -1) {
        printf("Book allocated to waiting user %s\n",
               queue[found].studentName);

        // Shift elements to maintain FIFO
        while (found != rear) {
            int next = (found + 1) % MAX;
            queue[found] = queue[next];
            found = next;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + MAX) % MAX;
        }

        books[index].copies--;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("\nWaiting queue is empty\n");
        return;
    }

    printf("\n--- Waiting Queue ---\n");
    int i = front;
    while (1) {
        printf("%s waiting for %s\n",
               queue[i].studentName,
               queue[i].bookName);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}


int main() {
    int choice;

    do {
        printf("\n===== LIBRARY BOOK ALLOCATION SYSTEM =====");
        printf("\n1. Display Available Books");
        printf("\n2. Request Book");
        printf("\n3. Return Book");
        printf("\n4. Display Waiting Queue");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayBooks();
            break;
        case 2:
            requestBook();
            break;
        case 3:
            returnBook();
            break;
        case 4:
            displayQueue();
            break;
        case 5:
            printf("Exiting system...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}