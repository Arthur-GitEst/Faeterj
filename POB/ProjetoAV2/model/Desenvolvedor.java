package POB.ProjetoAV2.model;

import POB.ProjetoAV2.controller.Desenvolve;

public class Desenvolvedor extends Funcionario implements Desenvolve {
    public Desenvolvedor(String nome, double salario) {
        super(nome, salario);
    }

    @Override
    public String getTipo() {
        return "D";
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Desenvolvedor: " + getNome() + ", Salário: " + getSalario());
    }

    @Override
    public void codar() {
        System.out.println(getNome() + " foi colocado para codar.");
    }

    @Override
    public void resolverProblemas() {
        System.out.println(getNome() + " foi colocado para resolver problemas.");
    }
}
