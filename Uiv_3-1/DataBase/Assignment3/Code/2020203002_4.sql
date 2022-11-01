select count(ID2), (select name
		   from people_main
		   where ID2 = ID) as name
from people_likes
where (ID1, ID2) in (select ID2, ID1 from people_likes)
group by ID2
order by count(ID2) DESC;