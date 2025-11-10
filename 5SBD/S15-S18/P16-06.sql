-- Tente fazer um update diretamente na view vw_emprestimos_grandes e observe o que acontece. Explique o motivo.

UPDATE vw_emprestimos_grandes
SET quantia = 25000
WHERE emprestimo_numero = 9; 

-- Ela retorna um erro, pois a coluna vw_emprestimos_grandes foi criada a partir de uma operação JOIN, tendo restrições específicas que impedem que seus valores ejam modificados.