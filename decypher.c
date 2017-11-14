#include <stdio.h>
#include <stdlib.h>

int main()
{
    int
        falhou,
        num_tentativas = 0,
        qtd_amin_acidos = 0,
        qtd_nucleotides = 0,
        cod_gen_decifrado = 0;

    char
        proteina[1000],
        sequencia_genetica[10000],
        registro_de_amin_acidos[1000][4];

	printf("Insira a proteina:\n");
	scanf("%1000s", proteina);
	qtd_amin_acidos = strlen(proteina);
	
	printf("Insira a sequencia genetica:\n");
	scanf("%10000s", sequencia_genetica);
	qtd_nucleotides = strlen(sequencia_genetica);

    while ((cod_gen_decifrado == 0) && (num_tentativas < (qtd_nucleotides - qtd_amin_acidos)))
    {
        falhou = 0;

		int
			j = 0,
			byte = num_tentativas;

	    for (int i = 0; i < qtd_amin_acidos; i++)
	    {
	        while (j != 3)
	        {
	            registro_de_amin_acidos[i][j] = sequencia_genetica[byte];
	
	            byte++;
	            j++;
	        }
	
	        j = 0;
	    }
	    
        for (int i = 0; i < qtd_amin_acidos; i++)
        {
            for (int j = 0; j <= qtd_amin_acidos; j++)
            {
                if (i != j)
                {
                    if (
                        registro_de_amin_acidos[i][0] == registro_de_amin_acidos[j][0]
                        &&
                        registro_de_amin_acidos[i][1] == registro_de_amin_acidos[j][1]
                        &&
                        registro_de_amin_acidos[i][2] == registro_de_amin_acidos[j][2]
                    ) {
                        falhou = 1;
                    }
                }
                
                if (falhou == 1)
                {
                    num_tentativas++;

                    printf("%dª tentativa: %c e %c sao iguais -> ", num_tentativas, proteina[i], proteina[j]);
                    printf("%s == %s\n", registro_de_amin_acidos[i], registro_de_amin_acidos[j]);

                    break;
                }
            }

            if (falhou == 1)
            {
                break;
            }
        }
        
        if (falhou == 0)
        {
            printf("\nCodigo genetico decifrado!\n");
            printf("\nTotal de tentativas: %d\n", num_tentativas + 1);
            printf("Codigo genetico:\n");

            for (int i = 0; i < qtd_amin_acidos; i++)
            {
                printf("%s", registro_de_amin_acidos[i]);
            }

            printf("\n");            

            break;
        }
    }
    
    if (falhou == 1)
    {
        printf("\nNao foi possivel decifrar o codigo genetico para a proteina:\n\n%s\n\n na sequencia genetica dada.\n\n", proteina);            
    }

    return 0;
}
