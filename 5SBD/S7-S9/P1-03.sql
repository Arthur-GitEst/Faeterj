-- Usando aliases de tabela, exiba o nome dos clientes e a cidade da agência onde mantêm conta.

SELECT
    c.cliente_nome,
    a.agencia_cidade
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
JOIN
    agencia a ON co.agencia_agencia_cod = a.agencia_cod;