SELECT
    DISTINCT city
FROM
    station
WHERE
    RIGHT(city, 1) NOT IN ('a', 'i', 'u', 'e', 'o') OR
    LEFT(city, 1) NOT IN ('a', 'i', 'u', 'e', 'o')