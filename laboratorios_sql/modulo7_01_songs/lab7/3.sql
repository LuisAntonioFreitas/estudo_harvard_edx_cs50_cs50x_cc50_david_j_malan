--No 3.sql, escreva uma consulta SQL para listar os nomes das 5 músicas mais longas, em ordem decrescente de duração.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.

SELECT  name
FROM    songs
ORDER BY duration_ms DESC
LIMIT 5;
