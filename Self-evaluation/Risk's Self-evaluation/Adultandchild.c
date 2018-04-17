#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int age, base;
    float point=0, OSA=0, ABN=0, MIX=0, height, weight, bmi;
    char answer, sex;
    system("cls");
    printf("Please enter your age.");
    scanf(" %d", &age);
    if (age>=40){point++;}
    printf("\nPlease enter your sex?(f-female/m-male) ");
    scanf(" %c", &sex);
    system("cls");
    if (sex=='f'){
        printf("Are you pregnant?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;}
    }
    else if (sex=='m'){point++;}

    printf("\nAre you colored people?(y/n) ");
    answer = getchar();
    if (answer=='y'){point++;}

    printf("\nDo you allergic to something?(y/n) ");
    answer = getchar();
    if (answer=='y'){OSA++;}

    if (age < 18) {
        printf("\nAre you wet your bed at night?(y/n) ");
        answer = getchar();
        if (answer=='y'){ABN+=0.5;}

        printf("\nHave you massive perspire at night?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;}

        printf("\nAre you breathing by mouth instead of the nose during the day?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;}

        printf("\nDo you often have a nightmare?(y/n) ");
        answer = getchar();
        if (answer=='y'){point+=0.5;}
        
        printf("\nAre you Mischievously or fidget?(y/n) ");
        answer = getchar();
        if (answer=='y'){point+=0.5;}

        printf("\nAre you not good or behide at study?(y/n) ");
        answer = getchar();
        if (answer=='y'){MIX+=0.5;}
    }

    else {
        printf("\nDo you smoking?(y/n) ");
        answer = getchar();
        if (answer=='y'){OSA++;}
        
        printf("\nDo you smoke opium?(y/n) ");
        answer = getchar();
        if (answer=='y'){ABN++;}
        
        printf("\nDo you  drink alcohol?(y/n) ");
        answer = getchar();
        if (answer=='y'){OSA++;}
        
        printf("\nDo you hard to deep sleep?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;}  

        printf("\nDo you frequent urination at night?(y/n) ");
        answer = getchar();
        if (answer=='y'){ABN++;}  

        printf("\nDo you shockingly like suffocate?(y/n) ");
        answer = getchar();
        if (answer=='y'){MIX+=2;}   

        printf("\nHave a headache in the morning?(y/n) ");
        answer = getchar();
        if (answer=='y'){MIX++;}   

        printf("\nDry mouth and sore throat when awake?(y/n) ");
        answer = getchar();
        if (answer=='y'){point+=1.5;}        

        printf("\nFall asleep while sitting in quietly place?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;} 

        printf("\nCan sleep at any time and not enough?(y/n) ");
        answer = getchar();
        if (answer=='y'){point++;} 

        printf("\nDo you have a problems with memory or concentration?(y/n) ");
        answer = getchar();
        if (answer=='y'){MIX++;}

        printf("\nChangeful mood?(y/n) ");
        answer = getchar();
        if (answer=='y'){MIX++;} 
    }
    system("cls");
    printf("Please enter your height(cm.)\n");
    scanf("%f", &height);
    printf("\nPlease enter your weight(kg.)\n");
    scanf(" %f", &weight);
    height = height / 100;
    bmi = weight / (height * height);

    system("cls");
    printf("---------------------RESULT----------------------\n");
    printf("  Age    = %d years old.\n", age);
    printf("  Height = %.2f cm.\n", height * 100);
    printf("  Weight = %.2f kg.\n", weight);
    printf("  BMI    = %.2f \n", bmi);
    if (age<18){bmi-=2;}
    printf("------------------BMI CRITERION------------------\n");
    printf("      BMI < 18.50       :   Underweight\n");
    printf("      BMI 16.0 - 22.9   :   Normal\n");
    printf("      BMI 23.0 - 24.9   :   Overweight\n");
    printf("      BMI 25.0 - 29.9   :   Pre-obese\n");
    printf("      BMI 30.0 - 40.0   :   Obese\n");
    printf("      BMI 40.1 - 50.0   :   Morbid-obese\n");
    printf("      BMI > 50.0        :   Super-obese\n");
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    if (bmi <= 18.5) {
        printf("  Comment : You are underweight, you need to do more exercise and eat all 5 groups.\n");
        printf("  Risk    : Malnutrition.\n");
    }
    else if (bmi > 18.5 && bmi <= 22.9) {
        printf("  Comment :     You are normalweight.\n");
        printf("  Risk    :     None\n");
    }
    else if (bmi > 22.9 && bmi <= 24.9) {
        printf("  Comment : You are overweight, please do exercise and bate greasy foods.\n");
        printf("  Risk    : None\n");
        OSA++;
    }
    else if (bmi > 24.9 && bmi <= 29.9) {
        printf("  Comment : You are pre-obese, please do exercise and avoid greasy foods.\n");
        printf("  Risk    : High Blood Pressure and Gestational Diabetes\n");
        OSA+=1.5;
    }
    else if (bmi > 29.9) {
        printf("  Comment : You are obese, please beware for obesity and do exercise with avoid greasy foods.\n");
        printf("  Risk    : High Blood Pressure, Gestational Diabetes and Obesity\n");
        OSA+=2;
    }

    if (age<18){base=2000;} else{base=8800;}
    printf("%d\n", base);
    printf(" Risk to have a sleep apnea disease : %f%%\n", (point+OSA+ABN+MIX/base)*100);
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    return 0;
}
