# Write your MySQL query statement below
SELECT customer_id
FROM Customer
GROUP BY customer_id

-- Using the first testcase, we need to reformat = 2 to a subquery
-- that can return count of all products in the Product table
# HAVING COUNT(DISTINCT product_key) = 2
HAVING COUNT(DISTINCT product_key) 
    =   (
        SELECT COUNT(product_key)
        FROM Product
        )
;