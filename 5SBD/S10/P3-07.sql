-- Exiba os nomes dos clientes cujos saldos são maiores que a média de saldo das contas da mesma agência.

WITH ContasComMediaDaAgencia AS (
    SELECT
        cliente_cliente_cod,
        agencia_agencia_cod,
        saldo,
        AVG(saldo) OVER (PARTITION BY agencia_agencia_cod) AS media_saldo_agencia
    FROM
        conta
)
SELECT
    c.cliente_nome,
    cma.saldo,
    ROUND(cma.media_saldo_agencia, 2) AS "Média da Agência"
FROM
    cliente c
JOIN
    ContasComMediaDaAgencia cma ON c.cliente_cod = cma.cliente_cliente_cod
WHERE
    cma.saldo > cma.media_saldo_agencia
ORDER BY
    cma.agencia_agencia_cod, cma.saldo DESC;