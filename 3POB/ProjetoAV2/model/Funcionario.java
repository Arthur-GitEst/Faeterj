package POB.ProjetoAV2.model;

public abstract class Funcionario {
    private String nome;
    double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void receberAumento(double aumento) {
        this.salario += aumento;
    }

    public void mostrarDetalhes() {
        System.out.println("Funcionário: " + this.nome + ", Salário: " + this.salario);
    }

    public abstract String getTipo();
}