--No 6.sql, escreva uma consulta SQL que lista os nomes das músicas de Post Malone.
--Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada música.
--Você não deve fazer suposições sobre qual é o artist_id de Post Malone.

SELECT  songs.name
FROM    songs
JOIN    artists
        ON songs.artist_id = artists.id
WHERE   ( artists.name = 'Post Malone' );
