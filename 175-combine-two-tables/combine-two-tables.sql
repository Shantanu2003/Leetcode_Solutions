# Write your MySQL query statement below
/* Write your T-SQL query statement below */
SELECT Person.firstName,Person.lastName, Address.city, Address.state
FROM Person 
LEFT JOIN Address 
ON Person.personID = Address.personId
