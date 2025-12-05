#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[50], cidade2[50];

    unsigned long populacao1, populacao2; // agora unsigned long int
    float area1, area2;
    float pib1, pib2; // PIB informado em BILHÕES de reais
    int pontos1, pontos2;

    float dens1, dens2;
    float percap1, percap2;
    float super1, super2;

    // -------- CARTA 1 --------
    printf("Estado: ");
    scanf(" %c", &estado1);

    printf("Codigo: ");
    scanf(" %4s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area: ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos1);

    // Cálculos carta 1 
    if (area1 == 0.0f) {
        dens1 = 0.0f;
    } else {
        dens1 = (float)((double)populacao1 / (double)area1);
    }

    if (populacao1 == 0UL) {
        percap1 = 0.0f;
    } else {
        // pib1 está em BILHÕES -> converter para reais antes de dividir
        percap1 = (float)((double)pib1 * 1e9 / (double)populacao1);
    }

    // inverso da densidade (se densidade 0 -> inverso 0)
    double inv_dens1 = (dens1 == 0.0f) ? 0.0 : 1.0 / (double)dens1;

    // Super Poder: somar em double (para segurança) e armazenar em float
    // Usar PIB em reais (pib1 * 1e9) para coerência com percap
    double soma1 = (double)populacao1
                 + (double)area1
                 + (double)pib1 * 1e9
                 + (double)pontos1
                 + (double)percap1
                 + inv_dens1;
    super1 = (float)soma1;

    // -------- CARTA 2 --------
    printf("\nEstado: ");
    scanf(" %c", &estado2);

    printf("Codigo: ");
    scanf(" %4s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area: ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontos2);

    // Cálculos carta 2
    if (area2 == 0.0f) {
        dens2 = 0.0f;
    } else {
        dens2 = (float)((double)populacao2 / (double)area2);
    }

    if (populacao2 == 0UL) {
        percap2 = 0.0f;
    } else {
        percap2 = (float)((double)pib2 * 1e9 / (double)populacao2);
    }

    double inv_dens2 = (dens2 == 0.0f) ? 0.0 : 1.0 / (double)dens2;

    double soma2 = (double)populacao2
                 + (double)area2
                 + (double)pib2 * 1e9
                 + (double)pontos2
                 + (double)percap2
                 + inv_dens2;
    super2 = (float)soma2;

    // -------- SAÍDA --------
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %50s\n", cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", dens1);
    printf("PIB per Capita: %.2f reais\n", percap1);
    printf("Super Poder: %.2f\n", super1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", dens2);
    printf("PIB per Capita: %.2f reais\n", percap2);
    printf("Super Poder: %.2f\n", super2);

    // -------- COMPARAÇÕES --------
    printf("\nComparacao de Cartas:\n\n");

    // População (maior vence)
    printf("Populacao: Carta %d venceu (%d)\n",
           (populacao1 >= populacao2) ? 1 : 2,
           (populacao1 >= populacao2) ? 1 : 0);

    // Área (maior vence)
    printf("Area: Carta %d venceu (%d)\n",
           (area1 >= area2) ? 1 : 2,
           (area1 >= area2) ? 1 : 0);

    // PIB (maior vence) -- comparar PIB em reais (multiplica por 1e9) ou em bilhões? usamos em reais
    printf("PIB: Carta %d venceu (%d)\n",
           ((double)pib1 * 1e9 >= (double)pib2 * 1e9) ? 1 : 2,
           ((double)pib1 * 1e9 >= (double)pib2 * 1e9) ? 1 : 0);

    // Pontos Turísticos (maior vence)
    printf("Pontos Turisticos: Carta %d venceu (%d)\n",
           (pontos1 >= pontos2) ? 1 : 2,
           (pontos1 >= pontos2) ? 1 : 0);

        
    //======menu de comparação======
    int opçao;

    printf("\n===menu de commparação===\n");
    printf("1- populacao\n");
    printf("2- area\n");
    printf("3- pib\n");
    printf("4- pontos turisticos\n");
    printf("5- densidade demografica\n");
    scanf("%d", &opçao);

    printf("\n=======RESULTADO DE COMPARAÇÃO=======\n");
    switch (opçao)
    {
    case 1:// população
        printf("comparando populaçao\n");
    printf("%s: %lu hab\n", cidade1, populacao1);
            printf("%s: %lu hab\n", cidade2, populacao2);

            if (populacao1 > populacao2)
                printf("Vencedor: %s\n", cidade1);
            else if (populacao2 > populacao1)
                printf("Vencedor: %s\n", cidade2);
            else
                printf("Empate!\n");
            break;

    case 2: // Área
            printf("Comparando AREA:\n");
            printf("%s: %.2f km²\n", cidade1, area1);
            printf("%s: %.2f km²\n", cidade2, area2);

            if (area1 > area2)
                printf("Vencedor: %s\n", cidade1);
            else if (area2 > area1)
                printf("Vencedor: %s\n", cidade2);
            else
                printf("Empate!\n");
            break;

    case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões\n", cidade1, pib1);
            printf("%s: %.2f bilhões\n", cidade2, pib2);

            if (pib1 > pib2)
                printf("Vencedor: %s\n", cidade1);
            else if (pib2 > pib1)
                printf("Vencedor: %s\n", cidade2);
            else
                printf("Empate!\n");
            break;

    case 4: // Pontos Turísticos
            printf("Comparando PONTOS TURISTICOS:\n");
            printf("%s: %d pontos\n", cidade1, pontos1);
            printf("%s: %d pontos\n", cidade2, pontos2);

            if (pontos1 > pontos2)
                printf("Vencedor: %s\n", cidade1);
            else if (pontos2 > pontos1)
                printf("Vencedor: %s\n", cidade2);
            else
                printf("Empate!\n");
            break;

    case 5: // Densidade — regra invertida (MENOR vence)
            printf("Comparando DENSIDADE DEMOGRAFICA (MENOR VENCE):\n");
            printf("%s: %.2f hab/km²\n", cidade1, dens1);
            printf("%s: %.2f hab/km²\n", cidade2, dens2);

            if (dens1 < dens2)
                printf("Vencedor: %s\n", cidade1);
            else if (dens2 < dens1)
                printf("Vencedor: %s\n", cidade2);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }

    
   

    
    return 0;
}
