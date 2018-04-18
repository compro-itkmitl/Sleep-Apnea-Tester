#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int main() {
    int age;
    float point=0, OSA=0, ABN=0, MIX=0, height, weight, bmi, base;
    char answer, sex;
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    system("cls");
    printf("\n Please enter your age.\n");
    scanf("%d", &age);
    getchar();
    if (age>=40){point++;}
    printf("\n Please enter your sex?(f-female/m-male)\n");
    scanf("%c", &sex);
    getchar();
    system("cls");
    if (sex=='f'){
        printf("\n Are you pregnant?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}
    }
    else if (sex=='m'){point++;}

    printf("\n Are you colored people?(y/n)\n");
    scanf("%c", &answer);
    getchar();
    if (answer=='y'){point++;}

    printf("\n Do you allergic to something?(y/n)\n");
    scanf("%c", &answer);
    getchar();
    if (answer=='y'){OSA++;}

    if (age < 18) {
        printf("\n Are you wet your bed at night?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){ABN+=0.5;}

        printf("\n Have you massive perspire at night?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}

        printf("\n Are you breathing by mouth instead of the nose during the day?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}

        printf("\n Do you often have a nightmare?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point+=0.5;}
        
        printf("\n Are you Mischievously or fidget?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point+=0.5;}

        printf("\n Are you not good or behide at study?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){MIX+=0.5;}
    }

    else {
        printf("\n Do you smoking?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){OSA++;}
        
        printf("\n Do you smoke opium?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){ABN++;}
        
        printf("\n Do you  drink alcohol?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){OSA++;}
        
        printf("\n Do you hard to deep sleep?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}

        printf("\n Do you frequent urination at night?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){ABN++;}

        printf("\n Do you shockingly like suffocate?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){MIX+=2;}

        printf("\n Have a headache in the morning?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){MIX++;}

        printf("\n Dry mouth and sore throat when awake?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point+=1.5;}

        printf("\n Fall asleep while sitting in quietly place?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}

        printf("\n Can sleep at any time and not enough?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){point++;}

        printf("\n Do you have a problems with memory or concentration?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){MIX++;}

        printf("\n Changeful mood?(y/n)\n");
        scanf("%c", &answer);
        getchar();
        if (answer=='y'){MIX++;}
    }
    system("cls");
    printf("\n Please enter your height(cm.)\n");
    scanf("%f", &height);
    getchar();
    printf("\n Please enter your weight(kg.)\n");
    scanf("%f", &weight);
    height = height / 100;
    bmi = weight / (height * height);

    system("cls");
    printf ( "\n            %s\n", asctime (timeinfo) );
    printf("---------------------RESULT----------------------\n");
    printf("      Age    = %d years old.\n", age);
    printf("      Height = %.2f cm.\n", height * 100);
    printf("      Weight = %.2f kg.\n", weight);
    printf("      BMI    = %.2f \n", bmi);
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

    if (age<18){base=20;} else{base=25;}
    printf("  Risk to have a sleep apnea disease : %.4f%% \n", ((point+OSA+ABN+MIX)/base)*100);
    if (OSA>ABN && OSA>MIX){
        printf("Have a tendency to be Obstructive Sleep Apnea Syndrome\n");
    }
    if (ABN>OSA && ABN>MIX){
        printf("Have a tendency to be Abnormal Sleep Apnea Syndrome\n");
    }
    if (MIX>ABN && MIX>OSA){
        printf("Have a tendency to be Mixed Sleep Apnea Syndrome\n");
    }
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");



    FILE *fp;
    if ((fp = fopen("C:\\Users\\PrintTrd\\Desktop\\Self-evaluation\\Risk's Self-evaluation\\file.txt", "w")) == NULL){
        printf("Cannot open file\n");
        exit(1);
    }
    fprintf(fp, "            %s", asctime (timeinfo));
    fprintf(fp, "\n          ---------  RESULT  ---------\n");
    fprintf(fp, "      Age    = %d years old.\n", age);
    fprintf(fp, "      Height = %.2f cm.\n", height * 100);
    fprintf(fp, "      Weight = %.2f kg.\n", weight);
    fprintf(fp, "      BMI    = %.2f \n", bmi);
    fprintf(fp, "\n  Risk to have a sleep apnea disease : %.4f%% \n", ((point+OSA+ABN+MIX)/base)*100);
    if (OSA>ABN && OSA>MIX){
        fprintf(fp, "Have a tendency to be Obstructive Sleep Apnea Syndrome");
    }
    if (ABN>OSA && ABN>MIX){
        fprintf(fp, "Have a tendency to be Abnormal Sleep Apnea Syndrome");
    }
    if (MIX>ABN && MIX>OSA){
        fprintf(fp, "Have a tendency to be Mixed Sleep Apnea Syndrome");
    }
    fprintf(fp, "             -----------------------             \n");

    fclose(fp);

    return 0;
}
