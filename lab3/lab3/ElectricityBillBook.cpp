#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class ElectricityBillBook {
private:
    double costPerKwh;      // cost per kilowatt-hour
    string date;           // date
    double paidAmount;      // paid amount

public:
    // Constructors
    ElectricityBillBook() : costPerKwh(0), date(""), paidAmount(0) {}

    ElectricityBillBook(double cost, const string& dt, double amount) {
        // Exception handling in constructor
        if (cost < 0) throw invalid_argument("Cost cannot be negative");
        if (dt.empty()) throw invalid_argument("Date cannot be empty");
        if (amount < 0) throw invalid_argument("Amount cannot be negative");

        costPerKwh = cost;
        date = dt;
        paidAmount = amount;
    }

    // Getters with exception handling
    double getCostPerKwh() const {
        return costPerKwh;
    }

    string getDate() const {
        if (date.empty()) throw invalid_argument("Date is not set");
        return date;
    }

    double getPaidAmount() const {
        return paidAmount;
    }

    // Setters with exception handling
    void setCostPerKwh(double cost) {
        if (cost < 0) throw invalid_argument("Cost cannot be negative");
        costPerKwh = cost;
    }

    void setDate(const string& dt) {
        if (dt.empty()) throw invalid_argument("Date cannot be empty");
        date = dt;
    }

    void setPaidAmount(double amount) {
        if (amount < 0) throw invalid_argument("Amount cannot be negative");
        paidAmount = amount;
    }

    // Overloaded ++ operator (increases values by 1)
    ElectricityBillBook& operator++() {
        costPerKwh += 1.0;
        paidAmount += 1.0;
        return *this;
    }

    ElectricityBillBook operator++(int) {
        ElectricityBillBook temp = *this;
        ++(*this);
        return temp;
    }

    // Overloaded -= operator (decreases values by given amount)
    ElectricityBillBook& operator-=(double value) {
        if (value < 0) throw invalid_argument("Decrement value cannot be negative");

        costPerKwh -= value;
        paidAmount -= value;

        // Prevent negative values
        if (costPerKwh < 0) costPerKwh = 0;
        if (paidAmount < 0) paidAmount = 0;

        return *this;
    }

    // Overloaded search method by date
    static vector<ElectricityBillBook> findByDate(
        const vector<ElectricityBillBook>& bills,
        const string& searchDate) {

        if (searchDate.empty()) throw invalid_argument("Search date cannot be empty");

        vector<ElectricityBillBook> result;
        for (const auto& bill : bills) {
            if (bill.getDate() == searchDate) {
                result.push_back(bill);
            }
        }
        return result;
    }

    void display() const {
        cout << "Date: " << date << ", Cost per kWh: " << costPerKwh
            << " UAH, Paid: " << paidAmount << " UAH" << endl;
    }
};

// Helper function for displaying vector
void displayBills(const vector<ElectricityBillBook>& bills, const string& title) {
    cout << "\n" << title << ":" << endl;
    for (const auto& bill : bills) {
        bill.display();
    }
    if (bills.empty()) {
        cout << "No records found" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    try {
        cout << "=== LABORATORY WORK #3 ===" << endl;
        cout << "=== ELECTRICITY BILL BOOK ===" << endl;

        // Create test data
        vector<ElectricityBillBook> bills = {
            ElectricityBillBook(2.5, "2024-01-15", 150.0),
            ElectricityBillBook(2.8, "2024-01-20", 200.0),
            ElectricityBillBook(2.5, "2024-02-01", 180.0),
            ElectricityBillBook(3.0, "2024-01-20", 250.0)
        };

        // Display initial data
        displayBills(bills, "All electricity bill records");

        // Testing ++ operator
        cout << "\n=== Testing ++ operator ===" << endl;
        ElectricityBillBook bill1 = bills[0];
        cout << "Initial record: ";
        bill1.display();

        // Prefix form
        ++bill1;
        cout << "After ++bill: ";
        bill1.display();

        // Postfix form
        bill1++;
        cout << "After bill++: ";
        bill1.display();

        // Testing -= operator
        cout << "\n=== Testing -= operator ===" << endl;
        ElectricityBillBook bill2 = bills[1];
        cout << "Initial record: ";
        bill2.display();

        bill2 -= 0.5;
        cout << "After -= 0.5: ";
        bill2.display();

        bill2 -= 1.0;
        cout << "After -= 1.0: ";
        bill2.display();

        // Testing search by date
        cout << "\n=== Testing search by date ===" << endl;

        auto foundBills = ElectricityBillBook::findByDate(bills, "2024-01-20");
        displayBills(foundBills, "Records for 2024-01-20");

        foundBills = ElectricityBillBook::findByDate(bills, "2024-02-01");
        displayBills(foundBills, "Records for 2024-02-01");

        foundBills = ElectricityBillBook::findByDate(bills, "2024-03-01");
        displayBills(foundBills, "Records for 2024-03-01");

        // Testing exception handling
        cout << "\n=== Testing exception handling ===" << endl;

        // Test 1: Invalid cost
        try {
            cout << "Attempt to create record with negative cost:" << endl;
            ElectricityBillBook invalidBill(-1.0, "2024-01-01", 100.0);
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Test 2: Invalid date
        try {
            cout << "\nAttempt to set empty date:" << endl;
            ElectricityBillBook bill(2.5, "2024-01-01", 100.0);
            bill.setDate("");
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Test 3: Invalid paid amount
        try {
            cout << "\nAttempt to set negative paid amount:" << endl;
            ElectricityBillBook bill(2.5, "2024-01-01", 100.0);
            bill.setPaidAmount(-50.0);
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Test 4: Invalid value for -=
        try {
            cout << "\nAttempt to use negative value in -= operation:" << endl;
            ElectricityBillBook bill(2.5, "2024-01-01", 100.0);
            bill -= -10.0;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        // Test 5: Search with empty date
        try {
            cout << "\nAttempt to search with empty date:" << endl;
            auto result = ElectricityBillBook::findByDate(bills, "");
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "\n=== Testing completed successfully ===" << endl;

    }
    catch (const exception& e) {
        cerr << "Critical error: " << e.what() << endl;
        return 1;
    }

    return 0;
}