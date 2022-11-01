CREATE TABLE people_main(
		ID			INT,
		name		VARCHAR(20),
		occupation	VARCHAR(20),
		birth_year	INT
);

CREATE TABLE people_likes(
		ID1		INT,
		ID2		INT
);

CREATE TABLE people_friends(
		ID1		INT,
		ID2		INT
);

INSERT INTO people_main VALUES (1, 'Adam Driver', 'Actor', 1983);
INSERT INTO people_main VALUES (2, 'Betty Friedan', 'Writer', 1960);
INSERT INTO people_main VALUES (3, 'Charles Barkley', 'Basketball player', 1963);
INSERT INTO people_main VALUES (4, 'David Bowie', 'Singer', 1947);
INSERT INTO people_main VALUES (5, 'Elon Musk', 'Entrepreneur', 1971);
INSERT INTO people_main VALUES (6, 'Francesca Eastwood', 'Model', 1993);
INSERT INTO people_main VALUES (7, 'Gloria Vanderbilt', 'Artist', 1924);
INSERT INTO people_main VALUES (8, 'Hillary Clinton', 'Politician', 1947);

INSERT INTO people_likes VALUES (8, 5); 
INSERT INTO people_likes VALUES (4, 5); 
INSERT INTO people_likes VALUES (2, 7); 
INSERT INTO people_likes VALUES (5, 1); 
INSERT INTO people_likes VALUES (6, 7); 
INSERT INTO people_likes VALUES (3, 1); 
INSERT INTO people_likes VALUES (8, 1); 
INSERT INTO people_likes VALUES (8, 2); 
INSERT INTO people_likes VALUES (5, 2); 
INSERT INTO people_likes VALUES (1, 7); 
INSERT INTO people_likes VALUES (6, 3); 
INSERT INTO people_likes VALUES (6, 7);
INSERT INTO people_likes VALUES (1, 2);
INSERT INTO people_likes VALUES (7, 8); 
INSERT INTO people_likes VALUES (6, 3);
INSERT INTO people_likes VALUES (4, 8);
INSERT INTO people_likes VALUES (3, 5); 
INSERT INTO people_likes VALUES (4, 5); 
INSERT INTO people_likes VALUES (3, 6); 
INSERT INTO people_likes VALUES (2, 6); 
INSERT INTO people_likes VALUES (3, 1); 
INSERT INTO people_likes VALUES (1, 6); 
INSERT INTO people_likes VALUES (8, 5); 
INSERT INTO people_likes VALUES (7, 6); 
INSERT INTO people_likes VALUES (1, 8); 
INSERT INTO people_likes VALUES (6, 7); 
INSERT INTO people_likes VALUES (2, 3); 
INSERT INTO people_likes VALUES (1, 7); 
INSERT INTO people_likes VALUES (2, 1); 
INSERT INTO people_likes VALUES (5, 7); 
INSERT INTO people_likes VALUES (7, 8); 
INSERT INTO people_likes VALUES (8, 2); 

INSERT INTO people_friends VALUES (2, 6);
INSERT INTO people_friends VALUES (6, 2);
INSERT INTO people_friends VALUES (4, 8);
INSERT INTO people_friends VALUES (8, 4);
INSERT INTO people_friends VALUES (1, 3);
INSERT INTO people_friends VALUES (3, 1);
INSERT INTO people_friends VALUES (5, 8);
INSERT INTO people_friends VALUES (8, 5);
INSERT INTO people_friends VALUES (3, 8);
INSERT INTO people_friends VALUES (8, 3);
INSERT INTO people_friends VALUES (1, 6);
INSERT INTO people_friends VALUES (6, 1);
INSERT INTO people_friends VALUES (7, 8);
INSERT INTO people_friends VALUES (8, 7);
