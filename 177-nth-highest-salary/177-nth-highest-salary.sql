CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT Distinct(salary) FROM Employee e1 where N-1 = (SELECT Count(Distinct(Salary)) from Employee e2 WHERE e2.salary > e1.salary)
      
  );
END