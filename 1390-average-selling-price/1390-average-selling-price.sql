# Write your MySQL query statement below
SELECT 
    p.product_id
    
    -- replace null with 0, round to 2dp, averaging formula
    ,IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units), 2), 0) average_price
FROM Prices p LEFT JOIN UnitsSold u 
ON u.product_id = p.product_id AND
u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY product_id
;
