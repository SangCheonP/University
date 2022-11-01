select distinct name, title
from actors natural left join actor_role natural left join movies;