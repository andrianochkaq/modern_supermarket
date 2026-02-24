#pragma once
#include "Shop.h"

class ShopB : public Shop {
public:
    ShopB() : Shop("TechWorld") {
        addProduct(Product("Смартфон Xiaomi", 12000, 1, 0.08));
        addProduct(Product("Навушники Sony", 2500, 1, 0.10));
    }
};