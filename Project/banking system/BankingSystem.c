#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 40
#define DATA_FILE "accounts.txt"

typedef struct
{
    int id;
    char name[NAME_LEN];
    char type[10]; // SAVINGS or CURRENT
    double balance;
    double loan;
    double fdrLocked;
    double certLocked;
    int atm, debit, credit;
    int active;
} Account;

static Account A[MAX];
static int AC = 0;
static int NEXT_ID = 1001;

/* ================= FILE HANDLING ================= */

static void load_accounts(void)
{
    FILE *fp = fopen(DATA_FILE, "r");
    if (!fp)
        return; // first run, file not exists

    AC = 0;
    while (AC < MAX &&
           fscanf(fp,
                  "%d|%39[^|]|%9[^|]|%lf|%lf|%lf|%lf|%d|%d|%d|%d\n",
                  &A[AC].id,
                  A[AC].name,
                  A[AC].type,
                  &A[AC].balance,
                  &A[AC].loan,
                  &A[AC].fdrLocked,
                  &A[AC].certLocked,
                  &A[AC].atm,
                  &A[AC].debit,
                  &A[AC].credit,
                  &A[AC].active) == 11)
    {

        if (A[AC].id >= NEXT_ID)
            NEXT_ID = A[AC].id + 1;
        AC++;
    }
    fclose(fp);
}

static void save_accounts(void)
{
    FILE *fp = fopen(DATA_FILE, "w");
    if (!fp)
        return;

    for (int i = 0; i < AC; i++)
    {
        if (!A[i].active)
            continue;
        fprintf(fp,
                "%d|%s|%s|%.2f|%.2f|%.2f|%.2f|%d|%d|%d|%d\n",
                A[i].id,
                A[i].name,
                A[i].type,
                A[i].balance,
                A[i].loan,
                A[i].fdrLocked,
                A[i].certLocked,
                A[i].atm,
                A[i].debit,
                A[i].credit,
                A[i].active);
    }
    fclose(fp);
}

/* ================= SAFE INPUT ================= */

static void read_line(char *buf, int n)
{
    if (fgets(buf, n, stdin))
    {
        int L = (int)strlen(buf);
        if (L && buf[L - 1] == '\n')
            buf[L - 1] = '\0';
    }
    else
    {
        if (n)
            buf[0] = '\0';
        clearerr(stdin);
    }
}

static int read_int(void)
{
    char b[64];
    int x = 0;
    read_line(b, sizeof b);
    sscanf(b, "%d", &x);
    return x;
}

static double read_double(void)
{
    char b[64];
    double x = 0.0;
    read_line(b, sizeof b);
    sscanf(b, "%lf", &x);
    return x;
}

static void wait_enter(void)
{
    printf("\nPress ENTER to continue...");
    fflush(stdout);
    char b[8];
    read_line(b, sizeof b);
}

static int find_index_by_id(int id)
{
    for (int i = 0; i < AC; i++)
        if (A[i].active && A[i].id == id)
            return i;
    return -1;
}

/* ================= 1) INFORMATION DESK ================= */

static void info_desk(void)
{
    printf("\n==== Information Desk ====\n");
    printf("Welcome to Demo Bank.\n");
    printf("Branches: Dhaka, Chattogram, Sylhet, Rajshahi.\n");
    printf("Hours: Sun-Thu 10:00-18:00\n");
    printf("Help: 16200\n");
    wait_enter();
}

/* ================= 2) NEW ACCOUNT ================= */

static void new_account(void)
{
    if (AC >= MAX)
    {
        printf("Bank full.\n");
        wait_enter();
        return;
    }

    Account a;
    memset(&a, 0, sizeof a);
    a.id = NEXT_ID++;
    a.active = 1;

    printf("\n=== Open New Account ===\n");
    printf("Full name: ");
    read_line(a.name, NAME_LEN);
    printf("Account type (SAVINGS/CURRENT): ");
    read_line(a.type, sizeof a.type);
    printf("Initial deposit: ");
    a.balance = read_double();

    A[AC++] = a;
    printf("Account created. Your ID: %d\n", a.id);
    wait_enter();
}

/* ================= COMMON ACTIONS ================= */

