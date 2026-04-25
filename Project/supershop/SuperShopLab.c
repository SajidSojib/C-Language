#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define INITIAL_CAPACITY 50
#define ADMIN_PASSWORD "admin123"
#define PRODUCT_FILE "products.txt"
#define SALES_FILE "sales.txt"
int MAXID = 1001;

/* Data structures */
typedef struct
{
    int id;
    char name[NAME_LEN];
    float price;
    int quantity;
} Product;

typedef struct
{
    int id;
    char name[NAME_LEN];
    float price;
    int quantity;
} CartItem;

typedef struct
{
    Product *items;
    size_t size;
    size_t capacity;
} ProductList;

/* Prototypes */
void mainMenu();
void adminLogin();
void customerMenu();

void adminMenu();
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();

void addToCart();
void removeFromCart();
void viewCart();
void checkout();

void clearInputBuffer();
void pauseAndContinue();

int main()
{
    mainMenu();
    return 0;
}

void mainMenu()
{
    int choice;
    while (1)
    {
        printf("\n=====================================\n");
        printf("    Super Shop Management System\n");
        printf("=====================================\n");
        printf("1. Admin Login\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            printf("Invalid input. Try again.\n");
            continue;
        }
        clearInputBuffer();

        if (choice == 1)
        {
            adminLogin();
        }
        else if (choice == 2)
        {
            customerMenu();
        }
        else if (choice == 3)
        {
            // saveProducts();
            // freeProductList();
            printf("Exiting... Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice, try again.\n");
        }
    }
}

void adminLogin()
{
    char password[50];
    printf("\nEnter admin password: ");
    if (fgets(password, sizeof(password), stdin) == NULL)
        return;
    password[strcspn(password, "\n")] = '\0'; // strip newline

    if (strcmp(password, ADMIN_PASSWORD) == 0)
    {
        printf("Login successful.\n");
        adminMenu();
    }
    else
    {
        printf("Incorrect password. Access denied.\n");
    }
}

/* Customer Menu */
void customerMenu()
{
    int choice;

    while (1)
    {
        printf("\n---------- Customer Menu ----------\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. View Cart\n");
        printf("4. Remove from Cart\n");
        printf("5. Checkout\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            printf("Invalid input.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            viewProducts();
            break;
        case 2:
            addToCart();
            break;
        case 3:
            viewCart();
            break;
        case 4:
            removeFromCart();
            break;
        case 5:
            checkout();
            break;
        case 6:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

/* Admin Menu */
void adminMenu()
{
    int choice;
    while (1)
    {
        printf("\n---------- Admin Menu ----------\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            clearInputBuffer();
            printf("Invalid input.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            viewProducts();
            break;
        case 3:
            updateProduct();
            break;
        case 4:
            deleteProduct();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

void addProduct()
{
    Product p;
    p.id = MAXID++;

    printf("Enter product name: ");
    if (fgets(p.name, sizeof(p.name), stdin) == NULL)
        return;
    p.name[strcspn(p.name, "\n")] = '\0';

    printf("Enter price: ");
    if (scanf("%f", &p.price) != 1)
    {
        clearInputBuffer();
        printf("Invalid price.\n");
        return;
    }
    printf("Enter quantity: ");
    if (scanf("%d", &p.quantity) != 1)
    {
        clearInputBuffer();
        printf("Invalid quantity.\n");
        return;
    }
    clearInputBuffer();
    printf("Product added successfully. ID = %d\n", p.id);
}
void viewProduct()
{
    printf("\nYou are in View Product\n\n");
}
void updateProduct()
{
    printf("\nYou are in Update Product\n\n");
}
void deleteProduct()
{
    printf("\nYou are in Delete Product\n\n");
}

void viewProducts(){
    printf("\nYou are in View Products\n\n");
}

void addToCart(){
    printf("\nYou are in Add to Cart\n\n");
}

void removeFromCart(){
    printf("\nYou are in Remove from Cart\n\n");
}

void viewCart(){
    printf("\nYou are in View Cart\n\n");
}

void checkout(){
    printf("\nYou are in Checkout\n\n");
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}