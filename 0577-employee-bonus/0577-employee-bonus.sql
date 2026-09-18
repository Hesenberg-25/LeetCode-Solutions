SELECT E.name, B.bonus
FROM Employee AS E LEFT JOIN
Bonus AS B ON E.empId = B.empId
WHERE B.Bonus IS NULL OR
B.Bonus < 1000