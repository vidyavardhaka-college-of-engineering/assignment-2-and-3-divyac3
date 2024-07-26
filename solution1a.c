#include <stdio.h>

int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % 11;
    return x;
}

void insert(int hash_table[], int key) {
    int home_slot = h1(key);
    int probe_sequence[11] = {0};
    int i = 0;
    while (hash_table[(home_slot + i) % 11]!= 0) {
        probe_sequence[i] = (home_slot + i) % 11;
        i++;
    }
    hash_table[(home_slot + i) % 11] = key;
    printf("Key: %d, Home Slot: %d, Probe Sequence: ", key, home_slot);
    for (int j = 0; j < i; j++) {
        printf("%d, ", probe_sequence[j]);
    }
    printf("\n");
}

void print_hash_table(int hash_table[]) {
    printf("Final Hash Table:\n");
    printf("Slot 0 1 2 3 4 5 6 7 8 9 10\n");
    printf("Contents ");
    for (int i = 0; i < 11; i++) {
        printf("%d ", hash_table[i]);
    }
    printf("\n");
}

int main() {
    int hash_table[11] = {0};
    insert(hash_table, 43);
    insert(hash_table, 23);
    insert(hash_table, 1);
    insert(hash_table, 0);
    insert(hash_table, 15);
    insert(hash_table, 31);
    insert(hash_table, 4);
    insert(hash_table, 7);
    insert(hash_table, 11);
    insert(hash_table, 3);
    print_hash_table(hash_table);
    return 0;
}
