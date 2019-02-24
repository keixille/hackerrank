SELECT
    C.company_code, C.founder, tempLM.n_lead, tempSM.n_senior, tempM.n_manager, tempE.n_employee
FROM
    company AS C
/* Counting lead manager */
JOIN
    (
        SELECT
            company_code, COUNT(DISTINCT lead_manager_code) AS n_lead
        FROM
            lead_manager
        GROUP BY
            company_code
    ) AS tempLM
ON
    C.company_code = tempLM.company_code
/* Counting senior manager */
JOIN
    (
        SELECT
            company_code, COUNT(DISTINCT senior_manager_code) AS n_senior
        FROM
            senior_manager
        GROUP BY
            company_code
    ) AS tempSM
ON
    C.company_code = tempSM.company_code
/* Counting manager */
JOIN
    (
        SELECT
            company_code, COUNT(DISTINCT manager_code) AS n_manager
        FROM
            manager
        GROUP BY
            company_code
    ) AS tempM
ON
    C.company_code = tempM.company_code
/* Counting employee */
JOIN
    (
        SELECT
            company_code, COUNT(DISTINCT employee_code) AS n_employee
        FROM
            employee
        GROUP BY
            company_code
    ) AS tempE
ON
    C.company_code = tempE.company_code
ORDER BY
    C.company_code ASC