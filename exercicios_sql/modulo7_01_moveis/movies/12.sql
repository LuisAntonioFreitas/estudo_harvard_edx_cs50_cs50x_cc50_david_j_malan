--Em 12.sql, escreva uma consulta SQL para listar os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos.
--Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
--Você pode presumir que há apenas uma pessoa no banco de dados com o nome Johnny Depp.
--Você pode presumir que há apenas uma pessoa no banco de dados com o nome Helena Bonham Carter.

SELECT  title, people.name
FROM    movies
JOIN    stars
        ON  movies.id = stars.movie_id
JOIN    people
        ON  stars.person_id = people.id
WHERE   ( people.name IN ('Johnny Depp', 'Helena Bonham Carter') )
HAVING  COUNT(DISTINCT people.name) = 2;
