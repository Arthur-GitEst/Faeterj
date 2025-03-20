package POB.exercicioHeranca.fabrica.dominio;

public class PessoaFisica extends Cliente {
    private String cpf;
    private String nome;

    public PessoaFisica (String nome, String cpf, String endereco, String telefone) {
        super(endereco, telefone);
        this.cpf = cpf;
        this.nome = nome;
    }

    public void mostrarInfo() {
        System.out.println("Nome: " + nome);
        System.out.println("CPF: " + cpf);
        super.mostrarInfo();
    }
}
