#include <stdio.h>
#include "TADPonto.h"
#include "TADCirculo.h"
int main()
{
    Ponto*pt1;
    pt1=pto_cria(2,3);
    tCirculo *circ1;
    tCirculo *circ2;
    circ1=circCria(10,2,4);

    printf("%s",pto_getPonto(pt1));
    circ_exibe(circ1);
    printf("oooooiiiii");
    return 0;
}
