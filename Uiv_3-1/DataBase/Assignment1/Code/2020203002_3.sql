select distinct takes.course_id, title
from takes natural join student, course
where ID = 45678 and takes.course_id = course.course_id;