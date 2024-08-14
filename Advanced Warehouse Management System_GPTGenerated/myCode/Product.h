#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

/**
 * Represents a product in the warehouse management system.
 */
class Product {
private:
    std::string name;
    std::string productId;
    float price;

public:
    /**
     * Initializes a new product with the given name, ID, and price.
     *
     * @param name the product's name
     * @param productId the product's ID
     * @param price the product's price
     */
    Product(const std::string& name, const std::string& productId, float price);

    /**
     * Returns the product's name.
     *
     * @return the product's name
     */
    std::string getName() const;

    /**
     * Returns the product's ID.
     *
     * @return the product's ID
     */
    std::string getProductId() const;

    /**
     * Returns the product's price.
     *
     * @return the product's price
     */
    float getPrice() const;

    /**
     * Sets the product's price.
     *
     * @param price the new price
     */
    void setPrice(float price);
};

#endif /* PRODUCT_H_ */
