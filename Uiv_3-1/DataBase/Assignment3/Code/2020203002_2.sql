select name
from actors
where AID not in (select AID
				  from actor_role);