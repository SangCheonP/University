CREATE TABLE actors (
  AID 	VARCHAR(5), 
  name 	VARCHAR(20),
  PRIMARY KEY (AID)
  );

CREATE TABLE movies (
  MID	VARCHAR(5),
  title	VARCHAR(40),
  PRIMARY KEY (MID)
  );

CREATE TABLE actor_role(
  MID		VARCHAR(5),
  AID		VARCHAR(5),
  rolename	VARCHAR(20),
  PRIMARY KEY (MID, AID, rolename),
  FOREIGN KEY (MID) REFERENCES movies ON DELETE SET null,
  FOREIGN KEY (AID) REFERENCES actors ON DELETE SET null  
  );

INSERT INTO actors VALUES ('00001', 'Adam Driver');
INSERT INTO actors VALUES ('00002', 'Kristen Stewart');
INSERT INTO actors VALUES ('00003', 'Lady Gaga');
INSERT INTO actors VALUES ('00004', 'Matt Damon');
INSERT INTO actors VALUES ('00005', 'Robert Pattinson');
INSERT INTO actors VALUES ('00006', 'Scarlett Johansson');
INSERT INTO actors VALUES ('00007', 'Tilda Swinton');
INSERT INTO actors VALUES ('00008', 'Tobey Maguire');

INSERT INTO movies VALUES ('00001', 'Black Widow');
INSERT INTO movies VALUES ('00002', 'Coco');
INSERT INTO movies VALUES ('00003', 'House of Gucci');
INSERT INTO movies VALUES ('00004', 'Marriage Story');
INSERT INTO movies VALUES ('00005', 'Spencer');
INSERT INTO movies VALUES ('00006', 'The Batman');
INSERT INTO movies VALUES ('00007', 'Suspiria');
INSERT INTO movies VALUES ('00008', 'Avengers: Endgame');
INSERT INTO movies VALUES ('00009', 'Okja');

INSERT INTO actor_role VALUES ('00003', '00001', 'Maurizio Gucci');
INSERT INTO actor_role VALUES ('00005', '00002', 'Diana');
INSERT INTO actor_role VALUES ('00003', '00003', 'Patrizia Reggiani');
INSERT INTO actor_role VALUES ('00006', '00005', 'Bruce Wayne');
INSERT INTO actor_role VALUES ('00001', '00006', 'Natasha Romanoff');
INSERT INTO actor_role VALUES ('00004', '00006', 'Nicole Barber');
INSERT INTO actor_role VALUES ('00007', '00007', 'Madame Blanc');
INSERT INTO actor_role VALUES ('00007', '00007', 'Mother Helena Markos');
INSERT INTO actor_role VALUES ('00007', '00007', 'Dr. Josef Klemperer');
INSERT INTO actor_role VALUES ('00008', '00007', 'The Acient One');
INSERT INTO actor_role VALUES ('00009', '00007', 'Lucy Mirando');
INSERT INTO actor_role VALUES ('00009', '00007', 'Nancy Mirando');
