-- Liste os clientes que possuem saldo menor que todos os saldos dos clientes da cidade de Niterói.

SELECT
    c.cliente_nome,
    c.cidade,
    co.saldo
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
WHERE
    co.saldo < (
        SELECT MIN(co2.saldo)
        FROM cliente c2
        JOIN conta co2 ON c2.cliente_cod = co2.cliente_cliente_cod
        WHERE c2.cidade = 'Niterói'
    )
ORDER BY
    co.saldo;