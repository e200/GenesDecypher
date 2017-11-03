/**
 * Este programa decifra o código
 * genético de um amino ácido em
 * uma proteína.
 *
 * Para entender como ele funciona,
 * é extremamente recomendável entender
 * antes como o código genético funciona.
 *
 * Para facilitar a compreensão de
 * quem venha a estudar esse código,
 * preferi separar algumas coisas em
 * arquivos.
 *
 * Mas ainda assim o código continua
 * um monstro.
 *
 * So, be careful...
 *
 * Data: 31/10/2017
 *
 * Autor: Eleandro Duzentos <eleandro@inbox.ru>
 * Repositório: https://github.com/e200/GenesDecypher/blob/master/
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Contém as constantes necessárias
 * para criarmos os vetores do nosso
 * decifrador.
 */
#include "lib/definicoes.h"

/**
 * Contém a função que lê todos
 * os bytes dos arquivos que contêm
 * as amostras necessárias para
 * decifrar o código genético de um
 * amino ácido.
 *
 * Estas amostras são: o arquivo que
 * contém o a proteína e o arquivo
 * que contém a sequência genética.
 */
#include "lib/leitor_de_amostras.h"

/**
 * Contém a função que regista cada
 * códon ao seu respectivo amino ácido.
 */
#include "lib/registrador_de_codons.h"

/**
 * O parámetro `argc` indica o número
 * de parámetros passados via terminal.
 *
 * O parámetro `argv` contem os parámetros
 * passados via terminal.
 *
 * Vamos usá-los para pegar as nossas ficheiros (amostras).
 */
