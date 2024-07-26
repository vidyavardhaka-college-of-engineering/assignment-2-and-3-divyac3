#include <stdio.h>

#define TABLE_SIZE 11

// Hash function h1
int h1(int key) {
    return key % TABLE_SIZE;
}

// Reverse function to reverse the digits of the key
int reverse(int key) {
    int reversed = 0;
    while (key > 0) {
        reversed = reversed * 10 + key % 10;
        key /= 10;
    }
    return reversed;
}

// Function to initialize hash table
void initialize_hash_table(int hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hash_table[i] = -1; // Initialize all slots to -1 (indicating empty)
    }
}

// Function to print the hash table
void print_hash_table(int hash_table[]) {
    printf("Final Hash Table:\n");
    printf("Slot 0 1 2 3 4 5 6 7 8 9 10\n");
    printf("Contents ");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hash_table[i] == -1) {
            printf("  "); // Empty slot
        } else {
            printf("%2d ", hash_table[i]);
        }
    }
    printf("\n");
}

// Function to insert a key into the hash table using double hashing
void insert_key(int key, int value, int hash_table[]) {
    int home_slot = h1(key); // Calculate home slot using hash function
    int probe = reverse(key); // Calculate probe using reverse function
    int slot = home_slot;

    printf("Key: %d, Home Slot: %d, Probe Sequence: ", key, home_slot);

    // Double hashing until an empty slot is found
    while (hash_table[slot] != -1) {
        printf("%d, ", slot);
        slot = (home_slot + probe) % TABLE_SIZE;
        probe = (probe + 1) % TABLE_SIZE; // Increment probe
    }

    printf("\n");

    // Insert the key into the found slot
    hash_table[slot] = value;
}

int main() {
    int hash_table[TABLE_SIZE];

    initialize_hash_table(hash_table);

    // Insert keys in the given order
    insert_key(43, 1, hash_table);
    insert_key(23, 2, hash_table);
    insert_key(1, 5, hash_table);
    insert_key(0, 3, hash_table);
    insert_key(15, 1, hash_table);
    insert_key(31, 0, hash_table);
    insert_key(4, 0, hash_table);
    insert_key(7, 8, hash_table);
    insert_key(11, 9, hash_table);
    insert_key(3, 9, hash_table);

    // Print the final hash table
    print_hash_table(hash_table);

    return 0;
}
