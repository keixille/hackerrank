/* First Query */
SELECT
    CONCAT(name, '(', LEFT(occupation, 1), ')')
FROM
    occupations
ORDER BY
    name ASC;

/* Second Query */
SELECT
    'There are a total of ', SUM(1) AS occurance, LOWER(CONCAT(occupation, 's.'))
FROM
    occupations
GROUP BY
    occupation
ORDER BY
    occurance ASC,
	occupation ASC