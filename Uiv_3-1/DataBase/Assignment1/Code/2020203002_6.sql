select distinct name
from course, takes natural join student
where dept_name = 'Comp. Sci.' and course.course_id = takes.course_id;