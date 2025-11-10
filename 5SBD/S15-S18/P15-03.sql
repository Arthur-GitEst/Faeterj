-- Insira pelo menos três movimentações diferentes utilizando a sequência seq_movimento.

INSERT ALL
    INTO movimento_conta (movimento_id, conta_numero, tipo, valor, data_movimento) VALUES (seq_movimento.NEXTVAL, 1, 'D', 150.00, SYSDATE)
    INTO movimento_conta (movimento_id, conta_numero, tipo, valor, data_movimento) VALUES (seq_movimento.NEXTVAL, 2, 'C', 500.00, SYSDATE)
    INTO movimento_conta (movimento_id, conta_numero, tipo, valor, data_movimento) VALUES (seq_movimento.NEXTVAL, 1, 'C', 1000.50, SYSDATE)
SELECT * FROM dual;