// VendingMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

struct Item {
    /*I'm not sure exactly why i need to define this string here but it didn't compile
    * without it and a guy on stackoverflow said this would fix it. Bizarre times.
    * 
    */
    std::string name;
    double price;
    int stockCount;
    bool isAvailable;

    // Setting up a constructor for "item"
    Item(std::string n = "", double p = 0.00, int s = 0)
        : name(n), price(p), stockCount(s), isAvailable(s > 0) {
    }
};

// Function to let the user input money
void inputMoney(double& totalMoney) {
    double amount;
    std::cout << "Enter the amount of money you're adding: £";
    std::cin >> amount;

    if (amount > 0) {
        totalMoney += amount;
        std::cout << "You now have £" << totalMoney << " available.\n";
    }
    else {
        std::cout << "Invalid amount. Please enter a positive value.\n";
    }
}


int main() {
    // Create a 5x5 vending machine grid
    std::vector<std::vector<Item>> vendingMachine(5, std::vector<Item>(5));

    vendingMachine[0][0] = Item("Coke", 1.50, 10);
    vendingMachine[0][1] = Item("Walkers ready salted", 1.00, 5);
    vendingMachine[0][2] = Item("Wispa", 1.25, 8);
    vendingMachine[0][3] = Item("5Gum", 0.50, 20);
    vendingMachine[0][4] = Item("Water", 1.00, 15);

    vendingMachine[1][0] = Item("Monster", 2.50, 7);
    vendingMachine[1][1] = Item("Maryland cookies", 1.75, 10);
    vendingMachine[1][2] = Item("Brunch Bar", 1.00, 12);
    vendingMachine[1][3] = Item("Salted Pretzels", 1.25, 6);
    vendingMachine[1][4] = Item("Copella Apple juice", 1.75, 10);

    vendingMachine[2][0] = Item("Cadburys chocolate bar", 2.00, 5);
    vendingMachine[2][1] = Item("bag of peanuts", 1.25, 8);
    vendingMachine[2][2] = Item("Trail Mix", 2.50, 4);
    vendingMachine[2][3] = Item("Crackers", 1.00, 9);
    vendingMachine[2][4] = Item("Popcorn", 1.50, 7);

    vendingMachine[3][0] = Item("rice crispies bar", 1.25, 10);
    vendingMachine[3][1] = Item("box of raisins", 1.00, 15);
    vendingMachine[3][2] = Item("air gum", 0.75, 25);
    vendingMachine[3][3] = Item("digestives", 1.50, 5);
    vendingMachine[3][4] = Item("instant coffee granules", 1.75, 8);

    vendingMachine[4][0] = Item("milk", 1.50, 6);
    vendingMachine[4][1] = Item("crunchie", 2.25, 5);
    vendingMachine[4][2] = Item("Protein Bar", 2.75, 3);
    vendingMachine[4][3] = Item("mcvities select pack", 3.00, 2);
    vendingMachine[4][4] = Item("hot chocolate sachets", 2.00, 4);


    double totalMoney = 0.0; // set total money to 0

    // User menu
    int choice;
    do {
        std::cout << "\nVending Machine Menu:\n";
        std::cout << "1. Input money\n";
        std::cout << "2. View total money\n";
        std::cout << "3. Display Full Selection\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            inputMoney(totalMoney); // Call the function to input money
            break;
        case 2:
            std::cout << "You have £" << totalMoney << "!\n";
            break;
        case 3:
            // Display the entire vending machine stock
            for (int i = 0; i < vendingMachine.size(); ++i) {
                for (int j = 0; j < vendingMachine[i].size(); ++j) {
                    const Item& item = vendingMachine[i][j];
                    std::cout << "Item at (" << i << ", " << j << "): "
                        << item.name << " | £" << item.price
                        << " | Stock: " << item.stockCount
                        << (item.isAvailable ? " | Available" : " | Out of Stock")
                        << '\n';
                }
            }
            break;
        case 4:
            std::cout << "see you later!\n";
            break;
        default:
            std::cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != 4);

    return 0;
}


