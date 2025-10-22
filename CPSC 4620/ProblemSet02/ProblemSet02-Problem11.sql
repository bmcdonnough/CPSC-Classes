-- ## Problem 11
-- 
-- Write a query to generate the total number of invoices, the invoice total for all of the 
-- invoices, the smallest of the customer purchase amounts, the largest of the customer purchase
-- amounts, and the average of all the customer purchase amounts. 
-- 
-- Your output must match the results show below.
-- 
-- +----------------+-------------+----------------------------+----------------------------+----------------------------+
-- | Total Invoices | Total Sales | Minimum Customer Purchases | Largest Customer Purchases | Average Customer Purchases |
-- +----------------+-------------+----------------------------+----------------------------+----------------------------+
-- |       8        |   1126.03   |           34.97            |           444.00           |           225.21           |
-- +----------------+-------------+----------------------------+----------------------------+----------------------------+
-- 
-- 
/* YOUR SOLUTION HERE */
USE SaleCo;

SELECT (SELECT COUNT(DISTINCT INV_NUMBER) FROM INVOICE) AS 'Total Invoices',

       (SELECT ROUND(SUM(LINE_UNITS * LINE_PRICE), 2) FROM LINE) AS 'Total Sales',
       
       ROUND(MIN(T.CustomerPurchaseTotal), 2) AS 'Minimum Customer Purchases',
       ROUND(MAX(T.CustomerPurchaseTotal), 2) AS 'Largest Customer Purchases',
       ROUND(AVG(T.CustomerPurchaseTotal), 2) AS 'Average Customer Purchases'

FROM 
    (
        SELECT SUM(L.LINE_UNITS * L.LINE_PRICE) AS CustomerPurchaseTotal
        FROM CUSTOMER AS C
        JOIN INVOICE AS I
            ON I.CUS_CODE = C.CUS_CODE
        JOIN LINE AS L
            ON L.INV_NUMBER = I.INV_NUMBER
        GROUP BY C.CUS_CODE
    ) AS T;