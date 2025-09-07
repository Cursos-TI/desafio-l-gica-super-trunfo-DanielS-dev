#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*Desafio Super Trunfo - Países - Comparação das Cartas
    Nível Novato - OK
    Nível Aventureiro - Pendente
    Nível Mestre - Pendente
*/

int main () {
    setlocale(LC_ALL, ".UTF-8");

    char estado;
    char codigoDaCarta[4];
    char nomeDaCidade[50];
    int numeroDePontosTuristicos;
    unsigned long int populacao;
    float areaEmKM, PIB, densidadePopulacional, PIBPerCapita;
    float superPoder;

    char estado2;
    char codigoDaCarta2[4];
    char nomeDaCidade2[50];
    int numeroDePontosTuristicos2;
    unsigned long int populacao2;
    float areaEmKM2, PIB2, densidadePopulacional2, PIBPerCapita2;
    float superPoder2;

    //Solicitando os dados da Carta 1
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

    //Comparação de um único atributo usando if e else
    if (densidadePopulacional < densidadePopulacional2){
        printf("Comparação de Cartas (Atributo: Densidade Populacional): \n\n");
        printf("Carta 1 - %s: %.2f\n", nomeDaCidade, densidadePopulacional);
        printf("Carta 2 - %s: %.2f\n", nomeDaCidade2, densidadePopulacional2);
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade);
    }else {
        printf("Comparação de Cartas (Atributo: Densidade Populacional): \n\n");
        printf("Carta 1 - %s: %.2f\n", nomeDaCidade, densidadePopulacional);
        printf("Carta 2 - %s: %.2f\n", nomeDaCidade2, densidadePopulacional2);
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
    }

return 0;
}
