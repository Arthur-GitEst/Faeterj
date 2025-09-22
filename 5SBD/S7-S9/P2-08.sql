-- Exiba o número da conta e o saldo, substituindo valores nulos por zero.

SELECT
    conta_numero,
    NVL(saldo, 0) AS "Saldo"
FROM
    conta;