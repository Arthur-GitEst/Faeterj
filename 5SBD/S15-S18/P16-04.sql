-- Crie uma view chamada vw_contas_clientes que exiba o nome do cliente, o número da conta, saldo e código da agência.

CREATE VIEW vw_contas_clientes AS
SELECT
    c.cliente_nome,
    ct.conta_numero,
    ct.saldo,
    ct.agencia_agencia_cod
FROM
    cliente c
JOIN
    conta ct ON c.cliente_cod = ct.cliente_cliente_cod;