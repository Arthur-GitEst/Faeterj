-- Faça uma consulta com UNION que combine os nomes de cidades dos clientes e das agências, sem repetições.

SELECT
    cidade AS "Nome da Cidade"
FROM
    cliente
UNION
SELECT
    agencia_cidade
FROM
    agencia
ORDER BY
    "Nome da Cidade";