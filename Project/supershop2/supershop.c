#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Structure Definitions
typedef struct
{
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
    char expiryDate[15];
} Product;

typedef struct
{
    int id;
    char name[50];
    char phone[15];
    float totalSpent;
} Customer;

typedef struct
{
    int billNo;
    char date[15];
    int customerId;
    char customerName[50];
    float totalAmount;
    int itemCount;
} Sale;

// Global variables
Product *products = NULL;
Customer *customers = NULL;
Sale *sales = NULL;
int productCount = 0;
int customerCount = 0;
int saleCount = 0;
int productCapacity = 10;
int customerCapacity = 10;
int saleCapacity = 10;

// Function Prototypes
void initializeSystem();
void mainMenu();
void productManagement();
void billingSystem();
void customerManagement();
void inventoryReport();
void salesReport();
void viewDataFiles();
void viewProductsFile();
void viewCustomersFile();
void viewSalesFile();

// Function Prototypes
void initializeSystem();
void mainMenu();
void productManagement();
void billingSystem();
void customerManagement();
void inventoryReport();
void salesReport();
void viewDataFiles();
void viewProductsFile();
void viewCustomersFile();
void viewSalesFile();

// Customer Management Functions
void addCustomer();
void viewCustomers();
void saveCustomersToFile();
void loadCustomersFromFile();

// Billing Functions
void generateBill();
void addToCart(int *cartIds, int *cartQuantities, float *cartPrices, int *itemCount);
void calculateBill(int *cartIds, int *cartQuantities, float *cartPrices, int itemCount, int customerId, char *customerName);
void saveSaleToFile(Sale sale);
void loadSalesFromFile();

// Utility Functions
int getNextProductId();
int getNextCustomerId();
int getNextBillNo();
int findProductById(int id);
int findCustomerById(int id);
void clearInputBuffer();
void printHeader(char *title);
void pressToContinue();

// File Operations
void saveAllData();
void loadAllData();

int main()
{
    initializeSystem();
    loadAllData();
    mainMenu();
    saveAllData();

    // Free allocated memory
    free(products);
    free(customers);
    free(sales);

    printf("\nThank you for using Super Shop Management System!\n");
    return 0;
}

void initializeSystem()
{
    // Initialize product array
    products = (Product *)malloc(productCapacity * sizeof(Product));
    if (!products)
    {
        printf("Memory allocation failed for products!\n");
        exit(1);
    }

    // Initialize customer array
    customers = (Customer *)malloc(customerCapacity * sizeof(Customer));
    if (!customers)
    {
        printf("Memory allocation failed for customers!\n");
        exit(1);
    }

    // Initialize sales array
    sales = (Sale *)malloc(saleCapacity * sizeof(Sale));
    if (!sales)
    {
        printf("Memory allocation failed for sales!\n");
        exit(1);
    }

    printf("\n========================================\n");
    printf("   SUPER SHOP MANAGEMENT SYSTEM\n");
    printf("========================================\n");
}

void mainMenu()
{
    int choice;

    do
    {
        printHeader("MAIN MENU");
        printf("1. Product Management\n");
        printf("2. Billing System\n");
        printf("3. Customer Management\n");
        printf("4. Inventory Report\n");
        printf("5. Sales Report\n");
        printf("6. View Data Files\n");
        printf("7. Exit\n");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            productManagement();
            break;
        case 2:
            billingSystem();
            break;
        case 3:
            customerManagement();
            break;
        case 4:
            inventoryReport();
            break;
        case 5:
            salesReport();
            break;
        case 6:
            viewDataFiles();
            break;
        case 7:
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);
}

