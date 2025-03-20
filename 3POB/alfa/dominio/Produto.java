package POB.alfa.dominio;

public class Produto {
    private int id;
    private String nome;
    private double valor;

    Produto(int id, String nome, double valor) {
        this.id = id;
        this.nome = nome;
        this.valor = valor;
    }

    public void listarProduto() {
        System.out.println("ID: " + this.id);
        System.out.println("Nome: " + this.nome);
        System.out.println("Valor: " + this.valor);
    }
}
