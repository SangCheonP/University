select title, count(rolename)
from actors natural join actor_role natural join movies
where name = 'Tilda Swinton'
group by title;