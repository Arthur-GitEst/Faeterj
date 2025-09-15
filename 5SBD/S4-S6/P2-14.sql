-- Exiba os nomes dos clientes e substitua valores nulos na cidade por 'Sem cidade'.

SELECT cliente_nome, NVL(cidade, 'Sem cidade') FROM cliente