-- ## Problem 5
-- 
-- During the guest user analysis, developers realized there could be duplicate users in the 
-- system. Check for the guests with the same name but different GuestIDs to check whether 
-- they are duplicate or not.
-- 
-- +---------+----------------+---------------+-------------------+--------------+
-- | GuestID | GuestFirstName | GuestLastName |    GuestEmail     | DUP Guest ID |
-- +---------+----------------+---------------+-------------------+--------------+
-- |   12    |     Ronald     |     Oneil     | r.oneil@tmail.com |      7       |
-- |   11    |      Jada      |     Swan      | j.swan@tmail.com  |      9       |
-- |    9    |      Jada      |     Swan      | j.swan@xmail.com  |      11      |
-- |    7    |     Ronald     |     Oneil     | r.oneil@xmail.com |      12      |
-- +---------+----------------+---------------+-------------------+--------------+

/* YOUR SOLUTION HERE */
USE InstantStay;

SELECT 
	g1.GuestID,
	g1.GuestFirstName,
	g1.GuestLastName,
	g1.GuestEmail,
	g2.GuestID AS 'DUP Guest ID'
FROM 
	GUEST g1
JOIN
	GUEST g2
	ON g1.GuestFirstName = g2.GuestFirstName
	AND g1.GuestLastName = g2. GuestLastName
	and g1.GuestID <> g2.GuestID
ORDER BY 
	g2.GuestID;