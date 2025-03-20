package POB.exercicioHeranca.empresa.dominio;

public abstract class Funcionario {
    private String matricula;
    private String cpf;
    private String nome;
    private float salario;
    
    Funcionario(String nome, String matricula, String cpf, float salario) {
        this.nome = nome;
        this.matricula = matricula;
        this.cpf = cpf;
        this.salario = salario;
    }

    public void mostrarInfo() {
        System.out.println("Nome: " + nome);
        System.out.println("Matrícula: " + matricula);
        System.out.println("CPF: " + cpf);
        System.out.println("Salário: R$ " + salario);
    }
}
