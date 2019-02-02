SELECT
    SUM(city.population)
FROM
    country
INNER JOIN
    city
ON
    country.code = city.countrycode
WHERE
    country.continent = 'Asia'