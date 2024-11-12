# Write your MySQL query statement below
SELECT
e.employee_id
,e.name
,COUNT(*) AS reports_count
,ROUND(AVG(r.age)) AS average_age
FROM Employees e
JOIN Employees r ON e.employee_id = r.reports_to
GROUP BY employee_id
ORDER BY employee_id
;