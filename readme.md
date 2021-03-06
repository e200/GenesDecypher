# GeneDecypher

GeneDecypher é um decifrador de código genético para amino ácidos, escrito em **C**, feito para um cliente estudante da Universidade Metodista de Angola.

## Como funciona?

Primeiro compile o arquivo `decypher.c` e execute o arquivo compilado assim:

`./arquivo_compilado dados/prot.1 dados/gene.1`.

Este decifrador genético vai ler cada arquivo passado como parámetro (`dados/prot.1` e `dados/gene.1`) e recolherá as amostras contidas neles. O primeiro arquivo deve ser sempre a proteína e o segundo a sequência genética.

Estas amostras serão analisadas internamente até não ser mais possível analisá-las ou o código genético ter cido decifrado.

## Como descobrir um código genético de um amino ácido?

Considere a seguinte proteína: `MSIQHMR`.

Cada letra dessa proteína representa um amino ácido.

Cada amino ácido possui um códon.

Cada codón só pode conter 3 nucleótides.

Um nucleótide é representado pelas letras {A, C, T, G}.

Perceba esse resumo na tabéla abaixo:

                   col

          | M | S | I | Q | H | M | R |   TODAS AS LETRAS FORMAM A PROTEÍNA.
    Lin   |att|gct|agc|aat|gct|agc|aat|   CADA LETRA TEM O SEU CODÓN.

Lembrando que cada amino ácido só pode conter 3 letras (nucleótides) no seu código genético.

Vamos então decifrar o código genético dos nossos amino ácidos `MSIQHMR`.

Essa é a nossa sequência genética: `attgctagcaatgctagcaattgctagcaattcat`.

Processos:

* 1º Verificar se temos dois ou mais amino ácidos com codóns iguais.
* 2º Caso o **1º processo** dê positivo, avançamos um nucleótide na sequência genética.
* 3º Repetimos os processos **1 e 2** até não termos amino ácidos com codóns iguais ou a sequência genética acabar.

Na prática:

|att|gct|agc|aat|gct|agc|aat|tgc|tag|caa|ttc|at |
|---|---|---|---|---|---|---|---|---|---|---|---|
|M  |S  |I  |Q  |H  |M  |R  |   |   |   |   |   |

Observe que no caso acima **S** e **H** são iguais (têm os mesmos codóns), então tentamos novamente avançando uma letra:

|a|ttg|cta|gca|atg|cta|gca|att|gct|agc|aat|tca|t  |
|-|---|---|---|---|---|---|---|---|---|---|---|---|
| |M  |S  |I  |Q  |H  |M  |R  |   |   |   |   |   |

Observe que no caso acima **S** e **H** são iguais, então tentamos novamente avançando mais uma letra:

|at|tgc|tag|caa|tgc|tag|caa|ttg|cta|gca|att|cat|   |
|--|---|---|---|---|---|---|---|---|---|---|---|---|
|  |M  |S  |I  |Q  |H  |M  |R  |   |   |   |   |   |

Observe que no caso acima **MS** e **QH** são iguais, então, fazendo o mesmo processo várias e várias vezes, na 10ª tentativa chegamos a esta sequência:

|a|ttg|cta|gca|atg|cta|gca|att|gct|agc|aat|tca|t|
|-|---|---|---|---|---|---|---|---|---|---|---|-|
| |   |   |   |M  |S  |I  |Q  |H  |M  |R  |   | |

Neste caso não temos proteínas com codóns iguais, certo? Todos codóns são diferentes. Isso significa que `atgctagcaattgctagcaat` é o nosso código genético decifrado.

Difícil e chato né??? Mas é o processo de decifrar um código genético e é o mesmo processo de **biologia computacional** que o **GeneDecypher** executa.

Esta versão foi escrita e testada em ambiente Linux. Se procura uma versão que funcione em ambientes Windows e seja compatível com DevC++, [veja](https://github.com/e200/GenesDecypher/tree/windows).
