/**
 * Este programa decifra o código
 * genético de amino ácidos.
 * 
 * Data: 31/10/2017
 *
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200/GenesDecypher/blob/master/
 */

#include <stdio.h>
#include <stdlib.h>

#include "definicoes.h"
#include "leia_arquivo.h"
#include "resolve_seq_gen.h"
/**
 * O parámetro `argc` indica o número
 * de parámetros passados via terminal.
 *
 * O parámetro `argv` contem os parámetros
 * passados via terminal.
 */
int main(int argc, char *argv[])
{
    int
        /**
         * Número de amino ácidos lidos
         * no arquivo contendo a proteína.
         */
        num_amin_acid_lidos,
        /**
         * Número de tentativas de decifrar
         * o código genético da proteína dada.
         */
        num_tentivas = 0,
        /**
         * Código genético decifrado?
         * 
         * Informa ao programa quando
         * o código genético foi finalmente
         * decifrado.
         */
        cod_gen_decifrado = 0;

    char
        /**
         * Vetor que armazenará as letras que
         * representarão cada amino ácido.
         */
        proteina[NUM_AMIN_ACID],
        /**
         * Vetor que armazenará a sequência
         * de onde extraíremos os amino ácidos.
         */
        seq_amin_acid[LIM_SEQ_COD_GEN],
        /**
         * Matríz (vetor 2d) que armazenará as
         * sequências de amino ácidos achados a cada tentiva.
         * 
         * As linhas representarão os amino ácidos.
         * As colunas representarão os códigos genéticos
         * dos amino ácidos.
         * 
         * Ex:
         * 
         *    |Col|Col|Col|Col|Col|
         * Lin| M | H | I | S | Y |
         * Lin|AGT|TTT|GGA|AAG|ATA|
         * 
         * Lembrando que cada amino ácido
         * só pode conter 3 letras no seu
         * código genético.
         */
        amin_acids_achados[NUM_AMIN_ACID][LIM_SEQ_COD_GEN];  
        ;  
    
    /**
     * Pegando a proteina.
     * 
     * O retorno é o número de amino ácidos
     * que essa proteína deverá conter.
     */
    num_amin_acid_lidos = leia_arquivo("dados/proteina", proteina);

    /**
     * Pegando a sequência genética.
     */
    leia_arquivo("dados/seq_amin_acid", seq_amin_acid);

    while (cod_gen_decifrado == 0)
    {
        resolva_seq_gen(
            amin_acids_achados,
            seq_amin_acid,
            num_amin_acid_lidos,
            num_tentivas
        );
        printf("%s", amin_acids_achados[2]);
        /*for (int i = 0; i < num_amin_acid_lidos; i++)
        {
            // Percorrendo cada sequência de um amino ácido.
            for (int j = 0; j <= num_amin_acid_lidos; j++)
            {
                if (i != j)
                {
                    if (
                        amin_acids_achados[i][0] == amin_acids_achados[j][0]
                        &&
                        amin_acids_achados[i][1] == amin_acids_achados[j][1]
                        &&
                        amin_acids_achados[i][2] == amin_acids_achados[j][2]
                    ) {
                        num_tentivas++;

                        printf("%dª tentativa: falhada\n\n", num_tentivas);

                        printf("%c: %s\n", proteina[i], amin_acids_achados[i]);
                        printf("%c: %s\n", proteina[j], amin_acids_achados[j]);
                    }
                }
            }
        }*/

        cod_gen_decifrado = 1;
    }

    /*while (cod_gen_decifrado != 1)
    {
        pegue_as_seq_de_genes(
            "dados/seq_amin_acid",
            seq_amin_acid,
            num_amin_acid_lidos,
            num_tentivas
        ); 

        // Percorrendo cada amino ácido.
        for (int i = 0; i < num_amin_acid_lidos; i++)
        {
            // Percorrendo cada sequência de um amino ácido.
            for (int j = 0; j <= num_amin_acid_lidos; j++)
            {
                if (i != j)
                {
                    if (
                        seq_amin_acid[i][0] == seq_amin_acid[j][0]
                        &&
                        seq_amin_acid[i][1] == seq_amin_acid[j][1]
                        &&
                        seq_amin_acid[i][2] == seq_amin_acid[j][2]
                    ) {
                        num_tentivas++;

                        printf("%dª tentativa: falhada\n\n", num_tentivas);

                        printf("%c: %s\n", proteina[i], seq_amin_acid[i]);
                        printf("%c: %s\n", proteina[j], seq_amin_acid[j]);
                    }
                }
            }

            /**
             * Se já lemos todos amino ácidos convém parar,
             * se não iremos ler lixo do buffer, e que não
             * é nosso.
             */
            /*if (i == num_amin_acid_lidos)
            {
                cod_gen_decifrado = 1;
                
                break;
            }
        }
    }*/
        
    return 0;
}