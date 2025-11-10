-- Crie uma tabela chamada movimento_conta com as colunas: movimento_id, conta_numero, tipo (C ou D), valor, data_movimento.

CREATE TABLE movimento_conta (
    movimento_id    INTEGER NOT NULL,
    conta_numero    INTEGER NOT NULL,
    tipo            CHAR(1 CHAR) NOT NULL,
    valor           NUMBER(7, 2) NOT NULL,
    data_movimento  DATE NOT NULL
);

ALTER TABLE movimento_conta ADD CONSTRAINT movimento_pk PRIMARY KEY ( movimento_id );

ALTER TABLE movimento_conta
    ADD CONSTRAINT movimento_conta_fk FOREIGN KEY ( conta_numero )
        REFERENCES conta ( conta_numero );

ALTER TABLE movimento_conta ADD CONSTRAINT movimento_tipo_chk CHECK ( tipo IN ('C', 'D') );