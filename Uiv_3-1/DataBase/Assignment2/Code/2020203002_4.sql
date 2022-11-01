insert into student(ID, name, dept_name, tot_cred)
	select ID, name, dept_name, 0
	from instructor
	where ID <= '60000';