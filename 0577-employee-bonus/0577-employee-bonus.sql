SELECT Employee.name, Bonus.bonus
FROM Employee
LEFT JOIN Bonus 
ON Employee.empId = Bonus.empId
WHERE Bonus.empId IS NULL 
OR Bonus.bonus < 1000;
