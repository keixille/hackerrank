/* Root table */
(
    SELECT
        n, 'Root'
    FROM
        bst
    WHERE
        p IS NULL
)
UNION
/* Inner table */
(
    SELECT
        n, 'Inner'
    FROM
        bst
    WHERE
        n IN 
        (
            SELECT
                DISTINCT p
            FROM
                bst
            WHERE
                p IS NOT NULL
        ) AND
        p IS NOT NULL
)
UNION
/* Leaf table */
(
    SELECT
        n, 'Leaf'
    FROM
        bst
    WHERE
        n NOT IN 
        (
            SELECT
                DISTINCT p
            FROM
                bst
            WHERE
                p IS NOT NULL
        ) AND
        p IS NOT NULL
)
ORDER BY
    n ASC