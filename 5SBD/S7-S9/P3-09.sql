-- Exiba a média de saldo por cidade dos clientes.

SELECT
    c.cidade,
    ROUND(AVG(co.saldo), 2) AS "Média de Saldo por Cidade"
FROM
    cliente c
JOIN
    conta co ON c.cliente_cod = co.cliente_cliente_cod
GROUP BY
    c.cidade
ORDER BY
    c.cidade;