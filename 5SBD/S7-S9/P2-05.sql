-- Mostre o maior saldo e a média de saldo entre todas as contas.

SELECT
    MAX(saldo) AS "Maior Saldo",
    ROUND(AVG(saldo), 2) AS "Média de Saldo"
FROM
    conta;