#include <iostream>
#include "ShopC.h"
#include "ShopD.h"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    cout << "=== ЛЮДИНА 2 — СИСТЕМА ПОКУПОК ===\n";
    ShopC c;
    ShopD d;

    while (true) {
        cout << "\nВиберіть магазин:\n1 — MegaStore\n2 — SuperTech\n9 — Вихід\nВаш вибір: ";
        int choice; cin >> choice;
        if (choice == 9) break;

        Shop* selected = nullptr;
        if (choice == 1) selected = &c;
        else if (choice == 2) selected = &d;
        else continue;

        selected->showProducts();
        Product p = selected->chooseProduct();
        selected->createReceipt(p);
    }

    cout << "Дякуємо, що обрали наші магазини!\n";
    return 0;
}