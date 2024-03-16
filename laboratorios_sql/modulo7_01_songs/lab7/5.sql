--No 5.sql, escreva uma consulta SQL que retorne a energia média de todas as músicas.
--Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.

SELECT  AVG(energy)
FROM    songs;
