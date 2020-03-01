#include <stdio.h>

char * get_value_of_index(double index)
{
    if (index <= 20.5)
    {
        return "sovany";
    }
    
    else if (index >= 20.5 && index <= 26.5)
    {
        return "normal";
    }
    else if (index >= 26.6 && index <= 31.9)
    {
        return "tulsuly";
    }
    else if (index >= 32.0 && index <= 36.9)
    {
        return "I. foku elhizas";
    }
    else if (index >= 37.0 && index <= 41.9)
    {
        return "II. foku elhizas";
    }

    return "III. foku elhizas";
}

int main()
{
    float suly;
    printf("Testsuly (kg): ");
    scanf("%f", &suly);

    float magassag;
    printf("Testmagassag (cm): ");
    scanf("%f", &magassag);

    double index = suly / (magassag * magassag / 10000);
    printf("\nAz On testtomegindexe: %.1f\n", index);
    printf("Ennek jelentese: %s\n", get_value_of_index(index));

    return 0;
}