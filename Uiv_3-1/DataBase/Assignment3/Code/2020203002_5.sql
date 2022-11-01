select name, occupation
from people_friends, people_main
where ID2 = ID
group by ID
having count(ID1) >= 3;