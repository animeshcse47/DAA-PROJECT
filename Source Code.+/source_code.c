#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// University structure
typedef struct {
    int id;
    char univ_code[10];
    char univ_name[50];
    char univ_address[100];
    char univ_email[50];
    char univ_website[50];
} University;

University universities[MAX];
int university_count = 0;

// File name 
const char* FILE_NAME = "university_setting.txt";

// Function declarations
void AP23110011096_UNIVERSITY_create();
void AP23110011096_UNIVERSITY_update();
void AP23110011096_UNIVERSITY_retrieve();
void AP23110011096_UNIVERSITY_delete();
void AP23110011096_UNIVERSITY_storing();
void AP23110011096_UNIVERSITY_INSERTION_SORT();
void AP23110011096_UNIVERSITY_SELECTION_SORT();
void AP23110011096_UNIVERSITY_BINARY_SEARCH();
void AP23110011096_UNIVERSITY_LINEAR_SEARCH();

// Function to load data 
void load_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No file exists yet
    }
    university_count = 0;
    while (fscanf(file, "%d %s %s %s %s %s\n", &universities[university_count].id,
                  universities[university_count].univ_code,
                  universities[university_count].univ_name,
                  universities[university_count].univ_address,
                  universities[university_count].univ_email,
                  universities[university_count].univ_website) != EOF) {
        university_count++;
    }
    fclose(file);
}

// Function to save data to the file
void AP23110011096_UNIVERSITY_storing() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < university_count; i++) {
        fprintf(file, "%d %s %s %s %s %s\n", universities[i].id,
                universities[i].univ_code, universities[i].univ_name,
                universities[i].univ_address, universities[i].univ_email,
                universities[i].univ_website);
    }
    fclose(file);
}

// create function
void AP23110011096_UNIVERSITY_create() {
    if (university_count >= MAX) {
        printf("University list is full!\n");
        return;
    }
    
    University u;
    printf("Enter University ID: ");
    scanf("%d", &u.id);
    printf("Enter University Code: ");
    scanf("%s", u.univ_code);
    printf("Enter University Name: ");
    scanf("%s", u.univ_name);
    printf("Enter University Address: ");
    scanf("%s", u.univ_address);
    printf("Enter University Email: ");
    scanf("%s", u.univ_email);
    printf("Enter University Website: ");
    scanf("%s", u.univ_website);

    universities[university_count++] = u;
    AP23110011096_UNIVERSITY_storing();
    printf("University created successfully!\n");
}

// updation
void AP23110011096_UNIVERSITY_update() {
    int id;
    printf("Enter University ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < university_count; i++) {
        if (universities[i].id == id) {
            printf("Enter new University Code: ");
            scanf("%s", universities[i].univ_code);
            printf("Enter new University Name: ");
            scanf("%s", universities[i].univ_name);
            printf("Enter new University Address: ");
            scanf("%s", universities[i].univ_address);
            printf("Enter new University Email: ");
            scanf("%s", universities[i].univ_email);
            printf("Enter new University Website: ");
            scanf("%s", universities[i].univ_website);

            AP23110011096_UNIVERSITY_storing();
            printf("University updated successfully!\n");
            return;
        }
    }
    printf("University with ID %d not found.\n", id);
}

// retrieve function
void AP23110011096_UNIVERSITY_retrieve() {
    printf("\nList of Universities:\n");
    for (int i = 0; i < university_count; i++) {
        printf("ID: %d\nCode: %s\nName: %s\nAddress: %s\nEmail: %s\nWebsite: %s\n\n",
               universities[i].id, universities[i].univ_code,
               universities[i].univ_name, universities[i].univ_address,
               universities[i].univ_email, universities[i].univ_website);
    }
}

// deletion
void AP23110011096_UNIVERSITY_delete() {
    int id;
    printf("Enter University ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < university_count; i++) {
        if (universities[i].id == id) {
            for (int j = i; j < university_count - 1; j++) {
                universities[j] = universities[j + 1];
            }
            university_count--;
            AP23110011096_UNIVERSITY_storing();
            printf("University deleted successfully!\n");
            return;
        }
    }
    printf("University with ID %d not found.\n", id);
}

// Insertion sort code
void AP23110011096_UNIVERSITY_INSERTION_SORT() {
    for (int i = 1; i < university_count; i++) {
        University key = universities[i];
        int j = i - 1;
        while (j >= 0 && strcmp(universities[j].univ_code, key.univ_code) > 0) {
            universities[j + 1] = universities[j];
            j = j - 1;
        }
        universities[j + 1] = key;
    }
    printf("Universities sorted by code (Insertion Sort)!\n");
    AP23110011096_UNIVERSITY_retrieve();
}

// Selection sort code
void AP23110011096_UNIVERSITY_SELECTION_SORT() {
    for (int i = 0; i < university_count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < university_count; j++) {
            if (strcmp(universities[j].univ_code, universities[min_idx].univ_code) < 0) {
                min_idx = j;
            }
        }
        University temp = universities[min_idx];
        universities[min_idx] = universities[i];
        universities[i] = temp;
    }
    printf("Universities sorted by code (Selection Sort)!\n");
    AP23110011096_UNIVERSITY_retrieve();
}

// Binary search code
void AP23110011096_UNIVERSITY_BINARY_SEARCH() {
    char code[10];
    printf("Enter University Code to search (Binary Search): ");
    scanf("%s", code);

    int left = 0, right = university_count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int res = strcmp(universities[mid].univ_code, code);

        if (res == 0) {
            printf("ID: %d\nCode: %s\nName: %s\nAddress: %s\nEmail: %s\nWebsite: %s\n",
                   universities[mid].id, universities[mid].univ_code,
                   universities[mid].univ_name, universities[mid].univ_address,
                   universities[mid].univ_email, universities[mid].univ_website);
            return;
        }

        if (res < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("University with code %s not found.\n", code);
}

// Linear search code
void AP23110011096_UNIVERSITY_LINEAR_SEARCH() {
    char code[10];
    printf("Enter University Code to search (Linear Search): ");
    scanf("%s", code);

    for (int i = 0; i < university_count; i++) {
        if (strcmp(universities[i].univ_code, code) == 0) {
            printf("ID: %d\nCode: %s\nName: %s\nAddress: %s\nEmail: %s\nWebsite: %s\n",
                   universities[i].id, universities[i].univ_code,
                   universities[i].univ_name, universities[i].univ_address,
                   universities[i].univ_email, universities[i].univ_website);
            return;
        }
    }
    printf("University with code %s not found.\n", code);
}

int main() {
    load_from_file();

    int choice;
    while (1) {
        printf("\n1. Create University\n2. Update University\n3. Retrieve Universities\n4. Delete University\n5. Linear Search by Code\n6. Binary Search by Code\n7. Insertion Sort by Code\n8. Selection Sort by Code\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: AP23110011096_UNIVERSITY_create(); break;
            case 2: AP23110011096_UNIVERSITY_update(); break;
            case 3: AP23110011096_UNIVERSITY_retrieve(); break;
            case 4: AP23110011096_UNIVERSITY_delete(); break;
            case 5: AP23110011096_UNIVERSITY_LINEAR_SEARCH(); break;
            case 6: AP23110011096_UNIVERSITY_BINARY_SEARCH(); break;
            case 7: AP23110011096_UNIVERSITY_INSERTION_SORT(); break;
            case 8: AP23110011096_UNIVERSITY_SELECTION_SORT(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n"); break;
        }
    }
    return 0;
}
