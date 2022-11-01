select max(cc), min(cc)
from (select count(course_id) as cc,*
	  from takes
	  group by course_id, sec_id, semester, year);