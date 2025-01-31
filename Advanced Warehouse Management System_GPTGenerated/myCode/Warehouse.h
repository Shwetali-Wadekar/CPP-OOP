#ifndef WAREHOUSE_H_
#define WAREHOUSE_H_

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

/**
 * Represents a warehouse in the warehouse management system.
 */
class Warehouse {
private:
    std::string name;
    std::vector<std::unique_ptr<Product>> products;

public:
    /**
     * Initializes a new warehouse with the given name.
     *
     * @param name the warehouse's name
     */
    Warehouse(const std::string& name);

    /**
     * Returns the warehouse's name.
     *
     * @return the warehouse's name
     */
    std::string getName() const;

    /**
     * Adds a product to the warehouse.
     *
     * @param product the product to add
     */
    void addProduct(std::unique_ptr<Product> product);

    /**
     * Removes a product from the warehouse by ID.
     *
     * @param productId the product's ID
     * @throws std::invalid_argument if the product is not found
     */
    void removeProduct(const std::string& productId);

    /**
     * Finds a product by its ID.
     *
     * @param productId the product's ID
     * @return a pointer to the product if found, nullptr otherwise
     */
    Product* findProductById(const std::string& productId);

    std::vector<Product*> allproducts();
};

#endif /* WAREHOUSE_H_ */
