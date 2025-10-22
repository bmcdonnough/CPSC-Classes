-- ## Problem 7
-- 
-- Write a query to compute the total of all purchases, the number of purchases, and the average
-- purchase amount made by each customer. 
-- 
-- Your results must match those shown below. Sort the results by customer code.
-- 
-- +----------+-------------+-----------------+---------------------+-------------------------+
-- | CUS_CODE | CUS_BALANCE | Total Purchases | Number of Purchases | Average Purchase Amount |
-- +----------+-------------+-----------------+---------------------+-------------------------+
-- |  10011   |    0.00     |     444.00      |          6          |          74.00          |
-- |  10012   |   345.86    |     153.85      |          3          |          51.28          |
-- |  10014   |    0.00     |     422.77      |          6          |          70.46          |
-- |  10015   |    0.00     |      34.97      |          2          |          17.49          |
-- |  10018   |   216.55    |      70.44      |          1          |          70.44          |
-- +----------+-------------+-----------------+---------------------+-------------------------+
-- 
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT C.CUS_CODE,
	   C.CUS_BALANCE,
	   ROUND(SUM(L.LINE_UNITS * L.LINE_PRICE), 2) AS 'Total Purchases',
	   COUNT(*) AS 'Number of Purchases',
	   ROUND(AVG(L.LINE_UNITS * L.LINE_PRICE), 2) AS 'Average Purchase Amount'
FROM CUSTOMER AS C
JOIN INVOICE AS I
ON I.CUS_CODE = C.CUS_CODE
JOIN LINE AS L
ON L.INV_NUMBER = I.INV_NUMBER
GROUP BY C.CUS_CODE
ORDER BY C.CUS_CODE;