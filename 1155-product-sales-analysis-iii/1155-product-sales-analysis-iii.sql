# Write your MySQL query statement below
-- filters Sales to include only rows where (product_id, year)
-- match each combination returned by the subquery
SELECT
    product_id
    ,year AS first_year
    ,quantity
    ,price
FROM Sales
WHERE (product_id, year) IN (
        -- Subquery returns minimum year for each product_id
        SELECT 
            product_id
            ,MIN(year)
        FROM sales
        GROUP BY product_id
);