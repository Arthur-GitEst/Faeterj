#include <stdio.h>
int funcao (int a, int b) {
    if (a > 0) {
    if (a > b) {
    return funcao (a-1, b+2) + funcao (b-a, b);
} else {
    return funcao (a-2, b);
}
} else {
    return b;
}
}
void main () {
    printf ("Resposta = %d", funcao (10, 5));
}

//10,5
//9,7 + -5,5
//(8,9 + -2, 7) + -5,5
//(6,9 + -2,7) + -5,5
//(4,9 + -2,7) + -5,5
//(2,9 + -2,7) + -5,5
//(0,9 + -2,7) + -5,5
//(9 + 7) + 5 = 21