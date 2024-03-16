--No 2.sql, escreva uma consulta SQL para listar os nomes de todas as músicas em ordem crescente de ritmo.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.

SELECT  name
FROM    songs
ORDER BY tempo;
