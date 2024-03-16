--No 7.sql, escreva uma consulta SQL que retorne a energia média das músicas de Drake.
--Sua consulta deve gerar uma tabela com uma única coluna e uma única linha contendo a energia média.
--Você não deve fazer suposições sobre qual é o artist_id de Drake.

SELECT  AVG(songs.energy)
FROM    songs
JOIN    artists
        ON songs.artist_id = artists.id
WHERE   ( artists.name = 'Drake' );
