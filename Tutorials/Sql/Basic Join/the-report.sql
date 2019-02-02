/* Grade 8 and above */
SELECT
    students.name, grades.grade, students.marks
FROM
    students
INNER JOIN
    grades
ON
    students.marks >= grades.min_mark AND
    students.marks <= grades.max_mark
WHERE
    grades.grade >= 8
ORDER BY
    grades.grade DESC, students.name ASC;

/* Grade below 8 */
SELECT
    NULL, grades.grade, students.marks
FROM
    students
INNER JOIN
    grades
ON
    students.marks >= grades.min_mark AND
    students.marks <= grades.max_mark
WHERE
    grades.grade < 8
ORDER BY
    grades.grade DESC, students.marks ASC;