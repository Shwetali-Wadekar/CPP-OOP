#ifndef WAREHOUSEMANAGER_H_
#define WAREHOUSEMANAGER_H_

#include <string>
#include "InventoryManager.h"

/**
 * Represents a warehouse manager responsible for managing the inventory.
 */
class WarehouseManager {
private:
    std::string name;
    InventoryManager& inventoryManager;

public:
    /**
     * Initializes a new warehouse manager with the given name.
     *
     * @param name the warehouse manager's name
     * @param inventoryManager the inventory manager
     */
    WarehouseManager(const std::string& name, InventoryManager& inventoryManager);

    /**
     * Returns the warehouse manager's name.
     *
     * @return the warehouse manager's name
     */
    std::string getName() const;

    /**
     * Adds a warehouse to the inventory.
     *
     * @param warehouseName the warehouse's name
     */
    void addWarehouseToInventory(const std::string& warehouseName);

    /**
     * Adds a product to a warehouse.
     *
     * @param warehouseName the warehouse's name
     * @param productName the product's name
     * @param productId the product's ID
     * @param price the product's price
     */
    void addProductToWarehouse(const std::string& warehouseName, const std::string& productName, const std::string& productId, float price);

    /**
     * Removes a product from a warehouse.
     *
     * @param warehouseName the warehouse's name
     * @param productId the product's ID
     */
    void removeProductFromWarehouse(const std::string& warehouseName, const std::string& productId);
};

#endif /* WAREHOUSEMANAGER_H_ */
