#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Book {
    char id[10];
    char title[50];
    char author[50];
    float price;
    char genre[30];
};

struct Book books[MAX];
int n = 0;

void inputBooks() {
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    int i; 
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin sach %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", books[i].id);
        printf("Ten sach: ");
        scanf(" %[^\n]", books[i].title);
        printf("Tac gia: ");
        scanf(" %[^\n]", books[i].author);
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        printf("The loai: ");
        scanf(" %[^\n]", books[i].genre);
    }
}

void displayBooks() {
    printf("\nDanh sach sach:\n");
    printf("Ma sach\tTen sach\tTac gia\tGia tien\tThe loai\n");
    int i; 
    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%.2f\t%s\n", books[i].id, books[i].title, books[i].author, books[i].price, books[i].genre);
    }
}

void addBook() {
    int pos;
    printf("Nhap vi tri can them (0-%d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    int i;
    for (i = n; i > pos; i--) {
        books[i] = books[i - 1];
    }
    printf("Nhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%s", books[pos].id);
    printf("Ten sach: ");
    scanf(" %[^\n]", books[pos].title);
    printf("Tac gia: ");
    scanf(" %[^\n]", books[pos].author);
    printf("Gia tien: ");
    scanf("%f", &books[pos].price);
    printf("The loai: ");
    scanf(" %[^\n]", books[pos].genre);
    n++;
}

void deleteBook() {
    char id[10];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", id);
    int found = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) {
        	int j;
            for (j = i; j < n - 1; j++) {
                books[j] = books[j + 1];
            }
            n--;
            found = 1;
            printf("Xoa sach thanh cong!\n");
            break;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

void updateBook() {
    char id[10];
    printf("Nhap ma sach can cap nhat: ");
    scanf("%s", id);
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Ten sach: ");
            scanf(" %[^\n]", books[i].title);
            printf("Tac gia: ");
            scanf(" %[^\n]", books[i].author);
            printf("Gia tien: ");
            scanf("%f", &books[i].price);
            printf("The loai: ");
            scanf(" %[^\n]", books[i].genre);
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach!\n");
}

void sortBooks() {
    int choice;
    printf("1. Sap xep tang dan\n2. Sap xep giam dan\nLua chon: ");
    scanf("%d", &choice);
    int i;
    for (i = 0; i < n - 1; i++) {
    	int j;
        for (j = i + 1; j < n; j++) {
            if ((choice == 1 && books[i].price > books[j].price) ||
                (choice == 2 && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchBook() {
    char title[50];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", title);
    int found = 0;
    printf("\nKet qua tim kiem:\n");
    printf("Ma sach\tTen sach\tTac gia\tGia tien\tThe loai\n");
    int i;
    for (i = 0; i < n; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("%s\t%s\t%s\t%.2f\t%s\n", books[i].id, books[i].title, books[i].author, books[i].price, books[i].genre);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach!\n");
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputBooks(); break;
            case 2: displayBooks(); break;
            case 3: addBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 6: sortBooks(); break;
            case 7: searchBook(); break;
            case 8: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);
    return 0;
}
