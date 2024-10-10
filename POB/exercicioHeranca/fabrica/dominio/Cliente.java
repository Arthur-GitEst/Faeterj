package POB.exercicioHeranca.fabrica.dominio;

public abstract class Cliente {
    private String endereco;
    private String telefone;

    public Cliente(String endereco, String telefone) {
        this.endereco = endereco;
        this.telefone = telefone;
    }

    public void mostrarInfo() {
        System.out.println("Endereco: " + endereco);
        System.out.println("Telefone: " + telefone);
    }
}
