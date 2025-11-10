-- Filtrar clientes cujo e-mail termina com '.br'.

SELECT *
FROM cliente
WHERE LOWER(cliente_email) LIKE '%.br';