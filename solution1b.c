#include <stdio.h>

#define TABLE_SIZE 11

int hash_table[TABLE_SIZE];

int hash_function(int key) {
    return key % TABLE_SIZE;
}

int probe_function(int k) {
    return (k * k + k) / 2;
}

void insert_key(int key) {
    int home_slot = hash_function(key);
    int probe_sequence[3];
    int i = 0;

    // Check if home slot is empty
    if (hash_table[home_slot] == -1) {
        hash_table[home_slot] = key;
        printf("Home Slot: %d, Probe Sequence: None\n", home_slot);
        return;
    }

    // Generate probe sequence
    probe_sequence[0] = home_slot + probe_function(1);
    probe_sequence[1] = home_slot + probe_function(2);
    probe_sequence[2] = home_slot + probe_function(3);

    // Probe for an empty slot
    for (i = 0; i < 3; i++) {
        int probe_slot = probe_sequence[i] % TABLE_SIZE;
        if (hash_table[probe_slot] == -1) {
            hash_table[probe_slot] = key;
            printf("Home Slot: %d, Probe Sequence: ", home_slot);
            for (int j = 0; j <= i; j++) {
                printf("%d ", probe_sequence[j]);
            }
            printf("\n");
            return;
        }
    }

    // If all probe slots are full, print error message
    printf("Error: Hash table is full!\n");
}

void print_hash_table() {
    printf("Final Hash Table:\n");
    printf("Slot\t");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    printf("Contents\t");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == -1) {
            printf("None\t");
        } else {
            printf("%d\t", hash_table[i]);
        }
    }
    printf("\n");
}

int main() {
    // Initialize hash table with -1 (empty)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
    }

    // Insert keys
    insert_key(43);
    insert_key(23);
    insert_key(1);
    insert_key(0);
    insert_key(15);
    insert_key(31);
    insert_key(4);
    insert_key(7);
    insert_key(11);
    insert_key(3);

    print_hash_table();

    return 0;
}

