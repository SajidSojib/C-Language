/* Super Shop Management System (Console-based in C)
   Features:
   - Admin login (fixed password)
   - Add/View/Update/Delete products
   - Customer add-to-cart and checkout
   - File persistence (products.dat, sales.txt)
   Compile: gcc -std=c99 super_shop.c -o super_shop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ADMIN_PASSWORD "admin123"
#define PRODUCT_FILE "products.txt"
#define SALES_FILE "sales.txt"
#define NAME_LEN 50
#define INITIAL_CAPACITY 50

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

/* In-memory product list structure */
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
void loadProducts(ProductList *pl);
void saveProducts(ProductList *pl);
void addProduct(ProductList *pl);
void viewProducts(ProductList *pl);
void updateProduct(ProductList *pl);
void deleteProduct(ProductList *pl);
int findProductIndexById(ProductList *pl, int id);
int getNextProductId(ProductList *pl);

void addToCart(ProductList *pl, CartItem cart[], int *cartSize);
void removeFromCart(CartItem cart[], int *cartSize);
void viewCart(CartItem cart[], int cartSize);
float calculateTotal(CartItem cart[], int cartSize);
void checkout(ProductList *pl, CartItem cart[], int *cartSize);
void saveSalesRecord(CartItem cart[], int cartSize, float total);

void clearInputBuffer();
void pauseAndContinue();
void ensureProductCapacity(ProductList *pl);
void initProductList(ProductList *pl);
void freeProductList(ProductList *pl);

/* --- Implementation --- */

int main()
{
    mainMenu();
    return 0;
}

/* Main Menu */
void mainMenu()
{
    ProductList pl;
    initProductList(&pl);
    loadProducts(&pl);

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
            adminLogin(&pl);
        }
        else if (choice == 2)
        {
            customerMenu(&pl);
        }
        else if (choice == 3)
        {
            saveProducts(&pl);
            freeProductList(&pl);
            printf("Exiting... Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice, try again.\n");
        }
    }
}

/* Admin Login */
void adminLogin(ProductList *pl)
{
    char password[50];
    printf("\nEnter admin password: ");
    if (fgets(password, sizeof(password), stdin) == NULL)
        return;
    password[strcspn(password, "\n")] = '\0'; // strip newline

    if (strcmp(password, ADMIN_PASSWORD) == 0)
    {
        printf("Login successful.\n");
        adminMenu(pl);
    }
    else
    {
        printf("Incorrect password. Access denied.\n");
    }
}

