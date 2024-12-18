# Write your MySQL query statement below
SELECT 
    st.student_id
    ,st.student_name
    ,sb.subject_name
    ,COUNT(e.student_id) attended_exams
FROM Students st

-- To list all subjects for each student, use cartesian product 
-- to generate every possible pair of rows from two tables
CROSS JOIN Subjects sb
LEFT JOIN Examinations e ON e.student_id = st.student_id
                         AND e.subject_name = sb.subject_name
GROUP BY st.student_id, st.student_name, sb.subject_name
ORDER BY st.student_id, st.student_name, sb.subject_name
;