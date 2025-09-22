-- Liste os nomes dos clientes que possuem pelo menos uma conta registrada no banco.

SELECT
    c.cliente_nome
FROM
    cliente c
WHERE
    EXISTS (
        SELECT 1
        FROM conta co
        WHERE co.cliente_cliente_cod = c.cliente_cod
    )
ORDER BY
    c.cliente_nome;