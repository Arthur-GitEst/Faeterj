package POB.ProjetoAV2;

import POB.ProjetoAV2.controller.FuncionarioController;
import POB.ProjetoAV2.view.FuncionarioView;

public class Main {
    public static void main(String[] args) {
        FuncionarioController controller = new FuncionarioController();
        FuncionarioView view = new FuncionarioView();

        view.menu();
    }
}
