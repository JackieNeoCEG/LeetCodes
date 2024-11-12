# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
LEFT JOIN Employees m
ON m.employee_id = e.manager_id
WHERE e.salary < 30000
AND m.employee_id IS NULL
AND e.manager_id IS NOT NULL
ORDER BY employee_id ASC
;