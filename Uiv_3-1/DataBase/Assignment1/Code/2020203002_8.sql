select instructor.ID, name
from instructor,(select id from instructor
except
select id from teaches) as S
where instructor.ID = S.ID;