--Em 11.sql, escreva uma consulta SQL para listar os títulos dos cinco filmes com melhor classificação (em ordem) que Chadwick Boseman estrelou,
--começando com os de maior classificação.
--Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
--Você pode presumir que há apenas uma pessoa no banco de dados com o nome Chadwick Boseman.

SELECT  title
FROM    movies
JOIN    stars
        ON movies.id = stars.movie_id
JOIN    people
        ON stars.person_id = people.id
JOIN    ratings
        ON  movies.id = ratings.movie_id
WHERE   ( people.name = 'Chadwick Boseman' )
ORDER BY ratings.rating DESC
LIMIT   5;