static void do_deposit(Account *a)
{
    printf("Amount to deposit: ");
    double x = read_double();
    if (x > 0)
    {
        a->balance += x;
        printf("Deposited. Balance: %.2f\n", a->balance);
    }
    else
        printf("Invalid.\n");
    wait_enter();
}

static void do_withdraw(Account *a)
{
    printf("Amount to withdraw: ");
    double x = read_double();
    if (x > 0 && x <= a->balance)
    {
        a->balance -= x;
        printf("Withdrawn. Balance: %.2f\n", a->balance);
    }
    else
        printf("Invalid or not enough money.\n");
    wait_enter();
}

static void do_transfer(Account *a)
{
    printf("Send to Account ID: ");
    int id = read_int();
    int j = find_index_by_id(id);
    if (j < 0)
    {
        printf("Account not found.\n");
        wait_enter();
        return;
    }
    printf("Amount: ");
    double x = read_double();
    if (x > 0 && x <= a->balance)
    {
        a->balance -= x;
        A[j].balance += x;
        printf("Sent. Your balance: %.2f\n", a->balance);
    }
    else
        printf("Invalid or not enough money.\n");
    wait_enter();
}

/* ================= 3) CASH COUNTER ================= */

static void cash_counter(void)
{
    printf("\nLogin (Account ID): ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Account not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Cash Counter ==\n");
        printf("1) Balance\n2) Deposit\n3) Withdraw\n4) Transfer\n0) Back\n> ");
        c = read_int();

        if (c == 1)
        {
            printf("Balance: %.2f\n", A[i].balance);
            wait_enter();
        }
        else if (c == 2)
            do_deposit(&A[i]);
        else if (c == 3)
            do_withdraw(&A[i]);
        else if (c == 4)
            do_transfer(&A[i]);
    } while (c != 0);
}

/* ================= 4) DEBIT SERVICE ================= */

static void debit_service(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Debit Service ==\n1) Pay Bill\n2) Transfer\n0) Back\n> ");
        c = read_int();

        if (c == 1)
        {
            printf("Bill amount: ");
            double x = read_double();
            if (x > 0 && x <= A[i].balance)
            {
                A[i].balance -= x;
                printf("Bill paid. Balance: %.2f\n", A[i].balance);
            }
            else
                printf("Invalid or not enough money.\n");
            wait_enter();
        }
        else if (c == 2)
            do_transfer(&A[i]);
    } while (c != 0);
}

/* ================= 5) CREDIT SERVICE ================= */

static void credit_service(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Credit Service ==\n1) Deposit\n2) Add Interest (3%%)\n0) Back\n> ");
        c = read_int();

        if (c == 1)
            do_deposit(&A[i]);
        else if (c == 2)
        {
            double add = A[i].balance * 0.03;
            A[i].balance += add;
            printf("Interest added: %.2f | Balance: %.2f\n", add, A[i].balance);
            wait_enter();
        }
    } while (c != 0);
}

/* ================= 6) FDR SERVICE ================= */

static void fdr_service(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== FDR Service ==\n1) Open FDR\n2) Encash FDR (+7%%)\n0) Back\n> ");
        c = read_int();

        if (c == 1)
        {
            printf("Amount to lock: ");
            double p = read_double();
            if (p > 0 && p <= A[i].balance)
            {
                A[i].balance -= p;
                A[i].fdrLocked += p;
                printf("FDR opened. Locked: %.2f\n", A[i].fdrLocked);
            }
            else
                printf("Invalid or not enough money.\n");
            wait_enter();
        }
        else if (c == 2)
        {
            if (A[i].fdrLocked > 0)
            {
                double credit = A[i].fdrLocked * 1.07;
                A[i].balance += credit;
                A[i].fdrLocked = 0;
                printf("Encashed. Got: %.2f\n", credit);
            }
            else
                printf("No FDR.\n");
            wait_enter();
        }
    } while (c != 0);
}

/* ================= 7) SAVINGS CERTIFICATES ================= */

