#include "VendingMachine.h"
#include <iostream>

using namespace std;

void VendingMachine::adminMode() {
    int choice;
    while (true) {
        cout << "\n=== admin-mode ===\n";
        cout << "1. add water and sugar\n";
        cout << "2. check remaining\n";
        cout << "3. change price\n";
        cout << "4. take cash\n";
        cout << "5. quit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1) {
            int addWater, addSugar;
            cout << "how much water add (ml)? ";
            cin >> addWater;
            cout << "how much sugar add(g)? ";
            cin >> addSugar;
            water += addWater;
            sugar += addSugar;
            cout << "water and sugar added!\n";
        }
        else if (choice == 2) {
            cout << "water: " << water << " ml\n";
            cout << "sugar: " << sugar << " g\n";
            cout << "cash: " << cash << " dol\n";
        }
        else if (choice == 3) 
        {
            int newPrice;
            cout << "\n=== change price ===\n";
            cout << "1. Coffee (" << coffee.getPrice() << " dol)\n";
            cout << "2. Tea (" << tea.getPrice() << " dol)\n";
            cout << "3. Cappuccino (" << cappuccino.getPrice() << " dol)\n";
            cout << "choice: ";
            int drinkChoice;
            cin >> drinkChoice;

            cout << "Enter new price!: ";
            cin >> newPrice;
            if (drinkChoice == 1) 
            {
                ChangePrice(coffee, newPrice);
            }
            else if (drinkChoice == 2) {

                ChangePrice(tea, newPrice);
            }
        
            else if (drinkChoice == 3) 
            {
                ChangePrice(cappuccino, newPrice);
            }
            else 
            {
                cout << "Wrong choice, try one more time\n";
            }

            cout << "Price changed!\n";

        }
        else if (choice == 4) {
            cout << "Cash whic been taken: " << cash << " dol\n";
            cash = 0;
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Wrong choice\n";
        }
    }
}

void VendingMachine::userMode() {
    int choice;
    while (true) {
        cout << "\n=== user mode ===\n";
        cout << "1. Coffee (" << coffee.getPrice() << " dol)\n";
        cout << "2. Tea (" << tea.getPrice() << " dol)\n";
        cout << "3. Cappuccino (" << cappuccino.getPrice() << " dol)\n";
        cout << "4. quit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1) {
            processOrder(coffee);
        }
        else if (choice == 2) {
            processOrder(tea);
        }
        else if (choice == 3) {
            processOrder(cappuccino);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Wrong choice, try again\n";
        }
    }
}

void VendingMachine::processOrder(HotDrink& drink) {
    if (water < drink.getWaterRequired()) {
        cout << "not enough water for:  " << drink.getName() << ".\n";
        return;
    }
    if (sugar < drink.getSugarRequired()) {
        cout << "not enough sugar for:  " << drink.getName() << ".\n";
        return;
    }

    int payment;
    cout << "input " << drink.getPrice() << " dol: ";
    cin >> payment;

    if (payment < drink.getPrice()) {
        cout << "not enough cash.\n";
        return;
    }

    water -= drink.getWaterRequired();
    sugar -= drink.getSugarRequired();
    cash += drink.getPrice();

    cout << "your " << drink.getName() << " ready!\n";
    if (payment > drink.getPrice()) {
        cout << "your change: " << (payment - drink.getPrice()) << " dol\n";
    }
}

void VendingMachine::ChangePrice(HotDrink& drink, int newPrice) {
    class HotDrink& modifiableDrink = drink;
    modifiableDrink = HotDrink(drink.getName(), drink.getWaterRequired(), drink.getSugarRequired(), newPrice);
}