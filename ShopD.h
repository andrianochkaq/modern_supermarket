#pragma once
#include "Shop.h"

class ShopD : public Shop {
public:
    ShopD() : Shop("SuperTech") {
        addProduct(Product("Ноутбук HP", 20000, 1, 0.15));
        addProduct(Product("Мишка Razer", 800, 1, 0.05));
    }
};
