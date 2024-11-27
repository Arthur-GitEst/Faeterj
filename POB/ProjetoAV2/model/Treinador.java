package POB.ProjetoAV2.model;

import POB.ProjetoAV2.controller.Treina;

public class Treinador extends Funcionario implements Treina {
    public Treinador(String nome, double salario) {
        super(nome, salario);
    }

    @Override
    public String getTipo() {
        return "T";
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Treinador: " + getNome() + ", Salário: " + getSalario());
    }

    @Override
    public void ensinarTecnologia() {
        System.out.println(getNome() + " foi colocado para ensinar tecnologia.");
    }

    @Override
    public void motivarEquipe() {
        System.out.println(getNome() + " foi colocado para motivar a equipe.");
    }
}
