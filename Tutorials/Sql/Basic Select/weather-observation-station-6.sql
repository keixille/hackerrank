SELECT
    DISTINCT city
FROM
    station
WHERE
    LEFT(city, 1) IN ('a', 'i', 'u', 'e', 'o')