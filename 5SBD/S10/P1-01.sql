-- Liste os nomes dos clientes cujas contas possuem saldo acima da média geral de todas as contas registradas.

SELECT
    c.cliente_nome,
    co.saldo
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
WHERE
    co.saldo > (SELECT AVG(saldo) FROM conta)
ORDER BY
    co.saldo DESC;