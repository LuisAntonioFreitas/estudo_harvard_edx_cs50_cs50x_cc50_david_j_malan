--Em 3.sql, escreva uma consulta SQL para listar os títulos de todos os filmes com data de lançamento igual ou posterior a 2018, em ordem alfabética.
--Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
--Os filmes lançados em 2018 devem ser incluídos, assim como os filmes com datas de lançamento no futuro.

SELECT title FROM movies WHERE year >= 2018 ORDER BY title;
