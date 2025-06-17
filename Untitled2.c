#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Product {
    char id[10];
    char name[50];
    float importPrice;
    float sellPrice;
    int quantity;
};

struct Product products[MAX];
int n = 0;
float revenue = 0;

void inputProducts() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);
    int i; 
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin san pham %d:\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", products[i].id);
        printf("Ten san pham: ");
        scanf(" %[^\n]", products[i].name);
        printf("Gia nhap: ");
        scanf("%f", &products[i].importPrice);
        printf("Gia ban: ");
        scanf("%f", &products[i].sellPrice);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        revenue -= products[i].quantity * products[i].importPrice;
    }
}

void displayProducts() {
    printf("\nDanh sach san pham:\n");
    printf("Ma SP\tTen SP\tGia nhap\tGia ban\tSo luong\n");
    int i; 
    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%.2f\t%.2f\t%d\n", products[i].id, products[i].name, products[i].importPrice, products[i].sellPrice, products[i].quantity);
    }
}

void importProduct() {
    char id[10];
    int quantity;
    printf("Nhap ma san pham: ");
    scanf("%s", id);
    int i; 
    for (i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap so luong them: ");
            scanf("%d", &quantity);
            products[i].quantity += quantity;
            revenue -= quantity * products[i].importPrice;
            printf("Nhap hang thanh cong!\n");
            return;
        }
    }
    printf("Nhap thong tin san pham moi:\n");
    strcpy(products[n].id, id);
    printf("Ten san pham: ");
    scanf(" %[^\n]", products[n].name);
    printf("Gia nhap: ");
    scanf("%f", &products[n].importPrice);
    printf("Gia ban: ");
    scanf("%f", &products[n].sellPrice);
    printf("So luong: ");
    scanf("%d", &quantity);
    products[n].quantity = quantity;
    revenue -= quantity * products[n].importPrice;
    n++;
    printf("Nhap hang thanh cong!\n");
}

void updateProduct() {
    char id[10];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);
    int i; 
    for (i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Ten san pham: ");
            scanf(" %[^\n]", products[i].name);
            printf("Gia nhap: ");
            scanf("%f", &products[i].importPrice);
            printf("Gia ban: ");
            scanf("%f", &products[i].sellPrice);
            printf("So luong: ");
            scanf("%d", &products[i].quantity);
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham!\n");
}

void sortProducts() {
    int choice;
    printf("1. Sap xep tang dan\n2. Sap xep giam dan\nLua chon: ");
    scanf("%d", &choice);
    int i; 
    for (i = 0; i < n - 1; i++) {
    	int j; 
        for (j = i + 1; j < n; j++) {
            if ((choice == 1 && products[i].sellPrice > products[j].sellPrice) ||
                (choice == 2 && products[i].sellPrice < products[j].sellPrice)) {
                struct Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchProduct() {
    char name[50];
    printf("Nhap ten san pham can tim: ");
    scanf(" %[^\n]", name);
    int found = 0;
    printf("\nKet qua tim kiem:\n");
    printf("Ma SP\tTen SP\tGia nhap\tGia ban\tSo luong\n");
    int i; 
    for (i = 0; i < n; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("%s\t%s\t%.2f\t%.2f\t%d\n", products[i].id, products[i].name, products[i].importPrice, products[i].sellPrice, products[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay san pham!\n");
}

void sellProduct() {
    char id[10];
    int quantity;
    printf("Nhap ma san pham can ban: ");
    scanf("%s", id);
    int i; 
    for (i = 0; i < n; i++) {
        if (strcmp(products[i].id, id) == 0) {
            if (products[i].quantity == 0) {
                printf("Het hang!\n");
                return;
            }
            printf("Nhap so luong ban: ");
            scanf("%d", &quantity);
            if (quantity > products[i].quantity) {
                printf("Khong con du hang!\n");
                return;
            }
            products[i].quantity -= quantity;
            revenue += quantity * products[i].sellPrice;
            printf("Ban hang thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay san pham!\n");
}

void showRevenue() {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputProducts(); break;
            case 2: displayProducts(); break;
            case 3: importProduct(); break;
            case 4: updateProduct(); break;
            case 5: sortProducts(); break;
            case 6: searchProduct(); break;
            case 7: sellProduct(); break;
            case 8: showRevenue(); break;
            case 9: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 9);
    return 0;
}
