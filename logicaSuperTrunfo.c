#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Desafio Super Trunfo - Países - Comparação das Cartas
    Nível Novato - OK
    Nível Aventureiro - OK
    Nível Mestre - OK
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

    int opcao, opcao2, cartaVencedora = 0, somaDosAtributos, somaDosAtributos2;
    int pontosCarta1 = 0, pontosCarta2 = 0;

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

        if (populacao > populacao2) {
            pontosCarta1 += 1;
        } else if (populacao < populacao2) {
            pontosCarta2 += 1;
        }
        
        printf("\n\nAgora escolha um segundo atributo para comparação!\n");
        printf("Área - 1\n");
        printf("PIB - 2\n");
        printf("Número de Pontos Turísticos - 3\n");
        printf("Densidade Populacional - 4\n\n");

        scanf("%i", &opcao2);
        switch (opcao2)
        {
        case 1:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e Área em KM² para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            
            somaDosAtributos = areaEmKM + populacao;
            somaDosAtributos2 = areaEmKM2 + populacao2;

            if (areaEmKM > areaEmKM2) {
                pontosCarta1 += 1;
            } else if (areaEmKM < areaEmKM2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 2:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e PIB para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            
            somaDosAtributos = PIB + populacao;
            somaDosAtributos2 = PIB2 + populacao2;

            if (PIB > PIB2) {
                pontosCarta1 += 1;
            } else if (PIB < PIB2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 3:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e Número de Pontos Turísticos para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            
            somaDosAtributos = numeroDePontosTuristicos + populacao;
            somaDosAtributos2 = numeroDePontosTuristicos2 + populacao2;

            if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
                pontosCarta1 += 1;
            } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 4:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e Densidade Populacional para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Popilacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            
            somaDosAtributos = densidadePopulacional + populacao;
            somaDosAtributos2 = densidadePopulacional2 + populacao2;

            if (densidadePopulacional < densidadePopulacional2) {
                pontosCarta1 += 1;
            } else if (densidadePopulacional > densidadePopulacional2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        
        default:
            printf("Opção Invalida!");
            break;
        }
        break;
    case 3:

        if (areaEmKM > areaEmKM2) {
            pontosCarta1 += 1;
        } else if (areaEmKM < areaEmKM2) {
            pontosCarta2 += 1;
        }
        
        printf("\n\nAgora escolha um segundo atributo para comparação!\n");
        printf("População - 1\n");
        printf("PIB - 2\n");
        printf("Número de Pontos Turísticos - 3\n");
        printf("Densidade Populacional - 4\n\n");

        scanf("%i", &opcao2);
        switch (opcao2)
        {
        case 1:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Área em KM² e População para comparação\n");
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            
            somaDosAtributos = areaEmKM + populacao;
            somaDosAtributos2 = areaEmKM2 + populacao2;

            if (populacao > populacao2) {
                pontosCarta1 += 1;
            } else if (populacao < populacao2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 2:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Área em KM² e PIB para comparação\n");
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            
            somaDosAtributos = PIB + areaEmKM;
            somaDosAtributos2 = PIB2 + areaEmKM2;

            if (PIB > PIB2) {
                pontosCarta1 += 1;
            } else if (PIB < PIB2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 3:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Área em KM² e Número de Pontos Turísticos para comparação\n");
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            
            somaDosAtributos = numeroDePontosTuristicos + areaEmKM;
            somaDosAtributos2 = numeroDePontosTuristicos2 + areaEmKM2;

            if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
                pontosCarta1 += 1;
            } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 4:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Área em KM² e Densidade Populacional para comparação\n");
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Popilacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            
            somaDosAtributos = densidadePopulacional + areaEmKM;
            somaDosAtributos2 = densidadePopulacional2 + areaEmKM2;

            if (densidadePopulacional < densidadePopulacional2) {
                pontosCarta1 += 1;
            } else if (densidadePopulacional > densidadePopulacional2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        
        default:
            printf("Opção Invalida!");
            break;
        }
        break;
    case 4:

        if (PIB > PIB2) {
            pontosCarta1 += 1;
        } else if (PIB < PIB2) {
            pontosCarta2 += 1;
        }
        
        printf("\n\nAgora escolha um segundo atributo para comparação!\n");
        printf("Área - 1\n");
        printf("População - 2\n");
        printf("Número de Pontos Turísticos - 3\n");
        printf("Densidade Populacional - 4\n\n");

        scanf("%i", &opcao2);
        switch (opcao2)
        {
        case 1:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos PIB e Área em KM² para comparação\n");
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            
            somaDosAtributos = areaEmKM + populacao;
            somaDosAtributos2 = areaEmKM2 + populacao2;

            if (areaEmKM > areaEmKM2) {
                pontosCarta1 += 1;
            } else if (areaEmKM < areaEmKM2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 2:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e PIB para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            
            somaDosAtributos = PIB + populacao;
            somaDosAtributos2 = PIB2 + populacao2;

            if (PIB > PIB2) {
                pontosCarta1 += 1;
            } else if (PIB < PIB2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 3:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos PIB e Número de Pontos Turísticos para comparação\n");
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            
            somaDosAtributos = numeroDePontosTuristicos + PIB;
            somaDosAtributos2 = numeroDePontosTuristicos2 + PIB2;

            if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
                pontosCarta1 += 1;
            } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 4:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos PIB e Densidade Populacional para comparação\n");
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            
            somaDosAtributos = densidadePopulacional + PIB;
            somaDosAtributos2 = densidadePopulacional2 + PIB2;

            if (densidadePopulacional < densidadePopulacional2) {
                pontosCarta1 += 1;
            } else if (densidadePopulacional > densidadePopulacional2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        
        default:
            printf("Opção Invalida!");
            break;
        }
        break;
    case 5:

        if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
            pontosCarta1 += 1;
        } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
            pontosCarta2 += 1;
        }
        
        printf("\n\nAgora escolha um segundo atributo para comparação!\n");
        printf("Área - 1\n");
        printf("PIB - 2\n");
        printf("População - 3\n");
        printf("Densidade Populacional - 4\n\n");

        scanf("%i", &opcao2);
        switch (opcao2)
        {
        case 1:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Número de Pontos Turísticos e Área em KM² para comparação\n");
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            
            somaDosAtributos = areaEmKM + numeroDePontosTuristicos;
            somaDosAtributos2 = areaEmKM2 + numeroDePontosTuristicos2;

            if (areaEmKM > areaEmKM2) {
                pontosCarta1 += 1;
            } else if (areaEmKM < areaEmKM2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 2:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Número de Pontos Turísticos e PIB para comparação\n");
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            
            somaDosAtributos = PIB + numeroDePontosTuristicos;
            somaDosAtributos2 = PIB2 + numeroDePontosTuristicos2;

            if (PIB > PIB2) {
                pontosCarta1 += 1;
            } else if (PIB < PIB2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 3:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos População e Número de Pontos Turísticos para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            
            somaDosAtributos = numeroDePontosTuristicos + populacao;
            somaDosAtributos2 = numeroDePontosTuristicos2 + populacao2;

            if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
                pontosCarta1 += 1;
            } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 4:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Número de Pontos Turísticos e DensidadePopulacional para comparação\n");
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Popilacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            
            somaDosAtributos = densidadePopulacional + numeroDePontosTuristicos;
            somaDosAtributos2 = densidadePopulacional2 + numeroDePontosTuristicos2;

            if (densidadePopulacional < densidadePopulacional2) {
                pontosCarta1 += 1;
            } else if (densidadePopulacional > densidadePopulacional2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        
        default:
            printf("Opção Invalida!");
            break;
        }
        break;
    case 6:

        if (densidadePopulacional > densidadePopulacional2) {
            pontosCarta1 += 1;
        } else if (densidadePopulacional < densidadePopulacional2) {
            pontosCarta2 += 1;
        }
        
        printf("\n\nAgora escolha um segundo atributo para comparação!\n");
        printf("Área - 1\n");
        printf("PIB - 2\n");
        printf("Número de Pontos Turísticos - 3\n");
        printf("População - 4\n\n");

        scanf("%i", &opcao2);
        switch (opcao2)
        {
        case 1:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Densidade Populacional e Área em KM² para comparação\n");
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade, areaEmKM);
            printf("Área em KM² do País %s: %lu\n", nomeDaCidade2, areaEmKM2);
            
            somaDosAtributos = areaEmKM + densidadePopulacional;
            somaDosAtributos2 = areaEmKM2 + densidadePopulacional2;

            if (areaEmKM > areaEmKM2) {
                pontosCarta1 += 1;
            } else if (areaEmKM < areaEmKM2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 2:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Densidade Populacional e PIB para comparação\n");
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            printf("PIB do País %s: %lu\n", nomeDaCidade, PIB);
            printf("PIB do País %s: %lu\n", nomeDaCidade2, PIB2);
            
            somaDosAtributos = PIB + densidadePopulacional;
            somaDosAtributos2 = PIB2 + densidadePopulacional2;

            if (PIB > PIB2) {
                pontosCarta1 += 1;
            } else if (PIB < PIB2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 3:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Densidade Populacional e Número de Pontos Turísticos para comparação\n");
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade, numeroDePontosTuristicos);
            printf("Número de Pontos Turísticos do País %s: %lu\n", nomeDaCidade2, numeroDePontosTuristicos2);
            
            somaDosAtributos = numeroDePontosTuristicos + densidadePopulacional;
            somaDosAtributos2 = numeroDePontosTuristicos2 + densidadePopulacional2;

            if (numeroDePontosTuristicos > numeroDePontosTuristicos2) {
                pontosCarta1 += 1;
            } else if (numeroDePontosTuristicos < numeroDePontosTuristicos2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        case 4:
            printf("País 1: %s\n", nomeDaCidade);
            printf("País 2: %s\n", nomeDaCidade2);
            printf("Usado os atributos Densidade Populacional e População para comparação\n");
            printf("População do País %s: %lu\n", nomeDaCidade, populacao);
            printf("População do País %s: %lu\n", nomeDaCidade2, populacao2);
            printf("Densidade Populacional do País %s: %lu\n", nomeDaCidade, densidadePopulacional);
            printf("Densidade Popilacional do País %s: %lu\n", nomeDaCidade2, densidadePopulacional2);
            
            somaDosAtributos = densidadePopulacional + populacao;
            somaDosAtributos2 = densidadePopulacional2 + populacao2;

            if (densidadePopulacional < densidadePopulacional2) {
                pontosCarta1 += 1;
            } else if (densidadePopulacional > densidadePopulacional2) {
                pontosCarta2 += 1;
            }

            if (somaDosAtributos > somaDosAtributos2) {
                pontosCarta1 += 1;
            } else if (somaDosAtributos < somaDosAtributos2) {
                pontosCarta2 += 1;
            }

            if (pontosCarta1 == pontosCarta2) {
                printf("Empate!");
            } else if (pontosCarta1 > pontosCarta2){
                printf("A Carta 1 venceu!");
            } else {
                printf("A Carta 2 venceu!");
            }

            break;
        
        default:
            printf("Opção Invalida!");
            break;
        }
        break;
    }
return 0;
}
