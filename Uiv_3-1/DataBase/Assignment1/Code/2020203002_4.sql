select sum(credits)
from takes natural join student, course
where id = 45678 and takes.course_id = course.course_id;