static void savings_certs(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Savings Certificates ==\n1) Buy\n2) Redeem (+9%%)\n0) Back\n> ");
        c = read_int();

        if (c == 1)
        {
            printf("Buy amount: ");
            double p = read_double();
            if (p > 0 && p <= A[i].balance)
            {
                A[i].balance -= p;
                A[i].certLocked += p;
                printf("Bought. Cert total: %.2f\n", A[i].certLocked);
            }
            else
                printf("Invalid or not enough money.\n");
            wait_enter();
        }
        else if (c == 2)
        {
            if (A[i].certLocked > 0)
            {
                double credit = A[i].certLocked * 1.09;
                A[i].balance += credit;
                A[i].certLocked = 0;
                printf("Redeemed. Got: %.2f\n", credit);
            }
            else
                printf("No certificate.\n");
            wait_enter();
        }
    } while (c != 0);
}

/* ================= 8) LOAN SERVICE ================= */

static void loan_service(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Loan Service ==\n1) Take Loan\n2) Pay Loan\n3) See Loan Due\n0) Back\n> ");
        c = read_int();

        if (c == 1)
        {
            printf("Loan amount: ");
            double p = read_double();
            if (p > 0)
            {
                A[i].loan += p;
                A[i].balance += p;
                printf("Loan ok. Due: %.2f | Balance: %.2f\n",
                       A[i].loan, A[i].balance);
            }
            else
                printf("Invalid.\n");
            wait_enter();
        }
        else if (c == 2)
        {
            printf("Pay amount: ");
            double pay = read_double();
            if (pay > 0 && pay <= A[i].balance)
            {
                A[i].balance -= pay;
                A[i].loan -= pay;
                if (A[i].loan < 0)
                    A[i].loan = 0;
                printf("Paid. Due: %.2f | Balance: %.2f\n",
                       A[i].loan, A[i].balance);
            }
            else
                printf("Invalid or not enough money.\n");
            wait_enter();
        }
        else if (c == 3)
        {
            printf("Loan due: %.2f\n", A[i].loan);
            wait_enter();
        }
    } while (c != 0);
}

/* ================= 9) ELECTRONIC BANKING ================= */

static void e_banking(void)
{
    printf("\nAccount ID: ");
    int id = read_int();
    int i = find_index_by_id(id);
    if (i < 0)
    {
        printf("Not found.\n");
        wait_enter();
        return;
    }

    int c;
    do
    {
        printf("\n== Electronic Banking ==\n");
        printf("ATM: %s | Debit: %s | Credit: %s\n",
               A[i].atm ? "ON" : "OFF",
               A[i].debit ? "ON" : "OFF",
               A[i].credit ? "ON" : "OFF");
        printf("1) Toggle ATM\n2) Toggle Debit\n3) Toggle Credit\n0) Back\n> ");
        c = read_int();

        if (c == 1)
            A[i].atm = !A[i].atm;
        else if (c == 2)
            A[i].debit = !A[i].debit;
        else if (c == 3)
            A[i].credit = !A[i].credit;
    } while (c != 0);
}

/* ================= MAIN MENU ================= */

static void menu(void)
{
    int ch;
    do
    {
        printf("\n================= Banking System =================\n");
        printf("1. Information Desk Operation\n");
        printf("2. New Account Opening\n");
        printf("3. Cash Counter Management\n");
        printf("4. Debit Service\n");
        printf("5. Credit Service\n");
        printf("6. FDR Service\n");
        printf("7. Savings Certificates Services\n");
        printf("8. Loan Service\n");
        printf("9. Electronic Banking (ATM/Debit/Credit)\n");
        printf("10. Exit\n==================================================\n> ");

        ch = read_int();

        if (ch == 1)
            info_desk();
        else if (ch == 2)
            new_account();
        else if (ch == 3)
            cash_counter();
        else if (ch == 4)
            debit_service();
        else if (ch == 5)
            credit_service();
        else if (ch == 6)
            fdr_service();
        else if (ch == 7)
            savings_certs();
        else if (ch == 8)
            loan_service();
        else if (ch == 9)
            e_banking();
        else if (ch == 10)
            printf("Goodbye!\n");
        else
        {
            printf("Wrong choice.\n");
            wait_enter();
        }
    } while (ch != 10);
}

/* ================= MAIN ================= */

int main(void)
{
    load_accounts(); // load from accounts.txt
    menu();
    save_accounts(); // save to accounts.txt
    return 0;
}
