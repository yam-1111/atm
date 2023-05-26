#include <functions/ATM-functions-edited.h>

float curr_bal = 5000;

int processing_screen(void) {
    printf("\n\t    Processing");

    for (int i = 0; i < 10; i++) {
        printf("..");
        fflush(stdout);  // Flush the output buffer

        // Add a delay to simulate loading
        usleep(250000);  // Sleep for 250 milliseconds (0.25 seconds)

        printf("\b");  // Move the cursor back by one character
    }
}

int aborting_screen(void) {
    printf("\n\n\t    Exiting");

    for (int i = 0; i < 10; i++) {
        printf("..");
        fflush(stdout);  // Flush the output buffer

        // Add a delay to simulate loading
        usleep(100000);  // Sleep for 100 milliseconds (0.1 seconds)

        printf("\b");  // Move the cursor back by one character
    }
}

int PINcheck(char PIN[6]) {
    char PINconfirm[6] = {}; // Array to store the confirmed PIN
    int p = 0, not_match = 0; // Counter variable and mismatch count

    printf("\n\n\tConfirm your PIN");
    printf("\n\n\t\tRe-Enter PIN: ");
    do {
        PINconfirm[p] = getch(); // Read a character from input
        if (PINconfirm[p] != '\r') { // If the character is not the carriage return
            printf("*"); // Print an asterisk to mask the input
        }
        p++;
    } while (PINconfirm[p - 1] != '\r' && p <= 6); // Continue until carriage return or maximum length is reached
    PINconfirm[p - 1] = '\0'; // Terminate the confirmed PIN string

    for (int i = 0; i < 6; i++) {
        if (PIN[i] != PINconfirm[i]) { // Compare each character of the original and confirmed PIN
            not_match++; // Increment the mismatch count
        }
    }
    printf("\n");

    return not_match; // Return the number of mismatches
}


float deposit(float amnt) {
    int depo_conf, rep; // Variables for deposit confirmation and repetition

    printf("\n\t>>> You want to deposit P%.2f.", amnt);
    printf("\n\nDo you want to proceed?");
    printf("\n\t[1] OK\n\t[0] Cancel\n\t>\t");

    do
    {
        if (scanf("%d", &depo_conf) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);
    
    if (amnt >= 0) {
        if (depo_conf == 1) {
            processing_screen();
            printf("\n\n\tDeposit Successful!");

            curr_bal += amnt; // Add the deposited amount to the current balance

            printf("\n\n>>> Your current balance is P%.2f", curr_bal);
            getch();
        } else if (depo_conf == 0) {
            printf("\n\n>> Deposit Unsuccessful!");
            getch();
        }
    }
    else {
        printf("\n\nInvalid transaction. You cannot deposit a negative amount!");
        getch();
    }
    printf("\n\n============================================");
    
    do
    {
        printf("\n\nDo you want to deposit again?");
        printf("\n\t[1] Yes\n\t[0] No\n\t>\t");

        if (scanf("%d", &rep) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);
    printf("\n");

    return rep; // Return the value indicating whether to repeat the deposit or not
}

float withdraw(float amnt) {
    int wid_conf, rep; // Variables for withdrawal confirmation and repetition

    printf("\n\t>>> You want to withdraw P%.2f.", amnt);
    printf("\n\nDo you want to proceed?");
    printf("\n\t[1] OK\n\t[0] Cancel\n\t>\t");

    do
    {
        if (scanf("%d", &wid_conf) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);

    if (amnt < 0) {
        printf("\n\nInvalid transaction. You cannot withdraw a negative amount!");
        getch();
    }
    else if (amnt <= curr_bal) {
        
        if (wid_conf == 1) {
            processing_screen();
            curr_bal -= amnt; // Subtract the withdrawal amount from the current balance

            printf("\n\n\t>>> Your current balance is P%.2f", curr_bal);
            printf("\n\nWithdrawal Successful! Please get your money.");
            getch();
        } else if (wid_conf == 0) {
            printf("\n>> Withdrawal Unsuccessful!");
            getch();
        }
    }
    else {
        printf("\n\nInvalid transaction. Your withdrawn amount is bigger than your current balance!");
        getch();
    }
    printf("\n\n============================================");

    do
    {
        printf("\n\nDo you want to withdraw again?");
        printf("\n\t[1] Yes\n\t[0] No\n\t>\t");

        if (scanf("%d", &rep) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);

    printf("\n");

    return rep; // Return the value indicating whether to repeat the withdrawal or not
}

int PINcompare(const char PIN[6], const char PIN2[6]) {
    int match = 0; // Variable to count the number of matching digits

    // Iterate over each digit in the PINs
    for (int i = 0; i < 6; i++) {
        if (PIN[i] == PIN2[i]) {
            match++; // Increment the count if the digits match
        }
    }

    // Check if all digits match or not
    if (match != 6) {
        return 1; // Return 1 if the PINs don't match
    } else {
        return 0; // Return 0 if the PINs match
    }
}

int inquiry(void) {
    int rep; // Variable for repetition choice

    processing_screen(); // Simulate processing

    printf("\n\n\t>>> Your current balance is P%.2f", curr_bal); // Display the current balance
    getch();

    printf("\n\n============================================");
    printf("\n\nDo you want to inquire your balance again?");

    do {
        printf("\n\t[1] Yes\n\t[0] No\n\t>\t");
        if (scanf("%d", &rep) != 1)
        { // Check if the input is a valid integer
            printf("\n\t>> Invalid input. Please enter 0 or 1.\n");
            getch();
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);

    printf("\n");

    return rep; // Return the value indicating whether to repeat the inquiry or not
}

void exit_menu(int conf) {
    if (conf == 1) {
        printf("\n#####################################################################################\n");
        processing_screen(); // Simulate processing
        printf("\n\n>>> Please get your card.");
        aborting_screen(); //Simulate exiting
        printf("\n\n>>> Thank you for using R2 Banking!\n\n");
    }
}

