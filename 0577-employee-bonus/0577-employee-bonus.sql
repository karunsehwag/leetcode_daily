# Write your MySQL query statement below
SELECT Employee.name ,Bonus.bonus
FROM Employee
LEFT JOIN Bonus ON Employee.empId=Bonus.empId
WHERE Bonus.bonus IS NULL OR 1000>Bonus.bonus;