void viewDataFiles()
{
    int choice;

    do
    {
        printHeader("VIEW DATA FILES");
        printf("1. View Products File\n");
        printf("2. View Customers File\n");
        printf("3. View Sales File\n");
        printf("4. Back to Main Menu\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            viewProductsFile();
            break;
        case 2:
            viewCustomersFile();
            break;
        case 3:
            viewSalesFile();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
}

void viewProductsFile()
{
    printHeader("PRODUCTS.TXT FILE CONTENT");

    FILE *file = fopen("products.txt", "r");
    if (file == NULL)
    {
        printf("No products file found or file is empty.\n");
        pressToContinue();
        return;
    }

    printf("======================================================================================\n");
    printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
    printf("======================================================================================\n");

    char line[200];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    printf("======================================================================================\n");
    pressToContinue();
}

void viewCustomersFile()
{
    printHeader("CUSTOMERS.TXT FILE CONTENT");

    FILE *file = fopen("customers.txt", "r");
    if (file == NULL)
    {
        printf("No customers file found or file is empty.\n");
        pressToContinue();
        return;
    }

    printf("============================================================================\n");
    printf("ID    | Name                          | Phone          | Total Spent\n");
    printf("============================================================================\n");

    char line[200];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    printf("============================================================================\n");
    pressToContinue();
}

void viewSalesFile()
{
    printHeader("SALES.TXT FILE CONTENT");

    FILE *file = fopen("sales.txt", "r");
    if (file == NULL)
    {
        printf("No sales file found or file is empty.\n");
        pressToContinue();
        return;
    }

    printf("===================================================================================\n");
    printf("BillNo | Date         | Customer ID | Customer Name               | Items | Amount\n");
    printf("===================================================================================\n");

    char line[200];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
    printf("===================================================================================\n");
    pressToContinue();
}

void productManagement()
{
    int choice;

    do
    {
        printHeader("PRODUCT MANAGEMENT");
        printf("1. Add New Product\n");
        printf("2. View All Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Back to Main Menu\n");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
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
            searchProduct();
            break;
        case 6:
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

void addProduct()
{
    printHeader("ADD NEW PRODUCT");

    // Check if we need to expand array
    if (productCount >= productCapacity)
    {
        productCapacity *= 2;
        products = (Product *)realloc(products, productCapacity * sizeof(Product));
    }

    Product newProduct;
    newProduct.id = getNextProductId();

    printf("Enter Product Name: ");
    fgets(newProduct.name, 50, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0;

    printf("Enter Category: ");
    fgets(newProduct.category, 30, stdin);
    newProduct.category[strcspn(newProduct.category, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &newProduct.price);

    printf("Enter Quantity: ");
    scanf("%d", &newProduct.quantity);
    clearInputBuffer();

    printf("Enter Expiry Date (DD/MM/YYYY): ");
    fgets(newProduct.expiryDate, 15, stdin);
    newProduct.expiryDate[strcspn(newProduct.expiryDate, "\n")] = 0;

    products[productCount] = newProduct;
    productCount++;

    printf("\nProduct added successfully! Product ID: %d\n", newProduct.id);
    saveProductsToFile();
    pressToContinue();
}

void viewProducts()
{
    printHeader("ALL PRODUCTS");

    if (productCount == 0)
    {
        printf("No products available!\n");
        pressToContinue();
        return;
    }

    printf("======================================================================================\n");
    printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
    printf("======================================================================================\n");

    for (int i = 0; i < productCount; i++)
    {
        printf("%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
               products[i].id,
               products[i].name,
               products[i].category,
               products[i].price,
               products[i].quantity,
               products[i].expiryDate);
    }
    printf("======================================================================================\n");
    printf("Total Products: %d\n", productCount);

    pressToContinue();
}

void updateProduct()
{
    printHeader("UPDATE PRODUCT");

    if (productCount == 0)
    {
        printf("No products available to update!\n");
        pressToContinue();
        return;
    }

    int id, index;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findProductById(id);

    if (index == -1)
    {
        printf("Product with ID %d not found!\n", id);
        pressToContinue();
        return;
    }

    printf("\nCurrent Details of Product ID %d:\n", id);
    printf("Name: %s\n", products[index].name);
    printf("Category: %s\n", products[index].category);
    printf("Price: %.2f\n", products[index].price);
    printf("Quantity: %d\n", products[index].quantity);
    printf("Expiry Date: %s\n", products[index].expiryDate);

    printf("\nEnter new details:\n");

    printf("Enter Product Name (current: %s): ", products[index].name);
    char name[50];
    fgets(name, 50, stdin);
    if (strlen(name) > 1)
    {
        name[strcspn(name, "\n")] = 0;
        strcpy(products[index].name, name);
    }

    printf("Enter Category (current: %s): ", products[index].category);
    char category[30];
    fgets(category, 30, stdin);
    if (strlen(category) > 1)
    {
        category[strcspn(category, "\n")] = 0;
        strcpy(products[index].category, category);
    }

    printf("Enter Price (current: %.2f): ", products[index].price);
    char priceStr[20];
    fgets(priceStr, 20, stdin);
    if (strlen(priceStr) > 1)
    {
        products[index].price = atof(priceStr);
    }

    printf("Enter Quantity (current: %d): ", products[index].quantity);
    char qtyStr[20];
    fgets(qtyStr, 20, stdin);
    if (strlen(qtyStr) > 1)
    {
        products[index].quantity = atoi(qtyStr);
    }

    printf("Enter Expiry Date (DD/MM/YYYY) (current: %s): ", products[index].expiryDate);
    char expiry[15];
    fgets(expiry, 15, stdin);
    if (strlen(expiry) > 1)
    {
        expiry[strcspn(expiry, "\n")] = 0;
        strcpy(products[index].expiryDate, expiry);
    }

    printf("\nProduct updated successfully!\n");
    saveProductsToFile();
    pressToContinue();
}

void deleteProduct()
{
    printHeader("DELETE PRODUCT");

    if (productCount == 0)
    {
        printf("No products available to delete!\n");
        pressToContinue();
        return;
    }

    int id, index;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    index = findProductById(id);

    if (index == -1)
    {
        printf("Product with ID %d not found!\n", id);
        pressToContinue();
        return;
    }

    printf("\nProduct Details:\n");
    printf("ID: %d\n", products[index].id);
    printf("Name: %s\n", products[index].name);
    printf("Price: %.2f\n", products[index].price);

    char confirm;
    printf("\nAre you sure you want to delete this product? (y/n): ");
    scanf("%c", &confirm);
    clearInputBuffer();

    if (confirm == 'y' || confirm == 'Y')
    {
        // Shift all products after the deleted one
        for (int i = index; i < productCount - 1; i++)
        {
            products[i] = products[i + 1];
        }
        productCount--;
        printf("Product deleted successfully!\n");
        saveProductsToFile();
    }
    else
    {
        printf("Deletion cancelled.\n");
    }

    pressToContinue();
}

void searchProduct()
{
    printHeader("SEARCH PRODUCT");

    if (productCount == 0)
    {
        printf("No products available to search!\n");
        pressToContinue();
        return;
    }

    int choice;
    printf("Search by:\n");
    printf("1. Product ID\n");
    printf("2. Product Name\n");
    printf("3. Category\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    char searchTerm[50];
    int found = 0;

    switch (choice)
    {
    case 1:
    {
        int searchId;
        printf("Enter Product ID: ");
        scanf("%d", &searchId);
        clearInputBuffer();

        printf("\nSearch Results:\n");
        printf("======================================================================================\n");
        printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
        printf("======================================================================================\n");

        for (int i = 0; i < productCount; i++)
        {
            if (products[i].id == searchId)
            {
                printf("%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
                       products[i].id,
                       products[i].name,
                       products[i].category,
                       products[i].price,
                       products[i].quantity,
                       products[i].expiryDate);
                found = 1;
                break;
            }
        }
        break;
    }

    case 2:
    {
        printf("Enter Product Name: ");
        fgets(searchTerm, 50, stdin);
        searchTerm[strcspn(searchTerm, "\n")] = 0;

        printf("\nSearch Results:\n");
        printf("======================================================================================\n");
        printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
        printf("======================================================================================\n");

        for (int i = 0; i < productCount; i++)
        {
            if (strstr(products[i].name, searchTerm) != NULL)
            {
                printf("%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
                       products[i].id,
                       products[i].name,
                       products[i].category,
                       products[i].price,
                       products[i].quantity,
                       products[i].expiryDate);
                found = 1;
            }
        }
        break;
    }

    case 3:
    {
        printf("Enter Category: ");
        fgets(searchTerm, 30, stdin);
        searchTerm[strcspn(searchTerm, "\n")] = 0;

        printf("\nSearch Results:\n");
        printf("======================================================================================\n");
        printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
        printf("======================================================================================\n");

        for (int i = 0; i < productCount; i++)
        {
            if (strcmp(products[i].category, searchTerm) == 0)
            {
                printf("%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
                       products[i].id,
                       products[i].name,
                       products[i].category,
                       products[i].price,
                       products[i].quantity,
                       products[i].expiryDate);
                found = 1;
            }
        }
        break;
    }

    default:
        printf("Invalid choice!\n");
        pressToContinue();
        return;
    }

    if (!found)
    {
        printf("No products found!\n");
    }
    printf("======================================================================================\n");

    pressToContinue();
}

void billingSystem()
{
    int choice;

    do
    {
        printHeader("BILLING SYSTEM");
        printf("1. Generate New Bill\n");
        printf("2. Back to Main Menu\n");
        printf("\nEnter your choice (1-2): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            generateBill();
            break;
        case 2:
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 2);
}

void generateBill()
{
    printHeader("GENERATE NEW BILL");

    if (productCount == 0)
    {
        printf("No products available for billing!\n");
        pressToContinue();
        return;
    }

    // Arrays for cart items
    int maxItems = 100;
    int cartIds[maxItems];
    int cartQuantities[maxItems];
    float cartPrices[maxItems];
    int itemCount = 0;

    // Customer selection
    int customerChoice;
    printf("Is the customer registered? (1=Yes, 0=No): ");
    scanf("%d", &customerChoice);
    clearInputBuffer();

    int customerId = 0;
    char customerName[50] = "Walk-in Customer";

    if (customerChoice == 1 && customerCount > 0)
    {
        printf("Enter Customer ID: ");
        scanf("%d", &customerId);
        clearInputBuffer();

        int custIndex = findCustomerById(customerId);
        if (custIndex != -1)
        {
            strcpy(customerName, customers[custIndex].name);
            printf("Customer: %s\n", customerName);
        }
        else
        {
            printf("Customer not found. Using 'Walk-in Customer'\n");
            customerId = 0;
        }
    }
    else if (customerChoice == 1 && customerCount == 0)
    {
        printf("No customers registered yet. Using 'Walk-in Customer'\n");
    }

    // Add items to cart
    char addMore;
    do
    {
        addToCart(cartIds, cartQuantities, cartPrices, &itemCount);

        if (itemCount < maxItems)
        {
            printf("\nAdd another item? (y/n): ");
            scanf(" %c", &addMore);
            clearInputBuffer();
        }
        else
        {
            printf("\nCart is full!\n");
            addMore = 'n';
        }
    } while ((addMore == 'y' || addMore == 'Y') && itemCount < maxItems);

    // Calculate and display bill
    if (itemCount > 0)
    {
        calculateBill(cartIds, cartQuantities, cartPrices, itemCount, customerId, customerName);

        // Update customer total spent if registered
        if (customerId > 0)
        {
            int custIndex = findCustomerById(customerId);
            if (custIndex != -1)
            {
                float total = 0;
                for (int i = 0; i < itemCount; i++)
                {
                    total += cartPrices[i] * cartQuantities[i];
                }
                customers[custIndex].totalSpent += total;
                saveCustomersToFile();
            }
        }
    }

    pressToContinue();
}

void addToCart(int *cartIds, int *cartQuantities, float *cartPrices, int *itemCount)
{
    viewProducts();

    int productId, quantity, index;

    printf("\nEnter Product ID to add to cart: ");
    scanf("%d", &productId);

    index = findProductById(productId);

    if (index == -1)
    {
        printf("Product with ID %d not found!\n", productId);
        return;
    }

    printf("Product: %s\n", products[index].name);
    printf("Price: %.2f\n", products[index].price);
    printf("Available Quantity: %d\n", products[index].quantity);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    clearInputBuffer();

    if (quantity <= 0)
    {
        printf("Invalid quantity!\n");
        return;
    }

    if (quantity > products[index].quantity)
    {
        printf("Insufficient stock! Only %d available.\n", products[index].quantity);
        return;
    }

    // Add to cart
    cartIds[*itemCount] = productId;
    cartQuantities[*itemCount] = quantity;
    cartPrices[*itemCount] = products[index].price;

    // Update product quantity
    products[index].quantity -= quantity;
    (*itemCount)++;

    printf("Added %d x %s to cart\n", quantity, products[index].name);
}

void calculateBill(int *cartIds, int *cartQuantities, float *cartPrices, int itemCount, int customerId, char *customerName)
{
    printHeader("BILL RECEIPT");

    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char dateStr[15];
    sprintf(dateStr, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    int billNo = getNextBillNo();

    printf("Bill No: %d\n", billNo);
    printf("Date: %s\n", dateStr);
    if (customerId > 0)
    {
        printf("Customer: %s (ID: %d)\n", customerName, customerId);
    }
    else
    {
        printf("Customer: %s\n", customerName);
    }
    printf("================================================\n");
    printf("Item                       Qty   Price   Total\n");
    printf("------------------------------------------------\n");

    float subtotal = 0;

    for (int i = 0; i < itemCount; i++)
    {
        int index = findProductById(cartIds[i]);
        if (index != -1)
        {
            float itemTotal = cartPrices[i] * cartQuantities[i];
            subtotal += itemTotal;

            // Truncate name if too long
            char displayName[25];
            strncpy(displayName, products[index].name, 24);
            displayName[24] = '\0';

            printf("%-25s %-5d %-7.2f %-7.2f\n",
                   displayName,
                   cartQuantities[i],
                   cartPrices[i],
                   itemTotal);
        }
    }

    printf("------------------------------------------------\n");

    // Calculate tax and total
    float tax = subtotal * 0.05; // 5% tax
    float total = subtotal + tax;

    printf("Subtotal: %38.2f\n", subtotal);
    printf("Tax (5%%): %38.2f\n", tax);
    printf("Total: %41.2f\n", total);
    printf("================================================\n");

    // Create sale record
    Sale newSale;
    newSale.billNo = billNo;
    strcpy(newSale.date, dateStr);
    newSale.customerId = customerId;
    strcpy(newSale.customerName, customerName);
    newSale.totalAmount = total;
    newSale.itemCount = itemCount;

    // Save sale to array
    if (saleCount >= saleCapacity)
    {
        saleCapacity *= 2;
        sales = (Sale *)realloc(sales, saleCapacity * sizeof(Sale));
    }
    sales[saleCount] = newSale;
    saleCount++;

    // Save sale to file and update products
    saveSaleToFile(newSale);
    saveProductsToFile();

    printf("\nThank you for shopping with us!\n");
}

void customerManagement()
{
    int choice;

    do
    {
        printHeader("CUSTOMER MANAGEMENT");
        printf("1. Add New Customer\n");
        printf("2. View All Customers\n");
        printf("3. Back to Main Menu\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            viewCustomers();
            break;
        case 3:
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 3);
}

void addCustomer()
{
    printHeader("ADD NEW CUSTOMER");

    // Check if we need to expand array
    if (customerCount >= customerCapacity)
    {
        customerCapacity *= 2;
        customers = (Customer *)realloc(customers, customerCapacity * sizeof(Customer));
    }

    Customer newCustomer;
    newCustomer.id = getNextCustomerId();
    newCustomer.totalSpent = 0;

    printf("Enter Customer Name: ");
    fgets(newCustomer.name, 50, stdin);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = 0;

    printf("Enter Phone Number: ");
    fgets(newCustomer.phone, 15, stdin);
    newCustomer.phone[strcspn(newCustomer.phone, "\n")] = 0;

    customers[customerCount] = newCustomer;
    customerCount++;

    printf("\nCustomer added successfully! Customer ID: %d\n", newCustomer.id);
    saveCustomersToFile();
    pressToContinue();
}

void viewCustomers()
{
    printHeader("ALL CUSTOMERS");

    if (customerCount == 0)
    {
        printf("No customers available!\n");
        pressToContinue();
        return;
    }

    printf("============================================================================\n");
    printf("ID    | Name                          | Phone          | Total Spent\n");
    printf("============================================================================\n");

    for (int i = 0; i < customerCount; i++)
    {
        printf("%-5d | %-30s | %-15s | %-11.2f\n",
               customers[i].id,
               customers[i].name,
               customers[i].phone,
               customers[i].totalSpent);
    }
    printf("============================================================================\n");
    printf("Total Customers: %d\n", customerCount);

    pressToContinue();
}

void inventoryReport()
{
    printHeader("INVENTORY REPORT");

    if (productCount == 0)
    {
        printf("No products in inventory!\n");
        pressToContinue();
        return;
    }

    float totalValue = 0;
    int lowStockCount = 0;

    printf("Products with Low Stock (less than 10):\n");
    printf("======================================================================================\n");
    printf("ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
    printf("======================================================================================\n");

    for (int i = 0; i < productCount; i++)
    {
        totalValue += products[i].price * products[i].quantity;

        if (products[i].quantity < 10)
        {
            printf("%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
                   products[i].id,
                   products[i].name,
                   products[i].category,
                   products[i].price,
                   products[i].quantity,
                   products[i].expiryDate);
            lowStockCount++;
        }
    }

    if (lowStockCount == 0)
    {
        printf("No products with low stock.\n");
    }

    printf("======================================================================================\n");
    printf("\nInventory Summary:\n");
    printf("Total Products: %d\n", productCount);
    printf("Total Inventory Value: %.2f\n", totalValue);
    printf("Products with low stock: %d\n", lowStockCount);

    pressToContinue();
}

void salesReport()
{
    printHeader("SALES REPORT");

    if (saleCount == 0)
    {
        printf("No sales recorded yet!\n");
        pressToContinue();
        return;
    }

    printf("Recent Sales:\n");
    printf("===================================================================================\n");
    printf("BillNo | Date         | Customer ID | Customer Name               | Items | Amount\n");
    printf("===================================================================================\n");

    float totalSales = 0;
    int totalItems = 0;

    // Show last 20 sales or all if less than 20
    int start = (saleCount > 20) ? saleCount - 20 : 0;

    for (int i = start; i < saleCount; i++)
    {
        printf("%-6d | %-12s | %-11d | %-28s | %-5d | %-11.2f\n",
               sales[i].billNo,
               sales[i].date,
               sales[i].customerId,
               sales[i].customerName,
               sales[i].itemCount,
               sales[i].totalAmount);

        totalSales += sales[i].totalAmount;
        totalItems += sales[i].itemCount;
    }

    printf("===================================================================================\n");
    printf("\nSales Summary:\n");
    printf("Total Sales: %.2f\n", totalSales);
    printf("Total Items Sold: %d\n", totalItems);
    printf("Total Bills Generated: %d\n", saleCount);

    pressToContinue();
}

// Utility Functions
int getNextProductId()
{
    int maxId = 1000;
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].id > maxId)
        {
            maxId = products[i].id;
        }
    }
    return maxId + 1;
}

int getNextCustomerId()
{
    int maxId = 2000;
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].id > maxId)
        {
            maxId = customers[i].id;
        }
    }
    return maxId + 1;
}

int getNextBillNo()
{
    int maxNo = 3000;
    for (int i = 0; i < saleCount; i++)
    {
        if (sales[i].billNo > maxNo)
        {
            maxNo = sales[i].billNo;
        }
    }
    return maxNo + 1;
}

int findProductById(int id)
{
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int findCustomerById(int id)
{
    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void printHeader(char *title)
{
// Clear screen command for different operating systems
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Mac/Linux
#endif

    printf("\n========================================\n");
    printf("   %s\n", title);
    printf("========================================\n\n");
}

void pressToContinue()
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
    getchar();
}

// File Operations - TEXT FILES
void saveProductsToFile()
{
    FILE *file = fopen("products.txt", "w");
    if (file == NULL)
    {
        printf("Error saving products to file!\n");
        return;
    }

    // Write header to file
    fprintf(file, "======================================================================================\n");
    fprintf(file, "ID    | Name                          | Category        | Price    | Qty | Expiry Date\n");
    fprintf(file, "======================================================================================\n");

    // Write all products
    for (int i = 0; i < productCount; i++)
    {
        fprintf(file, "%-5d | %-30s | %-15s | %-8.2f | %-3d | %-15s\n",
                products[i].id,
                products[i].name,
                products[i].category,
                products[i].price,
                products[i].quantity,
                products[i].expiryDate);
    }

    // Write footer
    fprintf(file, "======================================================================================\n");
    fprintf(file, "Total Products: %d\n", productCount);

    fclose(file);
}

void loadProductsFromFile()
{
    FILE *file = fopen("products.txt", "r");
    if (file == NULL)
    {
        return; // File doesn't exist yet
    }

    productCount = 0;
    char line[200];

    // Read the file line by line
    while (fgets(line, sizeof(line), file))
    {
        // Skip header/footer lines
        if (strstr(line, "=====") != NULL || strstr(line, "Total Products:") != NULL)
        {
            continue;
        }

        // Try to parse product data
        Product p;
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        // Parse the formatted line
        if (sscanf(line, "%d | %49[^|] | %29[^|] | %f | %d | %14[^\n]",
                   &p.id, p.name, p.category, &p.price, &p.quantity, p.expiryDate) >= 5)
        {

            // Trim trailing spaces from strings
            int len = strlen(p.name);
            while (len > 0 && p.name[len - 1] == ' ')
            {
                p.name[--len] = '\0';
            }

            len = strlen(p.category);
            while (len > 0 && p.category[len - 1] == ' ')
            {
                p.category[--len] = '\0';
            }

            len = strlen(p.expiryDate);
            while (len > 0 && p.expiryDate[len - 1] == ' ')
            {
                p.expiryDate[--len] = '\0';
            }

            // Ensure enough capacity
            if (productCount >= productCapacity)
            {
                productCapacity *= 2;
                products = (Product *)realloc(products, productCapacity * sizeof(Product));
            }

            products[productCount] = p;
            productCount++;
        }
    }

    fclose(file);
}

void saveCustomersToFile()
{
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL)
    {
        printf("Error saving customers to file!\n");
        return;
    }

    // Write header to file
    fprintf(file, "============================================================================\n");
    fprintf(file, "ID    | Name                          | Phone          | Total Spent\n");
    fprintf(file, "============================================================================\n");

    // Write all customers
    for (int i = 0; i < customerCount; i++)
    {
        fprintf(file, "%-5d | %-30s | %-15s | %-11.2f\n",
                customers[i].id,
                customers[i].name,
                customers[i].phone,
                customers[i].totalSpent);
    }

    // Write footer
    fprintf(file, "============================================================================\n");
    fprintf(file, "Total Customers: %d\n", customerCount);

    fclose(file);
}

void loadCustomersFromFile()
{
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL)
    {
        return;
    }

    customerCount = 0;
    char line[200];

    // Read the file line by line
    while (fgets(line, sizeof(line), file))
    {
        // Skip header/footer lines
        if (strstr(line, "=====") != NULL || strstr(line, "Total Customers:") != NULL)
        {
            continue;
        }

        // Try to parse customer data
        Customer c;
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        // Parse the formatted line
        if (sscanf(line, "%d | %49[^|] | %14[^|] | %f",
                   &c.id, c.name, c.phone, &c.totalSpent) >= 3)
        {

            // Trim trailing spaces from strings
            int len = strlen(c.name);
            while (len > 0 && c.name[len - 1] == ' ')
            {
                c.name[--len] = '\0';
            }

            len = strlen(c.phone);
            while (len > 0 && c.phone[len - 1] == ' ')
            {
                c.phone[--len] = '\0';
            }

            // Ensure enough capacity
            if (customerCount >= customerCapacity)
            {
                customerCapacity *= 2;
                customers = (Customer *)realloc(customers, customerCapacity * sizeof(Customer));
            }

            customers[customerCount] = c;
            customerCount++;
        }
    }

    fclose(file);
}

void saveSaleToFile(Sale sale)
{
    FILE *file = fopen("sales.txt", "a");
    if (file == NULL)
    {
        file = fopen("sales.txt", "w");
        if (file == NULL)
        {
            printf("Error creating sales file!\n");
            return;
        }
        // Write header for new file
        fprintf(file, "===================================================================================\n");
        fprintf(file, "BillNo | Date         | Customer ID | Customer Name               | Items | Amount\n");
        fprintf(file, "===================================================================================\n");
    }
    else
    {
        // Check if file is empty to add header
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0)
        {
            fprintf(file, "===================================================================================\n");
            fprintf(file, "BillNo | Date         | Customer ID | Customer Name               | Items | Amount\n");
            fprintf(file, "===================================================================================\n");
        }
        fclose(file);
        file = fopen("sales.txt", "a");
    }

    fprintf(file, "%-6d | %-12s | %-11d | %-28s | %-5d | %-11.2f\n",
            sale.billNo,
            sale.date,
            sale.customerId,
            sale.customerName,
            sale.itemCount,
            sale.totalAmount);

    fclose(file);
}

void loadSalesFromFile()
{
    FILE *file = fopen("sales.txt", "r");
    if (file == NULL)
    {
        return;
    }

    saleCount = 0;
    char line[200];

    // Read the file line by line
    while (fgets(line, sizeof(line), file))
    {
        // Skip header/footer lines
        if (strstr(line, "=====") != NULL)
        {
            continue;
        }

        // Try to parse sale data
        Sale s;
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        // Parse the formatted line
        if (sscanf(line, "%d | %14[^|] | %d | %49[^|] | %d | %f",
                   &s.billNo, s.date, &s.customerId, s.customerName, &s.itemCount, &s.totalAmount) >= 5)
        {

            // Trim trailing spaces from strings
            int len = strlen(s.date);
            while (len > 0 && s.date[len - 1] == ' ')
            {
                s.date[--len] = '\0';
            }

            len = strlen(s.customerName);
            while (len > 0 && s.customerName[len - 1] == ' ')
            {
                s.customerName[--len] = '\0';
            }

            // Ensure enough capacity
            if (saleCount >= saleCapacity)
            {
                saleCapacity *= 2;
                sales = (Sale *)realloc(sales, saleCapacity * sizeof(Sale));
            }

            sales[saleCount] = s;
            saleCount++;
        }
    }

    fclose(file);
}

void saveAllData()
{
    saveProductsToFile();
    saveCustomersToFile();
}

void loadAllData()
{
    loadProductsFromFile();
    loadCustomersFromFile();
    loadSalesFromFile();
}