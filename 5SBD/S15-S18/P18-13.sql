-- Exibir o domínio dos e-mails dos clientes (parte após o @).

SELECT SUBSTR(cliente_email, INSTR(cliente_email, '@') + 1) AS dominio_email
FROM cliente
WHERE cliente_email LIKE '%@%';