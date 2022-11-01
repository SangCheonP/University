delete from student
where ID in (select ID
			from instructor);