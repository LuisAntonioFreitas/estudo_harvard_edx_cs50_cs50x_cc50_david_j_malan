--Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
--Pode haver várias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas Kevin Bacon nascido em 1958.
--O próprio Kevin Bacon não deve ser incluído na lista resultante.

SELECT  people.name
FROM    movies
JOIN    stars
        ON  movies.id = stars.movie_id
JOIN    people
        ON  stars.person_id = people.id
WHERE   ( people.name IN ('Kevin Bacon') )
GROUP BY movies.id
HAVING  COUNT(DISTINCT people.name) = 2;
