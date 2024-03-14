--Em 2.sql, escreva uma consulta SQL para determinar o ano de nascimento de Emma Stone.
--Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o ano de nascimento de Emma Stone.
--Você pode presumir que há apenas uma pessoa no banco de dados com o nome Emma Stone.

SELECT brith FROM people WHERE name = 'Emma Stone';