/* Customer Menu */
void customerMenu(ProductList *pl)
{
    int choice;
    CartItem cart[100];
    int cartSize = 0;

    while (1)
    {
        printf("\n-------- Customer Menu --------\n");
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
            viewProducts(pl);
            break;
        case 2:
            addToCart(pl, cart, &cartSize);
            break;
        case 3:
            viewCart(cart, cartSize);
            break;
        case 4:
            removeFromCart(cart, &cartSize);
            break;
        case 5:
            checkout(pl, cart, &cartSize);
            break;
        case 6:
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

/* Admin Menu */
void adminMenu(ProductList *pl)
{
    int choice;
    while (1)
    {
        printf("\n-------- Admin Menu --------\n");
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
            addProduct(pl);
            break;
        case 2:
            viewProducts(pl);
            break;
        case 3:
            updateProduct(pl);
            break;
        case 4:
            deleteProduct(pl);
            break;
        case 5:
            saveProducts(pl);
            return;
        default:
            printf("Invalid choice.\n");
        }
    }
}

/* ProductList helpers */
void initProductList(ProductList *pl)
{
    pl->items = malloc(sizeof(Product) * INITIAL_CAPACITY);
    if (!pl->items)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    pl->size = 0;
    pl->capacity = INITIAL_CAPACITY;
}

void freeProductList(ProductList *pl)
{
    free(pl->items);
    pl->items = NULL;
    pl->size = pl->capacity = 0;
}

void ensureProductCapacity(ProductList *pl)
{
    if (pl->size >= pl->capacity)
    {
        pl->capacity *= 2;
        Product *tmp = realloc(pl->items, pl->capacity * sizeof(Product));
        if (!tmp)
        {
            fprintf(stderr, "Memory reallocation error\n");
            exit(1);
        }
        pl->items = tmp;
    }
}

/* Load products from file into memory */
/* Load products from text file */
void loadProducts(ProductList *pl)
{
    FILE *fp = fopen(PRODUCT_FILE, "r");
    if (!fp)
    {
        printf("No product file found, starting fresh.\n");
        return;
    }

    Product p;
    while (fscanf(fp, "%d,%49[^,],%f,%d\n", &p.id, p.name, &p.price, &p.quantity) == 4)
    {
        ensureProductCapacity(pl);
        pl->items[pl->size++] = p;
    }
    fclose(fp);
}

/* Save products to text file */
void saveProducts(ProductList *pl)
{
    FILE *fp = fopen(PRODUCT_FILE, "w");
    if (!fp)
    {
        fprintf(stderr, "Could not open product file for writing.\n");
        return;
    }

    for (size_t i = 0; i < pl->size; ++i)
    {
        fprintf(fp, "%d,%s,%.2f,%d\n",
                pl->items[i].id,
                pl->items[i].name,
                pl->items[i].price,
                pl->items[i].quantity);
    }

    fclose(fp);
}

/* Get next product id (max existing id + 1) */
int getNextProductId(ProductList *pl)
{
    int max = 0;
    for (size_t i = 0; i < pl->size; ++i)
    {
        if (pl->items[i].id > max)
            max = pl->items[i].id;
    }
    return max + 1;
}

/* Find product index by id; return -1 if not found */
int findProductIndexById(ProductList *pl, int id)
{
    for (size_t i = 0; i < pl->size; ++i)
    {
        if (pl->items[i].id == id)
            return (int)i;
    }
    return -1;
}

/* Add product (admin) */
void addProduct(ProductList *pl)
{
    Product p;
    p.id = getNextProductId(pl);

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

    ensureProductCapacity(pl);
    pl->items[pl->size++] = p;
    saveProducts(pl);
    printf("Product added successfully. ID = %d\n", p.id);
}

/* View products */
void viewProducts(ProductList *pl)
{
    if (pl->size == 0)
    {
        printf("\nNo products available.\n");
        return;
    }
    printf("\n--------- Product List ---------\n");
    printf("%-5s %-25s %-10s %-8s\n", "ID", "Name", "Price", "Quantity");
    for (size_t i = 0; i < pl->size; ++i)
    {
        printf("%-5d %-25s %-10.2f %-8d\n",
               pl->items[i].id,
               pl->items[i].name,
               pl->items[i].price,
               pl->items[i].quantity);
    }
}

/* Update product (admin) */
void updateProduct(ProductList *pl)
{
    int id;
    printf("Enter product ID to update: ");
    if (scanf("%d", &id) != 1)
    {
        clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    clearInputBuffer();

    int idx = findProductIndexById(pl, id);
    if (idx == -1)
    {
        printf("Product with ID %d not found.\n", id);
        return;
    }
    Product *p = &pl->items[idx];
    printf("Editing product (ID %d, Name: %s)\n", p->id, p->name);

    char input[NAME_LEN];
    printf("Enter new name (leave blank to keep '%s'): ", p->name);
    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) > 0)
            strncpy(p->name, input, NAME_LEN);
    }

    printf("Enter new price (current %.2f, enter 0 to keep): ", p->price);
    float newPrice;
    if (scanf("%f", &newPrice) == 1)
    {
        if (newPrice > 0)
            p->price = newPrice;
    }
    else
    {
        clearInputBuffer();
        printf("Invalid input for price, keeping old value.\n");
    }

    printf("Enter new quantity (current %d, enter -1 to keep): ", p->quantity);
    int newQty;
    if (scanf("%d", &newQty) == 1)
    {
        if (newQty >= 0)
            p->quantity = newQty;
    }
    else
    {
        clearInputBuffer();
        printf("Invalid input for quantity, keeping old value.\n");
    }
    clearInputBuffer();

    saveProducts(pl);
    printf("Product updated.\n");
}

