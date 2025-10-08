#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Ingredient {
private:
    string name;
    double quantity;
    double price;
    string unit;
public:
    // Конструктор з параметрами замість методу set
    Ingredient(string n = "", double q = 0, double p = 0, string u = "kg") {
        name = n;
        quantity = q;
        price = p;
        unit = u;
    }

    string getname() {
        return name;
    }

    double getquantity() {
        return quantity;
    }

    double getprice() {
        return price;
    }

    string getunit() {
        return unit;
    }

    void show() {
        cout << name << ": " << quantity << " " << unit << ", " << price << " UAH/" << unit << endl;
    }

    double getcost() {
        return quantity * price;
    }
};

class Recipe {
private:
    string name;
    Ingredient* ingredients; // Динамічний масив
    int count;
    int capacity; // Максимальна кількість інгредієнтів
public:
    Recipe() {
        name = "";
        count = 0;
        capacity = 10; // Початковий розмір
        ingredients = new Ingredient[capacity]; // Виділяємо пам'ять
    }

    // Деструктор - звільняємо пам'ять
    ~Recipe() {
        delete[] ingredients;
    }

    void set(string n) {
        name = n;
    }

    string getname() {
        return name;
    }

    void addIngredient(Ingredient ing) {
        if (count < capacity) {
            ingredients[count] = ing;
            count++;
        }
    }

    void show() {
        cout << "=== RECIPE: " << name << " ===" << endl;
        cout << "Ingredients:" << endl;

        double totalCost = 0;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            ingredients[i].show();
            totalCost += ingredients[i].getcost();
        }
        cout << "Total cost: " << totalCost << " UAH" << endl;
    }

    void saveToFile() {
        ofstream file("recipes.txt", ios::app);
        if (file.is_open()) {
            file << name << endl;
            file << count << endl;
            for (int i = 0; i < count; i++) {
                file << ingredients[i].getname() << " "
                    << ingredients[i].getquantity() << " "
                    << ingredients[i].getunit() << " "
                    << ingredients[i].getprice() << endl;
            }
            file << "---" << endl;
            file.close();
            cout << "Recipe saved to file!" << endl;
        }
    }

    bool searchInFile(string searchName) {
        ifstream file("recipes.txt");
        if (file.is_open()) {
            string currentName;
            int ingCount;

            while (file >> currentName) {
                if (currentName == searchName) {
                    file >> ingCount;
                    name = searchName;
                    count = 0; // Очищаємо старі інгредієнти

                    for (int i = 0; i < ingCount; i++) {
                        string ingName, unit;
                        double qty, prc;
                        file >> ingName >> qty >> unit >> prc;

                        // Використовуємо конструктор замість set
                        Ingredient ing(ingName, qty, prc, unit);
                        addIngredient(ing);
                    }
                    file.close();
                    return true;
                }
            }
            file.close();
        }
        return false;
    }
};

int main() {
    Recipe myRecipe;
    int choice;

    do {
        cout << "\n=== RECIPE MANAGEMENT SYSTEM ===" << endl;
        cout << "1. Create new recipe" << endl;
        cout << "2. Show recipe" << endl;
        cout << "3. Save recipe to file" << endl;
        cout << "4. Search recipe in file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int ingCount;

            cout << "Enter recipe name: ";
            cin >> name;
            myRecipe.set(name);
            cout << "How many ingredients? ";
            cin >> ingCount;

            for (int i = 0; i < ingCount; i++) {
                string ingName, unit;
                double qty, price;

                cout << "Ingredient " << i + 1 << ":" << endl;
                cout << "Name: "; cin >> ingName;
                cout << "Quantity: "; cin >> qty;
                cout << "Unit (kg, g, l, ml, pcs, etc.): "; cin >> unit;
                cout << "Price per " << unit << ": "; cin >> price;

                // Використовуємо конструктор замість set
                Ingredient ing(ingName, qty, price, unit);
                myRecipe.addIngredient(ing);
            }
            break;
        }

        case 2:
            myRecipe.show();
            break;

        case 3:
            myRecipe.saveToFile();
            break;

        case 4: {
            string searchName;
            cout << "Enter recipe name to search: ";
            cin >> searchName;

            if (myRecipe.searchInFile(searchName)) {
                cout << "Recipe found!" << endl;
                myRecipe.show();
            }
            else {
                cout << "Recipe not found!" << endl;
            }
            break;
        }

        case 5:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}