-- Liste os nomes dos clientes com saldo igual a qualquer um dos dez maiores saldos registrados.

WITH ContasComRanking AS (
    SELECT
        c.cliente_nome,
        co.saldo,
        DENSE_RANK() OVER (ORDER BY co.saldo DESC) AS ranking_saldo
    FROM
        cliente c
    JOIN
        conta co ON c.cliente_cod = co.cliente_cliente_cod
)
SELECT
    cliente_nome,
    saldo
FROM
    ContasComRanking
WHERE
    ranking_saldo <= 10
ORDER BY
    saldo DESC, cliente_nome;