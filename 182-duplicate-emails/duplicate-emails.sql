# Write your MySQL query statement below
SELECT email FROM Person AS Email
group by email
having COUNT(email) > 1;
