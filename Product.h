#pragma once
#include <string>
#include <windows.h>
using namespace std;

class Product {
private:
    string name;
    double price;
    int quantity;
    double discount;

public:
    Product() : name(""), price(0), quantity(1), discount(0) {}
    Product(string n, double p, int q, double d) : name(n), price(p), quantity(q), discount(d) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    double getDiscount() const { return discount; }
    void setQuantity(int q) { quantity = q; }
};
