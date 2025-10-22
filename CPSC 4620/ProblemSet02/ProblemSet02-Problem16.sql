-- ## Problem 16
-- 
-- Write a query to find the customer balance summary for all customers who have not made 
-- purchases during the current invoicing period. 
-- 
-- The results are shown here.
-- 
-- +---------------+-----------------+-----------------+-----------------+
-- | Total Balance | Minimum Balance | Maximum Balance | Average Balance |
-- +---------------+-----------------+-----------------+-----------------+
-- |    1526.87    |      0.00       |     768.93      |     305.37      |
-- +---------------+-----------------+-----------------+-----------------+
-- 
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT SUM(T.CUS_BALANCE) AS 'Total Balance',
	   MIN(T.CUS_BALANCE) AS 'Minimum Balance',
       MAX(T.CUS_BALANCE) AS 'Maximum Balance',
       ROUND(AVG(T.CUS_BALANCE), 2) AS 'Average Balance'
FROM (
    SELECT DISTINCT
        C.CUS_CODE,
        C.CUS_BALANCE
    FROM CUSTOMER AS C
    LEFT JOIN INVOICE AS I
    ON C.CUS_CODE = I.CUS_CODE
    WHERE I.INV_NUMBER IS NULL
) AS T;