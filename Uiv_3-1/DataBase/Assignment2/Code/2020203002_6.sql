update student
set tot_cred = (select case
						when sum(credits) is not null then sum(credits)
						else 0
						end
				from takes, course
				where takes.course_id = course.course_id and
						student.ID = takes.ID and
						takes.grade <> 'F' and
						takes.grade is not null);