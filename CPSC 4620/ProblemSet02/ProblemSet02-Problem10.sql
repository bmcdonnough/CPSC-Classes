-- ## Problem 10
-- 
-- Write a query to produce the number of invoices and the total purchase amounts by customer.
-- Use the results shown below as your guide. 
-- 
-- Note the results are sorted by customer code.
-- 
-- +----------+--------------------+--------------------------+
-- | CUS_CODE | Number of Invoices | Total Customer Purchases |
-- +----------+--------------------+--------------------------+
-- |  10011   |         3          |          444.00          |
-- |  10012   |         1          |          153.85          |
-- |  10014   |         2          |          422.77          |
-- |  10015   |         1          |          34.97           |
-- |  10018   |         1          |          70.44           |
-- +----------+--------------------+--------------------------+
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT C.CUS_CODE,
	   COUNT(DISTINCT I.INV_NUMBER) AS 'Number of Invoices',
	   ROUND(SUM(L.LINE_UNITS * L.LINE_PRICE), 2) AS 'Total Customer Purchases'
FROM CUSTOMER AS C
JOIN INVOICE AS I
ON I.CUS_CODE = C.CUS_CODE
JOIN LINE AS L
ON L.INV_NUMBER = I.INV_NUMBER
GROUP BY CUS_CODE 
ORDER BY CUS_CODE;