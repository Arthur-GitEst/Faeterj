-- Liste os nomes dos clientes e os nomes das agências onde mantêm conta.

SELECT
    cliente_nome,
    agencia_nome
FROM
    cliente
INNER JOIN
    conta ON cliente_cod = cliente_cliente_cod
INNER JOIN
    agencia ON agencia_agencia_cod = agencia_cod
ORDER BY
    cliente_nome;