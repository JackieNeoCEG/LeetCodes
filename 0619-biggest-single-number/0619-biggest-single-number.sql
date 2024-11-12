# Write your MySQL query statement below
-- To remove duplicate numbers, we use a subquery to 
-- generate a new table with single numbers only

SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) AS SingleNumTable