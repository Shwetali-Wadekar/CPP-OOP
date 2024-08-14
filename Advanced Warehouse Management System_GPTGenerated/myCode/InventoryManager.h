#ifndef INVENTORYMANAGER_H_
#define INVENTORYMANAGER_H_

#include <vector>
#include <map>
#include <string>
#include <memory>
#include "Warehouse.h"

/**
 * Represents an inventory manager responsible for managing multiple warehouses.
 */
class InventoryManager {
private:
    std::vector<std::unique_ptr<Warehouse>> warehouses;

public:
    /**
     * Adds a warehouse to the inventory manager.
     *
     * @param warehouse the warehouse to add
     */
    void addWarehouse(std::unique_ptr<Warehouse> warehouse);

    /**
     * Finds a warehouse by its name.
     *
     * @param name the warehouse's name
     * @return a pointer to the warehouse if found, nullptr otherwise
     */
    Warehouse* findWarehouseByName(const std::string& name);

    /**
     * Generates a report of all products in all warehouses.
     *
     * @return a string containing the report
     */
    std::string generateProductReport() const;

    /**
     * Calculates the total value of all products in all warehouses.
     *
     * @return the total value
     */
    float calculateTotalValue() const;
};

#endif /* INVENTORYMANAGER_H_ */
