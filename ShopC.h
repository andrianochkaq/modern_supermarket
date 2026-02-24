
#pragma once
#include "Shop.h"

class ShopC : public Shop {
public:
    ShopC() : Shop("MegaStore") {
        addProduct(Product("Холодильник LG", 18000, 1, 0.12));
        addProduct(Product("Піч Samsung", 7000, 1, 0.10));
    }
};