--Em 9.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
--Pessoas com o mesmo ano de nascimento podem ser listadas em qualquer ordem.
--Não precisa se preocupar com pessoas que não têm ano de nascimento listado, desde que aqueles que têm ano de nascimento estejam listados em ordem.
--Se uma pessoa apareceu em mais de um filme em 2004, ela só deve aparecer uma vez nos resultados.

SELECT DISTINCT
        people.name
FROM    people
JOIN    stars
        ON people.id = stars.person_id
JOIN    movies
        ON stars.movie_id = movies.id
WHERE   ( movies.year = 2004 )
ORDER BY people.birth;
