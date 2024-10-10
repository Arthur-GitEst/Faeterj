package POB.exercicioHeranca.empresa.dominio;

public class Vendas extends Gerente {
    private float participacaoLucros;

    public Vendas(String nome, String matricula, String cpf, float salario, float gratificacao, float participacaoLucros) {
        super(nome, matricula, cpf, salario, gratificacao);
        this.participacaoLucros = participacaoLucros;
    }

    public void mostrarInfo() {
        super.mostrarInfo();
        System.out.println("Participação de Lucros: " + participacaoLucros + "%");
    }
}
