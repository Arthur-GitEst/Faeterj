package POB.ProjetoAV2.model;

import POB.ProjetoAV2.controller.Desenvolve;
import POB.ProjetoAV2.controller.Gerencia;

public class GerenteDesenvolvedor extends Funcionario implements Gerencia, Desenvolve {
    public GerenteDesenvolvedor(String nome, double salario) {
        super(nome, salario);
    }

    @Override
    public String getTipo() {
        return "GD";
    }

    @Override
    public void mostrarDetalhes() {
        System.out.println("Gerente Desenvolvedor: " + getNome() + ", Salário: " + getSalario());
    }

    @Override
    public void codar() {
        System.out.println(getNome() + " foi colocado para codar.");
    }
    
    @Override
    public void resolverProblemas() {
        System.out.println(getNome() + " foi colocado para resolver problemas.");
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
