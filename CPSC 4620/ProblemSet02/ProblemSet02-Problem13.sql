-- ## Problem 13
-- 
-- Provide a summary of customer balance characteristics for customers who made purchases. 
-- Include the minimum balance, maximum balance, and average balance, as shown below.
-- 
-- +-----------------+-----------------+-----------------+
-- | Minimum Balance | Maximum Balance | Average Balance |
-- +-----------------+-----------------+-----------------+
-- |      0.00       |     345.86      |     112.48      |
-- +-----------------+-----------------+-----------------+
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT MIN(T.CUS_BALANCE) AS 'Minimum Balance',
       MAX(T.CUS_BALANCE) AS 'Maximum Balance',
       ROUND(AVG(T.CUS_BALANCE), 2) AS 'Average Balance'
FROM (
    SELECT DISTINCT
        C.CUS_CODE,
        C.CUS_BALANCE
    FROM CUSTOMER AS C
    INNER JOIN INVOICE AS I
    ON C.CUS_CODE = I.CUS_CODE
) AS T;