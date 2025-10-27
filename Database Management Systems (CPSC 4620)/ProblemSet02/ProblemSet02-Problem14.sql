-- ## Problem 14
-- 
-- Create a query to find the balance characteristics for all customers, 
-- including the total of the outstanding balances. 
-- 
-- The results of this query are shown in below.
-- 
-- +---------------+-----------------+-----------------+-----------------+
-- | Total Balance | Minimum Balance | Maximum Balance | Average Balance |
-- +---------------+-----------------+-----------------+-----------------+
-- |    2089.28    |      0.00       |     768.93      |     208.93      |
-- +---------------+-----------------+-----------------+-----------------+
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT ROUND(SUM(CUS_BALANCE), 2) AS 'Total Balance',
	   MIN(CUS_BALANCE) AS 'Minimum Balance',
       MAX(CUS_BALANCE) AS 'Maximum Balance',
       ROUND(AVG(CUS_BALANCE), 2) AS 'Average Balance'
FROM CUSTOMER