/* Delete product (admin) */
void deleteProduct(ProductList *pl)
{
    int id;
    printf("Enter product ID to delete: ");
    if (scanf("%d", &id) != 1)
    {
        clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    clearInputBuffer();

    int idx = findProductIndexById(pl, id);
    if (idx == -1)
    {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    // shift elements to remove
    for (size_t i = idx; i + 1 < pl->size; ++i)
    {
        pl->items[i] = pl->items[i + 1];
    }
    pl->size--;
    saveProducts(pl);
    printf("Product deleted.\n");
}

/* Customer: add to cart */
void addToCart(ProductList *pl, CartItem cart[], int *cartSize)
{
    if (pl->size == 0)
    {
        printf("No products available.\n");
        return;
    }
    int id;
    printf("Enter product ID to add to cart: ");
    if (scanf("%d", &id) != 1)
    {
        clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    clearInputBuffer();

    int idx = findProductIndexById(pl, id);
    if (idx == -1)
    {
        printf("Product not found.\n");
        return;
    }
    Product *p = &pl->items[idx];

    printf("Enter quantity to add (available %d): ", p->quantity);
    int qty;
    if (scanf("%d", &qty) != 1)
    {
        clearInputBuffer();
        printf("Invalid quantity.\n");
        return;
    }
    clearInputBuffer();

    if (qty <= 0)
    {
        printf("Quantity must be > 0.\n");
        return;
    }
    if (qty > p->quantity)
    {
        printf("Not enough stock. Available: %d\n", p->quantity);
        return;
    }

    // If item already in cart, increase quantity
    for (int i = 0; i < *cartSize; ++i)
    {
        if (cart[i].id == p->id)
        {
            cart[i].quantity += qty;
            printf("Added %d more of '%s' to cart. New qty: %d\n", qty, cart[i].name, cart[i].quantity);
            return;
        }
    }

    // else add new item
    if (*cartSize >= 100)
    {
        printf("Cart full. Checkout first.\n");
        return;
    }
    cart[*cartSize].id = p->id;
    strncpy(cart[*cartSize].name, p->name, NAME_LEN);
    cart[*cartSize].price = p->price;
    cart[*cartSize].quantity = qty;
    (*cartSize)++;
    printf("Added to cart: %s x %d\n", p->name, qty);
}

/* Remove from cart */
void removeFromCart(CartItem cart[], int *cartSize)
{
    if (*cartSize == 0)
    {
        printf("Cart is empty.\n");
        return;
    }
    int id;
    printf("Enter product ID to remove from cart: ");
    if (scanf("%d", &id) != 1)
    {
        clearInputBuffer();
        printf("Invalid input.\n");
        return;
    }
    clearInputBuffer();

    int idx = -1;
    for (int i = 0; i < *cartSize; ++i)
        if (cart[i].id == id)
        {
            idx = i;
            break;
        }
    if (idx == -1)
    {
        printf("Item not found in cart.\n");
        return;
    }

    // shift
    for (int i = idx; i + 1 < *cartSize; ++i)
        cart[i] = cart[i + 1];
    (*cartSize)--;
    printf("Item removed from cart.\n");
}

/* View cart */
void viewCart(CartItem cart[], int cartSize)
{
    if (cartSize == 0)
    {
        printf("Cart is empty.\n");
        return;
    }
    printf("\n--- Cart ---\n");
    printf("%-5s %-25s %-8s %-8s %-10s\n", "ID", "Name", "Price", "Qty", "Subtotal");
    for (int i = 0; i < cartSize; ++i)
    {
        float subtotal = cart[i].price * cart[i].quantity;
        printf("%-5d %-25s %-8.2f %-8d %-10.2f\n",
               cart[i].id, cart[i].name, cart[i].price, cart[i].quantity, subtotal);
    }
    float total = calculateTotal(cart, cartSize);
    printf("Total: %.2f\n", total);
}

/* Calculate total */
float calculateTotal(CartItem cart[], int cartSize)
{
    float total = 0;
    for (int i = 0; i < cartSize; ++i)
        total += cart[i].price * cart[i].quantity;
    return total;
}

/* Checkout */
void checkout(ProductList *pl, CartItem cart[], int *cartSize)
{
    if (*cartSize == 0)
    {
        printf("Cart is empty.\n");
        return;
    }
    // Check availability again
    for (int i = 0; i < *cartSize; ++i)
    {
        int idx = findProductIndexById(pl, cart[i].id);
        if (idx == -1 || pl->items[idx].quantity < cart[i].quantity)
        {
            printf("Insufficient stock for product '%s'. Checkout canceled.\n", cart[i].name);
            return;
        }
    }

    float total = calculateTotal(cart, *cartSize);
    printf("\n--- Checkout ---\n");
    viewCart(cart, *cartSize);
    printf("Confirm purchase? (y/n): ");
    char confirm = getchar();
    clearInputBuffer();
    if (confirm != 'y' && confirm != 'Y')
    {
        printf("Checkout canceled.\n");
        return;
    }

    // Deduct stock
    for (int i = 0; i < *cartSize; ++i)
    {
        int idx = findProductIndexById(pl, cart[i].id);
        if (idx != -1)
        {
            pl->items[idx].quantity -= cart[i].quantity;
        }
    }
    // Save products after update
    saveProducts(pl);

    // Save sales record
    saveSalesRecord(cart, *cartSize, total);

    // Print simple receipt
    time_t t = time(NULL);
    printf("\n--- Receipt ---\n");
    printf("Date: %s", ctime(&t));
    for (int i = 0; i < *cartSize; ++i)
    {
        printf("%s x %d = %.2f\n", cart[i].name, cart[i].quantity, cart[i].quantity * cart[i].price);
    }
    printf("Total Paid: %.2f\n", total);
    printf("Thank you for shopping!\n");

    // Clear cart
    *cartSize = 0;
}

/* Save sales record to text file (append) */
void saveSalesRecord(CartItem cart[], int cartSize, float total)
{
    FILE *fp = fopen(SALES_FILE, "a");
    if (!fp)
    {
        fprintf(stderr, "Unable to open sales file.\n");
        return;
    }
    time_t t = time(NULL);
    fprintf(fp, "---- Transaction on %s", ctime(&t));
    for (int i = 0; i < cartSize; ++i)
    {
        fprintf(fp, "%d | %s | %.2f | %d | %.2f\n",
                cart[i].id, cart[i].name, cart[i].price, cart[i].quantity, cart[i].price * cart[i].quantity);
    }
    fprintf(fp, "Total: %.2f\n\n", total);
    fclose(fp);
}

/* Utility: clear input buffer */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* optional pause */
void pauseAndContinue()
{
    printf("Press Enter to continue...");
    getchar();
}
