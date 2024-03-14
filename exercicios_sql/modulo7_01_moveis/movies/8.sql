--Em 8.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
--Você pode presumir que há apenas um filme no banco de dados com o título Toy Story.

SELECT  people.name
FROM    people
JOIN    stars
        ON people.id = stars.person_id
JOIN    movies
        ON stars.movie_id = movies.id
WHERE   ( movies.title = 'Toy Story' );
