--Em 10.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
--Se uma pessoa dirigiu mais de um filme que recebeu uma classificação de pelo menos 9,0, eles só devem aparecer em seus resultados uma vez.

SELECT DISTINCT
        people.name
FROM    people
JOIN    directors
        ON people.id = directors.person_id
JOIN    movies
        ON directors.movie_id = movies.id
JOIN    ratings
        ON  movies.id = ratings.movie_id
WHERE   ( ratings.rating >= 9 );
