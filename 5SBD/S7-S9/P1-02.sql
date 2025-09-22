-- Mostre todas as combinações possíveis de clientes e agências (produto cartesiano).

SELECT
    cliente_nome,
    agencia_nome
FROM
    cliente
CROSS JOIN
    agencia;