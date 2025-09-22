-- Usando a sintaxe proprietária da Oracle, exiba o nome de cada cliente junto com o número de sua conta.

SELECT
    cliente_nome,
    conta_numero
FROM
    cliente,
    conta
WHERE
    cliente_cod = cliente_cliente_cod;