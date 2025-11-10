-- Liste todos os clientes cujo nome começa com 'M' e termina com 'a' (não sensível a maiúsculas/minúsculas).

SELECT *
FROM cliente
WHERE UPPER(cliente_nome) LIKE 'M%A';