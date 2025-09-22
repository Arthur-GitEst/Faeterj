-- Liste os nomes e cidades dos clientes que têm saldo inferior à média de sua própria cidade.

WITH ContasComMediaDaCidade AS (
    SELECT
        c.cliente_nome,
        c.cidade,
        co.saldo,
        AVG(co.saldo) OVER (PARTITION BY c.cidade) AS media_saldo_cidade
    FROM
        cliente c
    JOIN
        conta co ON c.cliente_cod = co.cliente_cliente_cod
)
SELECT
    cliente_nome,
    cidade,
    saldo,
    ROUND(media_saldo_cidade, 2) AS "Média da Cidade"
FROM
    ContasComMediaDaCidade
WHERE
    saldo < media_saldo_cidade
ORDER BY
    cidade, saldo;