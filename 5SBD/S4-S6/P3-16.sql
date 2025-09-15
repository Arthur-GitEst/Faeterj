-- Exiba o nome de cada cliente, o número da conta e o saldo correspondente.

SELECT
    cliente_nome,
    conta_numero,
    saldo
FROM
    cliente
INNER JOIN
    conta ON cliente_cod = cliente_cliente_cod
ORDER BY
    cliente_nome;