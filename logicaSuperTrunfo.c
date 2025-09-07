#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Desafio Super Trunfo - Países - Comparação das Cartas
    Nível Novato - OK
    Nível Aventureiro - OK
    Nível Mestre - Pendente
*/

int main () {
    setlocale(LC_ALL, ".UTF-8");

    //Dados da Carta 1
    char estado;
    char codigoDaCarta[4];
    char nomeDaCidade[50];
    int numeroDePontosTuristicos;
    unsigned long int populacao;
    float areaEmKM, PIB, densidadePopulacional, PIBPerCapita;
    float superPoder;

    //Dados da Carta 2
    char estado2;
    char codigoDaCarta2[4];
    char nomeDaCidade2[50];
    int numeroDePontosTuristicos2;
    unsigned long int populacao2;
    float areaEmKM2, PIB2, densidadePopulacional2, PIBPerCapita2;
    float superPoder2;

    //Solicitando os dados da Carta 1
    printf("Digite os dados da Carta 1\n\n");

    printf("Digite o estado da carta: ");
    scanf("%c", &estado);

    printf("Digite o código da carta: ");
    scanf("%s", codigoDaCarta);

    //limpar o buffer
    while (getchar() != '\n');
    printf("Digite o nome da cidade: ");
    fgets(nomeDaCidade, 50, stdin);

    nomeDaCidade[strcspn(nomeDaCidade, "\n")] = '\0';

    printf("Digite a quantidade da população da cidade: ");
    scanf("%lu", &populacao);

    printf("Digite a área da cidade: ");
    scanf("%f", &areaEmKM);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB);

    printf("Digite o numero de pontos turísticos da cidade: ");
    scanf("%i", &numeroDePontosTuristicos);

    //Solicitando os dados da carta 2
    printf("\nDigite os dados da Carta 2\n\n");

    while (getchar() != '\n');
    printf("Digite o estado da carta: ");
    scanf("%c", &estado2);

    printf("Digite o código da carta: ");
    scanf("%s", codigoDaCarta2);

    //limpar o buffer
    while (getchar() != '\n');
    printf("Digite o nome da cidade: ");
    fgets(nomeDaCidade2, 50, stdin);

    nomeDaCidade2[strcspn(nomeDaCidade2, "\n")] = '\0';

    printf("Digite a quantidade da população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade: ");
    scanf("%f", &areaEmKM2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &PIB2);

    printf("Digite o numero de pontos turísticos da cidade: ");
    scanf("%i", &numeroDePontosTuristicos2);

    //calculando a Densidade Populacional das duas cartas
    densidadePopulacional = (float) populacao / areaEmKM;
    densidadePopulacional2 = (float) populacao2 / areaEmKM2;

    //Calculando o PIB per capita das duas cartas
    PIBPerCapita = PIB / (float) populacao;
    PIBPerCapita2 = PIB2 / (float) populacao2;

    //Calculando o super poder das cartas
    superPoder = populacao + areaEmKM + PIB + numeroDePontosTuristicos + PIBPerCapita + (1/densidadePopulacional);
    superPoder2 = populacao2 + areaEmKM2 + PIB2 + numeroDePontosTuristicos2 + PIBPerCapita2 + (1/densidadePopulacional2);

    //Menu
    printf("\nEscolha uma opção de comparação de atributos:\n\n");
    printf("Nome do País - 1\n");
    printf("População - 2\n");
    printf("Área - 3\n");
    printf("PIB - 4\n");
    printf("Número de Pontos Turísticos - 5\n");
    printf("Densidade Populacional - 6\n\n");

    int opcao;

    printf("Digite a opção desejada: ");
    scanf("%i", &opcao);
    printf("\n");

    switch (opcao)
    {
    case 1:
        printf("País 1: %s", nomeDaCidade);
        printf("País 2: %s", nomeDaCidade2);
        break;
    case 2:
        printf("País 1: %s\n", nomeDaCidade);
        printf("País 2: %s\n", nomeDaCidade2);
        printf("Usado o atributo População para comparação\n");
        printf("População do País %s: %lu\n", nomeDaCidade, populacao);
        printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);

        if (populacao > populacao2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade);
        } else if (populacao < populacao2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade2);
        }else {
            printf("Empate!");
        }

        break;
    case 3:
        printf("País 1: %s\n", nomeDaCidade);
        printf("País 2: %s\n", nomeDaCidade2);
        printf("Usado o atributo Área para comparação\n");
        printf("Área do País %s: %.2f\n", nomeDaCidade, areaEmKM);
        printf("Área do País %s: %.2f\n", nomeDaCidade2, areaEmKM2);

        if (areaEmKM > areaEmKM2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade);
        } else if (areaEmKM < areaEmKM2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade2);
        }else {
            printf("Empate!");
        }

        break;
    case 4:
        printf("País 1: %s\n", nomeDaCidade);
        printf("País 2: %s\n", nomeDaCidade2);
        printf("Usado o atributo PIB para comparação\n");
        printf("PIB do País %s: %.2f\n", nomeDaCidade, PIB);
        printf("PIB do País %s: %.2f\n", nomeDaCidade2, PIB2);

        if (PIB > PIB2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade);
        } else if (PIB < PIB2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade2);
        }else {
            printf("Empate!");
        }

        break;
    case 5:
        printf("País 1: %s\n", nomeDaCidade);
        printf("País 2: %s\n", nomeDaCidade2);
        printf("Usado o atributo Número de Pontos Turísticos para comparação\n");
        printf("Número de Pontos Turísticos do País %s: %i\n", nomeDaCidade, numeroDePontosTuristicos);
        printf("Número de Pontos Turísticos do País %s: %i\n", nomeDaCidade2, numeroDePontosTuristicos2);

        if (numeroDePontosTuristicos > numeroDePontosTuristicos2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade);
        } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade2);
        }else {
            printf("Empate!");
        }

        break;
    case 6:
        printf("País 1: %s\n", nomeDaCidade);
        printf("País 2: %s\n", nomeDaCidade2);
        printf("Usado o atributo Densidade Populacional para comparação\n");
        printf("Densidade Populacional do País %s: %.2f\n", nomeDaCidade, densidadePopulacional);
        printf("Densidade Populacional %s: %.2f\n", nomeDaCidade2, densidadePopulacional2);

        if (densidadePopulacional > densidadePopulacional2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade);
        } else if (populacao < populacao2){
            printf("A carta vencodora foi a do País %s!\n", nomeDaCidade2);
        }else {
            printf("Empate!");
        }

        break;
    default:
        printf("Opção Invalida!");
        break;
    }

return 0;
}
