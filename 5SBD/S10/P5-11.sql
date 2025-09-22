-- Usando a cláusula WITH, calcule a média de saldo por cidade e exiba os clientes que possuem saldo acima da média de sua cidade.

WITH MediaPorCidade AS (
    SELECT
        c.cidade,
        AVG(co.saldo) AS media_saldo
    FROM
        cliente c
    JOIN
        conta co ON c.cliente_cod = co.cliente_cliente_cod
    GROUP BY
        c.cidade
)
SELECT
    c.cliente_nome,
    c.cidade,
    co.saldo,
    ROUND(mpc.media_saldo, 2) AS "Média da Cidade"
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
JOIN
    MediaPorCidade mpc ON c.cidade = mpc.cidade
WHERE
    co.saldo > mpc.media_saldo
ORDER BY
    c.cidade, c.cliente_nome;