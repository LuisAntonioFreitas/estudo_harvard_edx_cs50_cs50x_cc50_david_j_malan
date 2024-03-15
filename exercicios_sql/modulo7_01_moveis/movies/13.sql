--Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
--Pode haver várias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas Kevin Bacon nascido em 1958.
--O próprio Kevin Bacon não deve ser incluído na lista resultante.

SELECT 
        p2.name
FROM    stars
JOIN    people p1
        ON  stars.person_id = p1.id
        AND p1.name IN ('Kevin Bacon')
JOIN    people p2
        ON  stars.person_id = p2.id
        AND NOT p2.name IN ('Kevin Bacon');
