-- Liste os clientes cujos saldos estão entre os saldos de clientes de Volta Redonda.

WITH LimitesVoltaRedonda AS (
    SELECT
        MIN(co.saldo) AS SaldoMinimo,
        MAX(co.saldo) AS SaldoMaximo
    FROM
        cliente c
    JOIN
        conta co ON c.cliente_cod = co.cliente_cliente_cod
    WHERE
        c.cidade = 'Volta Redonda'
)
SELECT
    c.cliente_nome,
    c.cidade,
    co.saldo
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod,
    LimitesVoltaRedonda lvr
WHERE
    co.saldo BETWEEN lvr.SaldoMinimo AND lvr.SaldoMaximo
ORDER BY
    co.saldo;