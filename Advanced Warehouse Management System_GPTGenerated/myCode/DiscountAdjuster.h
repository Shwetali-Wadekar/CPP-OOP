#ifndef DISCOUNTADJUSTER_H_
#define DISCOUNTADJUSTER_H_

#include <string>
#include <map>
#include "Product.h"

/**
 * Adjusts the price of products based on discount rules.
 */
class DiscountAdjuster {
private:
    std::map<std::string, float> discounts; // product ID to discount percentage

public:
    /**
     * Adds a discount for a product.
     *
     * @param productId the product's ID
     * @param discount the discount percentage (0 to 1)
     */
    DiscountAdjuster& addDiscount(const std::string& productId, float discount);

    /**
     * Adjusts the price of the given product based on the discount rules.
     *
     * @param product the product to adjust
     * @return the adjusted price
     */
    float adjust(const Product& product) const;
};

#endif /* DISCOUNTADJUSTER_H_ */
