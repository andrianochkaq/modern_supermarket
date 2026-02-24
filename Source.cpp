#include <iostream>
#include "ShopA.h"
#include "ShopB.h"
using namespace std;

int main() {
SetConsoleOutputCP(65001);
SetConsoleCP(65001);
    cout << "=== ЛЮДИНА 1 — СИСТЕМА ПОКУПОК ===\n";
    ShopA a;
    ShopB b;

    while (true) {
        cout << "\nВиберіть магазин:\n1 — ElectroShop\n2 — TechWorld\n0 — Вихід\nВаш вибір: ";
        int choice; cin >> choice;
        if (choice == 0) break;

        Shop* selected = nullptr;
        if (choice == 1) selected = &a;
        else if (choice == 2) selected = &b;
        else continue;

        selected->showProducts();
        Product p = selected->chooseProduct();
        selected->createReceipt(p);
    }

    cout << "Дякуємо за покупки!\n";
    return 0;
}