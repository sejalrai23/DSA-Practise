# Write your MySQL query statement below
SELECT firstName , lastName , city, state FROM Person LEFT JOIN Address On ( Person.personId = Address.personId)