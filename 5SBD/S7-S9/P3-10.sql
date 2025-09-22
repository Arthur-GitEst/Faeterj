-- Liste apenas as cidades com mais de 3 contas associadas a seus moradores.

SELECT
    c.cidade,
    COUNT(co.conta_numero) AS "Quantidade de Contas"
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
GROUP BY
    c.cidade
HAVING
    COUNT(co.conta_numero) > 3
ORDER BY
    "Quantidade de Contas" DESC;