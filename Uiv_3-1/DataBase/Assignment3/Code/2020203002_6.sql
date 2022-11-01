select distinct p2.name, p2.birth_year
from people_likes, people_main as p1, people_main as p2
where p1.ID = ID1 and p2.ID = ID2 and p2.birth_year < p1.birth_year
order by p2.name;