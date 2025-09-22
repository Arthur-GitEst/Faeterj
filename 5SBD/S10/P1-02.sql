-- Exiba os nomes dos clientes cujos saldos são iguais ao maior saldo encontrado no banco.

SELECT
    c.cliente_nome,
    co.saldo
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
WHERE
    co.saldo = (SELECT MAX(saldo) FROM conta);