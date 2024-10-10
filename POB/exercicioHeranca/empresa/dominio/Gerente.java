package POB.exercicioHeranca.empresa.dominio;

public class Gerente extends Funcionario {
    private float gratificacao;

    public Gerente(String nome, String matricula, String cpf, float salario, float gratificacao) {
        super(nome, matricula, cpf, salario);
        this.gratificacao = gratificacao;
    }

    public void mostrarInfo() {
        super.mostrarInfo();
        System.out.println("Gratificacao: R$ " + gratificacao);
    }
}
