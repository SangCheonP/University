select distinct ID, name, course.dept_name
from instructor natural join teaches as t, course
where t.course_id = course.course_id and course.course_id like 'CS-1%';