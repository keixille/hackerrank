SELECT
    MAX(months*salary), COUNT(months*salary)
FROM
    employee
WHERE
    salary*months = 
	(
        SELECT
            MAX(salary*months)
        FROM
            employee
    )