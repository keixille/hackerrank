SELECT
    DISTINCT city
FROM
    station
WHERE
    RIGHT(city, 1) IN ('a', 'i', 'u', 'e', 'o')