//Huffman_Coding
/*Aim of the experiment: Huffman coding assigns variable length codewords to fixed length
input characters based on their frequencies/probabilities of occurrence. Given a set of characters
along with their frequency of occurrences. Write a c program to perform the following functions.
Note# Declare a structure CHAR having members symbol and frequency. Create a Min-Priority
Queue, keyed on frequency attributes.
Input:
Enter the number of distinct characters: 6
Enter the characters: a b c d e f
Enter its frequencies: 45 13 12 16 9 5
Output:
In-order traversal of the tree (Huffman): a c b f e d
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure CHAR to represent characters and their frequencies
struct CHAR {
    char symbol;
    unsigned frequency;
};

// Define a structure MIN_HEAP_NODE to represent nodes in the Min-Heap
struct MIN_HEAP_NODE {
    struct CHAR data;
    struct MIN_HEAP_NODE* left;
    struct MIN_HEAP_NODE* right;
};

// Define a Min-Heap structure
struct MIN_HEAP {
    unsigned size;
    unsigned capacity;
    struct MIN_HEAP_NODE** array;
};

// Function to create a new character node
struct MIN_HEAP_NODE* newNode(struct CHAR data) {
    struct MIN_HEAP_NODE* node = (struct MIN_HEAP_NODE*)malloc(sizeof(struct MIN_HEAP_NODE));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a Min-Heap
struct MIN_HEAP* createMinHeap(unsigned capacity) {
    struct MIN_HEAP* minHeap = (struct MIN_HEAP*)malloc(sizeof(struct MIN_HEAP));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MIN_HEAP_NODE**)malloc(capacity * sizeof(struct MIN_HEAP_NODE));
    return minHeap;
}

// Function to swap two Min-Heap nodes
void swapNodes(struct MIN_HEAP_NODE** a, struct MIN_HEAP_NODE** b) {
    struct MIN_HEAP_NODE* t = *a;
    *a = *b;
    *b = t;
}

// Function to maintain Min-Heap property
void minHeapify(struct MIN_HEAP* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->data.frequency < minHeap->array[smallest]->data.frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->data.frequency < minHeap->array[smallest]->data.frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if Min-Heap contains only one node
int isSizeOne(struct MIN_HEAP* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from Min-Heap
struct MIN_HEAP_NODE* extractMin(struct MIN_HEAP* minHeap) {
    struct MIN_HEAP_NODE* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node into Min-Heap
void insertMinHeap(struct MIN_HEAP* minHeap, struct MIN_HEAP_NODE* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->data.frequency < minHeap->array[(i - 1) / 2]->data.frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build the Huffman tree
struct MIN_HEAP_NODE* buildHuffmanTree(struct CHAR data[], int size) {
    struct MIN_HEAP_NODE* left, * right, * top;

    // Create a Min-Heap with given characters and their frequencies
    struct MIN_HEAP* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i]);

    minHeap->size = size;
    for (int i = (size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    // Build the Huffman tree
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        struct CHAR temp = { '$', left->data.frequency + right->data.frequency };
        top = newNode(temp);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print Huffman codes
void printHuffmanCodes(struct MIN_HEAP_NODE* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data.symbol);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Driver program
int main() {
    int n;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    struct CHAR data[n];

    for (int i = 0; i < n; i++) {
        printf("Enter symbol for character %d: ", i + 1);
        scanf(" %c", &data[i].symbol); // Space before %c to consume newline
        printf("Enter frequency for character %c: ", data[i].symbol);
        scanf("%d", &data[i].frequency);
    }

    struct MIN_HEAP_NODE* root = buildHuffmanTree(data, n);

    int arr[n];
    int top = 0;

    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, arr, top);

    return 0;
}