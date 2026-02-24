#include <iostream>
#include "ShopA.h"
#include "ShopB.h"
#include "ShopC.h"
#include "ShopD.h"
using namespace std;

int main() {
SetConsoleOutputCP(65001);
SetConsoleCP(65001);
cout << "=== ЛЮДИНА  — СИСТЕМА ПОКУПОК ===\n";
ShopA a;
ShopB b;
ShopC c;
ShopD d;

    while (true) {
        cout << "\nВиберіть магазин:\n1 — ElectroShop\n2 — TechWorld\n3 — MegaStore\n4 — SuperTech\n0 — Вихід\nВаш вибір: ";
        int choice; cin >> choice;
        if (choice == 0) break;

        Shop* selected = nullptr;
        if (choice == 1) selected = &a;
        else if (choice == 2) selected = &b;
        else if (choice == 3) selected = &c;
        else if (choice == 4) selected = &d;
        else continue;
        

        selected->showProducts();
        Product p = selected->chooseProduct();
        selected->createReceipt(p);
    }
    cout << "Дякуємо за покупки!\n";
    return 0;
}