-- ## Problem 15
-- 
-- Write a query to create a listing of customers who did not make purchases during the 
-- invoicing period. Sort the results by customer code. 
-- 
-- Your output must match the output shown here.
-- 
-- +----------+-------------+
-- | CUS_CODE | CUS_BALANCE |
-- +----------+-------------+
-- |  10010   |    0.00     |
-- |  10013   |   536.75    |
-- |  10016   |   221.19    |
-- |  10017   |   768.93    |
-- |  10019   |    0.00     |
-- +----------+-------------+
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT C.CUS_CODE,
	   C.CUS_BALANCE
FROM CUSTOMER AS C
LEFT JOIN INVOICE AS I
    ON I.CUS_CODE = C.CUS_CODE
WHERE I.INV_NUMBER IS NULL
GROUP BY C.CUS_CODE;