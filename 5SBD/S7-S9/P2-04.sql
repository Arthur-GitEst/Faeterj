-- Exiba o saldo total de todas as contas cadastradas.

SELECT
    SUM(saldo) AS "Saldo Total"
FROM
    conta;