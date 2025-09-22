-- Liste as cidades onde a quantidade de clientes é maior que a quantidade média de clientes por cidade.

WITH ContagemPorCidade AS (
    SELECT
        cidade,
        COUNT(cliente_cod) AS QtdClientes
    FROM
        cliente
    GROUP BY
        cidade
),
MediaGeral AS (
    SELECT
        AVG(QtdClientes) AS MediaClientes
    FROM
        ContagemPorCidade
)
SELECT
    cpc.cidade,
    cpc.QtdClientes
FROM
    ContagemPorCidade cpc,
    MediaGeral mg
WHERE
    cpc.QtdClientes > mg.MediaClientes
ORDER BY
    cpc.QtdClientes DESC;