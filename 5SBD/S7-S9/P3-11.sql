-- Utilize a cláusula ROLLUP para exibir o total de saldos por cidade da agência e o total geral.

SELECT
    NVL(a.agencia_cidade, 'Total Geral') AS "Cidade da Agência",
    SUM(co.saldo) AS "Soma dos Saldos"
FROM
    agencia a
JOIN
    conta co ON a.agencia_cod = co.agencia_agencia_cod
GROUP BY
    ROLLUP(a.agencia_cidade)
ORDER BY
    "Cidade da Agência";