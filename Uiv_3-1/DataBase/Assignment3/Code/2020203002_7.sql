select (select name from people_main where ID = ID1)as name1, ID1, ID2, (select name from people_main where ID = ID2)as name2
from people_likes
where (ID1, ID2) not in (select ID1, ID2
						 from people_friends);