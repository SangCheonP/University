select id, sum(credits)
from takes natural join student, course
where takes.course_id = course.course_id
group by id;