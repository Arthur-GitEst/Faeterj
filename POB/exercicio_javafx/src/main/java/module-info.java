module exercicio.javafx {
    requires javafx.controls;
    requires javafx.fxml;

    opens exercicio.javafx to javafx.fxml;
    exports exercicio.javafx;
}
