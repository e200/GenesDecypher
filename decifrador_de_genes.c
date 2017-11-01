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

#include "leia_arquivo.h"

/**
 * Representa é o número de combinações
 * de amino ácidos.
 *
 * Existem 4 tipos de amino ácidos, isso
 * significa que só existem 64 possíveis combinações
 * entre os mesmos. (4 x 4 x 4 = 64).
 *
 * Para entender melhor veja a tabéla das combinações.
 */
#define NUM_AMIN_ACID 64

/**
 * Este é o limite de proteínas que o nosso
 * programa irá suportar.
 */
#define LIM_AMIN_ACID 1000

/**
 * Este é o limite de códigos genéticos
 * que o nosso programa irá suportar.
 * 
 * Se nos for passado mais do que isso, o
 * resto não será lido.
 */
#define LIM_SEQ_COD_GEN 10000

/**
 * Armazena as proteínas.
 */
int pegue_a_proteina(char ficheiro_proteina[], char *proteina, int *numero_proteina)
{
    // Conterá o número de amino acidos
    int contador = 0;
    
    /**
     * Pointeiro para o ficheiro.
     *
     * O ficheiro é de onde as proteínas
     * serão extraídas.
     */
    FILE *ptr_ficheiro;

    /**
     * Uma vez que iremos pegar carácter
     * por carácter, vamos armazenar cada
     * carácter na variável `c`, para
     * para posterior processamento.
     */
    char c;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_proteina, "r");

    /**
     * Aqui lemos cada carácter e armazenamos
     * no nosso vector `proteinas`.
     * 
     * Cada carácter representará uma sequência
     * de amino ácidos.
     */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        // Armazenando cada carácter.
        proteina[contador] = c;

        // Contando cada amino ácido.
        contador++;
    }

    /**
     * Uma vez contados o número de amino ácidos
     * vamos passá-lo ao ponteiro que representa
     * variável fora da função que conterá o
     * número de proteínas.
     */
    *numero_proteina = contador;
    
    // Nunca se esqueça: Limpar sempre a casa (memória).
    fclose(ptr_ficheiro);

    /**
     * Em C edde é o padrão para indicar que
     * a função foi executada com sucesso.
     */
    return 0;
}

/**
 * Pega a sequência dos genes
 * e associa a sua respectiva
 * proteína.
 */
int pegue_as_seq_de_genes(
    char ficheiro_seq_genes[],
    char sequencia_de_amino_acidos[][LIM_SEQ_COD_GEN],
    int num_amin_adic_lidos,
    int tentativas
) {
    FILE *ptr_ficheiro;

    char c;

    int
        linha = 0,
        coluna = 0,
        contador = 0;

    // Abrindo o arquivo.
    ptr_ficheiro = fopen(ficheiro_seq_genes, "r");

    /**
    * Aqui lemos cada carácter e armazenamos
    * no nosso vector `proteina`.
    */
    while ((c = getc(ptr_ficheiro)) != EOF)
    {
        if (contador > tentativas)
        {
            if (coluna != 2)
            {
                sequencia_de_amino_acidos[linha][coluna] = c;
    
                coluna++;
            }
            else
            {
                sequencia_de_amino_acidos[linha][coluna] = c;
                
                linha++;
                coluna = 0;
            }
    
            if (linha == num_amin_adic_lidos)
            {
                break;
            }
        }

        contador++;
    }

    // Nunca se esqueçam de limpar a memória.
    fclose(ptr_ficheiro);

    return 0;
}

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
        num_amin_adic_lidos,
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
        sequencia_de_amino_acidos[LIM_SEQ_COD_GEN],
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
    num_amin_adic_lidos = leia_arquivo("dados/proteina", proteina);

    /**
     * Pegando a sequência genética.
     */
    leia_arquivo("dados/sequencia_de_amino_acidos", sequencia_de_amino_acidos);

    /*while (cod_gen_decifrado != 1)
    {
        pegue_as_seq_de_genes(
            "dados/sequencia_de_amino_acidos",
            sequencia_de_amino_acidos,
            num_amin_adic_lidos,
            num_tentivas
        ); 

        // Percorrendo cada amino ácido.
        for (int i = 0; i < num_amin_adic_lidos; i++)
        {
            // Percorrendo cada sequência de um amino ácido.
            for (int j = 0; j <= num_amin_adic_lidos; j++)
            {
                if (i != j)
                {
                    if (
                        sequencia_de_amino_acidos[i][0] == sequencia_de_amino_acidos[j][0]
                        &&
                        sequencia_de_amino_acidos[i][1] == sequencia_de_amino_acidos[j][1]
                        &&
                        sequencia_de_amino_acidos[i][2] == sequencia_de_amino_acidos[j][2]
                    ) {
                        num_tentivas++;

                        printf("%dª tentativa: falhada\n\n", num_tentivas);

                        printf("%c: %s\n", proteina[i], sequencia_de_amino_acidos[i]);
                        printf("%c: %s\n", proteina[j], sequencia_de_amino_acidos[j]);
                    }
                }
            }

            /**
             * Se já lemos todos amino ácidos convém parar,
             * se não iremos ler lixo do buffer, e que não
             * é nosso.
             */
            /*if (i == num_amin_adic_lidos)
            {
                cod_gen_decifrado = 1;
                
                break;
            }
        }
    }*/
        
    return 0;
}