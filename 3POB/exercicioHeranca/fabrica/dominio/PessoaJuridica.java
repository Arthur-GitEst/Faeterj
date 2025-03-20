package POB.exercicioHeranca.fabrica.dominio;

public class PessoaJuridica extends Cliente {
    private String cnpj;
    private String razaoSocial;

    public PessoaJuridica (String cnpj, String razaoSocial, String endereco, String telefone) {
        super(endereco, telefone);
        this.cnpj = cnpj;
        this.razaoSocial = razaoSocial;
    }

    public void mostrarInfo() {
        System.out.println("CNPJ: " + cnpj);
        System.out.println("Razão Social: " + razaoSocial);
        super.mostrarInfo();
    }
}