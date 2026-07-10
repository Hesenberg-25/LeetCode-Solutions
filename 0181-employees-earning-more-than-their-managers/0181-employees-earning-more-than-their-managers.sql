SELECT emp.name AS Employee
FROM Employee emp
JOIN Employee mgr 
  ON emp.managerId = mgr.id
WHERE emp.salary > mgr.salary;