int main(int argc, char *argv[])
{
    int
        /**
         * Informa quando uma tentativa
         * dentro do loop de tentativas
         * falhou ou não.
         */
        falhou,

        /**
         * Quantidade de amino ácidos
         * encontrados na proteína.
         */
        qtd_amin_acidos = 0,

        /**
         * Quantidade de nucleotides
         * encontrados na sequência genêtica.
         */
         qtd_nucleotides = 0,

        /**
         * Número de tentativas de decifrar
         * o código genético da proteína dada.
         */
        num_tentativas = 0,
        /**
         * Código genético decifrado?
         * 
         * Se 1, informa ao programa que
         * o código genético foi finalmente
         * decifrado.
         */
        cod_gen_decifrado = 0;

    char
        /**
         * Este vetor armazenará as letras que
         * representarão cada amino ácido
         * encontrado pelo nosso programa
         * na proteína.
         */
        proteina[MAX_AMIN_ACID_NA_PROT],

        /**
         * Este vetor armazenará a sequência
         * de amino ácidos extraídos da nossa
         * amostra de amino ácidos.
         */
        seq_amin_acidos[MAX_SEQ_GEN],

        /**
         * Esta matríz (ou vetor 2d) armazenará
         * as sequências de amino ácidos achados
         * a cada tentativa.
         *
         * Que tentativa?
         *
         * Achar o código genético de um amino
         * ácido consiste tentar, errar e tentar
         * de novo até achar.
         *
         * Só com isso, se entenderes bem de lógica
         * já sabes que vai chover **loops**.
         * 
         * As linhas representarão os amino ácidos.
         * As colunas representarão os códigos genéticos
         * que juntos formam os codóns.
         * 
         * Ex:
         *
         * Fique atento:
         *
         * Isto é uma proteína: MHISY.
         *
         * Cada letra dessa proteína representa um amino ácido.
         *
         * Cada amino ácido possui um códon.
         *
         * Cada codón possui 3 nucleotide.
         *
         * Um nucleotide é representado pelas letras {A, C, T, G}
         *
         * Perceba tudo isso nessa tabéla: 
         * 
         *                col
         *
         *       | M | H | I | S | Y |          TODAS AS LETRAS FORMAM A PROTEÍNA.
         * Lin   |AGT|TTT|GGA|AAG|ATA|          CADA LETRA TEM O SEU CODÓN.
         * 
         * Lembrando que cada amino ácido
         * só pode conter 3 letras no seu
         * código genético.
         */
        registro_de_amin_acidos[MAX_AMIN_ACID_NA_PROT][MAX_CODON];
    
    /**
     * Pegando os ponteiros para o caminho
     * das amostras.
     */
    char
        *amostra_proteina = argv[1],
        *amostra_sequencia_genetica = argv[2];

    /**
     * Pegando a nossa amostra da proteina.
     * 
     * O retorno da função `leia_amostra()`
     * é o número de amino ácidos que a nossa
     * proteína poderá conter.
     *
     * A nossa variável `proteína` será um
     * ponteiro que receberá de dentro da função
     * `leia_amostra()` a nossa proteina.
     */
    qtd_amin_acidos = leia_amostra(amostra_proteina, proteina);

    /**
     * Pegando a nossa amostra da sequência genética.
     *
     * O retorno da função `leia_amostra()`
     * é o número de nucletides que a nossa
     * sequência genética tem.
     *
     * A nossa variável `seq_amin_acidos` será um
     * ponteiro que receberá de dentro da função
     * `leia_amostra()` a nossa sequência genética.
     */
     qtd_nucleotides = leia_amostra(amostra_sequencia_genetica, seq_amin_acidos);

    /**
     * Até aqui já temos a nossa proteína e
     * a nossa sequência genética, é tudo que
     * que precisamos para fazer a nossa análize
     * e daí decifrar o código genético do nosso
     * amino ácido.
     *
     * Este `while` vai se executar até
     * alguém o dizer: para, o código
     * genético já foi encontrado, ou
     * o não haver mais tentativas
     * possíveis.
     */
    while ((cod_gen_decifrado == 0) && (num_tentativas < (qtd_nucleotides - qtd_amin_acidos)))
    {
        /**
         * Nova tentativa, ainda não sabemos
         * se ela falhará ou não, então
         * reiniciamos está variável.
         *
         * Caso está tentativa falhe, algures
         * alguém vai setar está variável com
         * o valor "1".
         */
        falhou = 0;

        /**
         * Vamos registrar os codóns disponíveis.
         */
        registre_os_codons(
            registro_de_amin_acidos,
            seq_amin_acidos,
            qtd_amin_acidos,
            num_tentativas
        );

        /**
         * Ok, temos os nossos codóns registrados
         * e associados aos seus amino ácidos na
         * matríz `registro_de_amin_acidos`.
         *
         * Agora vamos ver dentro do nosso registro
         * se há alguma sequência de codóns repetida,
         * se sim, o teste tá negativo (falhou), se não,
         * continuamos os nossos testes até testarmos
         * não encontrarmos nenhuma sequência repetida.
         *
         * Se isso acontecer bro, deciframos o nosso código
         * genético ou os amino ácidos da nossa proteína
         * acabaram kkkkkkkkkkkkkkk.
         *
         * Ok, vamos comparar o amino ácido `registro_de_amin_acidos[i]`
         * com os restantes, os restantes são todos os `registro_de_amin_acidos[j]`
         * diferentes do `registro_de_amin_acidos[i]`.
         */
        for (int i = 0; i < qtd_amin_acidos; i++)
        {
            // Percorrendo cada sequência de um amino ácido.
            for (int j = 0; j <= qtd_amin_acidos; j++)
            {
                /**
                 * Esta comparação previne que o mesmo
                 * amino ácido seja comparado consigo
                 * mesmo.
                 */
                if (i != j)
                {
                    /**
                     * Aqui verificamos se os codóns
                     * dos amino ácidos a serem testados
                     * são iguais.
                     *
                     * Se sim, o teste falha.
                     */
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

                /**
                 * A tentativa falhou? cancele este loop.
                 * Diga em que amino ácido falhou e qual
                 * foi a combinação.
                 */
                if (falhou == 1)
                {
                    num_tentativas++;

                    printf("%dª tentativa: ", num_tentativas);                        
                    printf("%c == %c: ", proteina[i], proteina[j]);
                    printf("%s == %s\n", registro_de_amin_acidos[i], registro_de_amin_acidos[j]);

                    break;
                }
            }

            // A tentativa falhou, cancele este loop.
            if (falhou == 1)
            {
                break;
            }
        }

        /**
         * Se os loops acima não acharam
         * uma falha, e não ocorreu erro
         * nenhum, então deciframos o código
         * genético do nosso amino ácido.
         *
         * Ele está no registro. É só imprimí-lo.
         */
        if (falhou == 0)
        {
            printf("\nCódigo genético decifrado: ");

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
        printf("\nNão foi possível decifrar o código genético da proteína:\n\n%s\n\n na sequência genética dada.\n\n", proteina);            
    }

    return 0;
}