-- Listar clientes com dois ou mais nomes.

SELECT *
FROM cliente
WHERE cliente_nome LIKE '% %';