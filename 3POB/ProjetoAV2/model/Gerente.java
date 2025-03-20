package POB.ProjetoAV2.model;

import POB.ProjetoAV2.controller.Gerencia;

public class Gerente extends Funcionario implements Gerencia {
    public Gerente(String nome, double salario) {
        super(nome, salario);
    }

    @Override
    public String getTipo() {
        return "G";
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Gerente: " + getNome() + ", Salário: " + getSalario());
    }

    @Override
    public void organizarEquipe() {
        System.out.println(getNome() + " foi colocado para organizar a equipe.");
    }

    @Override
    public void conduzirReunioes() {
        System.out.println(getNome() + " foi colocado para conduzir as reuniões.");
    }
}
