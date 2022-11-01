update instructor
set salary = (select case
			  	when instructor.Id = teaches.ID then count(teaches.ID)*50000
			  	else 30000
			  end
			  from teaches
			  where instructor.Id = teaches.ID or instructor.ID not in(select ID from teaches));