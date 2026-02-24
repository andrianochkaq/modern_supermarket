#pragma once
#include "Product.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // для system()
using namespace std;

class Shop {
protected:
    string name;
    Product products[10];
    int productCount = 0;

public:
    Shop(string n) : name(n) {}

    string getName() const { return name; }

    void addProduct(const Product& p) {
        if (productCount < 10) products[productCount++] = p;
    }

    void showProducts() {
        cout << "\n=== Товари магазину " << name << " ===\n";
        for (int i = 0; i < productCount; i++) {
            cout << i + 1 << ") " << products[i].getName()
                << " — " << products[i].getPrice() << " грн"
                << " (знижка: " << products[i].getDiscount() * 100 << "%)\n";
        }
    }

    Product chooseProduct() {
        int choice;
        cout << "Виберіть товар: ";
        cin >> choice;
        while (choice < 1 || choice > productCount) {
            cout << "Помилка. Спробуйте ще раз: ";
            cin >> choice;
        }
        Product p = products[choice - 1];

        int qty;
        cout << "Введіть кількість: ";
        cin >> qty;
        p.setQuantity(qty);
        return p;
    }

    void createReceipt(const Product& p) {
        static int receiptNumber = 1;
        string filename = "receipts/receipt_" + to_string(receiptNumber++) + ".txt";

        // Створюємо чек
        ofstream file(filename);
        double discount = p.getPrice() * p.getDiscount();
        double finalPrice = p.getPrice() - discount;

        file << "Магазин: " << name << "\n";
        file << "Товар: " << p.getName() << "\n";
        file << "Ціна: " << p.getPrice() << " грн\n";
        file << "Знижка: " << discount << " грн\n";
        file << "Ціна зі знижкою: " << finalPrice << " грн\n";
        file << "Кількість: " << p.getQuantity() << "\n";
        file << "Сума: " << finalPrice * p.getQuantity() << " грн\n";
        file.close();
        cout << "Чек створено: " << filename << endl;

        // --- Автоматично додаємо чек до Git і пушимо ---
        string cmd = "git add " + filename;
        system(cmd.c_str());
        system("git commit -m \"Додано новий чек\"");
        system("git push");
    }
};