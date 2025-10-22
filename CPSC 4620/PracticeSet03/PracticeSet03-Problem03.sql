-- ## Problem 3:
-- 
-- The InstantStay Marketing team wants to learn the apartment that have more than average number 
-- of stays.
-- 
-- +---------+-------+
-- | HouseID | Stays |
-- +---------+-------+
-- |    1    |   4   |
-- |    4    |   4   |
-- +---------+-------+

/* YOUR SOLUTION HERE */
USE InstantStay;

SELECT HouseID, COUNT(HouseID) AS 'Stays'
FROM STAY
GROUP BY HouseID
HAVING COUNT(HouseID) > (
	SELECT AVG(AvgNumStays)
	FROM (
		SELECT COUNT(HouseID) AS AvgNumStays
		FROM STAY
		GROUP BY HouseID
	) AS T
);
