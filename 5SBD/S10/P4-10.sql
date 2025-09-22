-- Liste os nomes dos clientes que ainda não possuem conta registrada no banco.

SELECT
    c.cliente_nome
FROM
    cliente c
WHERE
    NOT EXISTS (
        SELECT 1
        FROM conta co
        WHERE co.cliente_cliente_cod = c.cliente_cod
    )
ORDER BY
    c.cliente_nome;