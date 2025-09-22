-- Liste o número de cidades distintas onde os clientes residem.

SELECT
    COUNT(DISTINCT cidade) AS "Número de Cidades Distintas"
FROM
    cliente;