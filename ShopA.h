#pragma once
#include "Shop.h"

class ShopA : public Shop {
public:
    ShopA() : Shop("ElectroShop") {
        addProduct(Product("Телевізор Samsung", 15000, 1, 0.10));
        addProduct(Product("Ноутбук Acer", 22000, 1, 0.15));
    }
};