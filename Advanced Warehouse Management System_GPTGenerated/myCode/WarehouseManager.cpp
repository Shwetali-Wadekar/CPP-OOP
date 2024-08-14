/*
 * WarehouseManager.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: pradh
 */

#include "WarehouseManager.h"
#include<stdexcept>
WarehouseManager::WarehouseManager(const std::string &name,
		InventoryManager &inventoryManager) : name(name) , inventoryManager(inventoryManager)
{
}

std::string WarehouseManager::getName() const
{
	return name;
}

void WarehouseManager::addWarehouseToInventory(const std::string &warehouseName)
{
	std::unique_ptr<Warehouse> warehouse(new Warehouse(warehouseName));
	inventoryManager.addWarehouse(std::move(warehouse));
}

void WarehouseManager::addProductToWarehouse(const std::string &warehouseName,
		const std::string &productName, const std::string &productId,
		float price)
{
	std::unique_ptr<Product> product(new Product(productName,productId,price));

	auto foundWarehouse=inventoryManager.findWarehouseByName(warehouseName);

	if(foundWarehouse!=nullptr) {
		foundWarehouse->addProduct(std::move(product));
	}else {
		throw std::invalid_argument("warehouse not exist");
	}
}

void WarehouseManager::removeProductFromWarehouse(
		const std::string &warehouseName, const std::string &productId)
{
	auto foundWarehouse=inventoryManager.findWarehouseByName(warehouseName);

	if(foundWarehouse!=nullptr) {
		foundWarehouse->removeProduct(productId);

	}else {
		throw std::invalid_argument("warehouse not exist");
	}
}
