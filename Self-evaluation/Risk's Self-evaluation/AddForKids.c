#include<stdio.h>

int result_BMI(float bmi);

int main() {
	int age;
	float point=0.0;
	char answer;
	printf("Please enter your age.\n");
	scanf("%d", &age);
	if (age < 15) {
	    printf("1.Are you wet your bed at night?(y/n)\n");
	    scanf("%c\n", &answer);
	    if (answer=='y'){point++;}
	    
	    printf("2.Have you much night sweats?(y/n)\n");
	    scanf("%c\n", &answer);
	    if (answer=='y'){point++;}	    

	    printf("3.Are you breathing by mouth during the day?(y/n)\n");
        scanf("%c\n", &answer);
        if (answer=='y'){point++;}
        
	    printf("4.Do you often have a nightmare?(y/n)\n");
        scanf("%c\n", &answer);
        if (answer=='y'){point++;}        
        
	    printf("5.Are you naughty or not good at school?(y/n)\n");
        scanf("%c\n", &answer);
        if (answer=='y'){point++;}   
        
        printf("Risk to have a sleep apnea disease:  %f %%\n", (point/6)*100);
	}	
	if (age < 18) {
		printf("---------------------------------------------\n");
		printf("   You are not in criterion for check BMI.   \n");
		printf("---------------------------------------------\n");
// 		system("pause");
        return 0;
	}
	float height, weight, bmi;
	printf("Please enter your height(cm.)\n");
	scanf("%f", &height);
	printf("Please enter your weight(kg.)\n");
	scanf("%f", &weight);
	height = height / 100;
	bmi = weight / (height * height);
	printf("-------------------RESULT--------------------\n");
	printf("  Age = %d years old.\n", age);
	printf("  Height = %.2f cm.\n", height * 100);
	printf("  Weight = %.2f kg.\n", weight);
	result_BMI(bmi);
}

int result_BMI(float bmi) {
	printf("  BMI = %.2f kg.\n", bmi);
	if (bmi <= 18.5) {
		printf("  Comment :	You are underweight, you need to do more exercise and eat all 5 groups.\n");
		printf("  Risk 	  :	Malnutrition.\n");
	}
	else if (bmi > 18.5 && bmi <= 22.9) {
		printf("  Comment : 	You are normalweight.\n");
		printf("  Risk    : 	None\n");
	}
	else if (bmi > 22.9 && bmi <= 24.9) {
		printf("  Comment : 	You are overweight, please do exercise and bate greasy foods.\n");
		printf("  Risk    :	None\n");
	}
	else if (bmi > 24.9 && bmi <= 29.9) {
		printf("  Comment : 	You are pre-obese, please do exercise and avoid greasy foods.\n");
		printf("  Risk    : 	High Blood Pressure and Gestational Diabetes\n");
	}
	else if (bmi > 29.9) {
		printf("  Comment : 	You are obese, please beware for obesity and do exercise with avoid greasy foods.\n");
		printf("  Risk    : 	High Blood Pressure, Gestational Diabetes and Obesity\n");
	}
	printf("---------------------------------------------\n");
	printf("----------------BMI CRITERION----------------\n");
	printf("  BMI < 18.50		:	Underweight\n");
	printf("  BMI 16.0 - 22.9	:	Normal\n");
	printf("  BMI 23.0 - 24.9	:	Overweight\n");
	printf("  BMI 25.0 - 29.9	:	Pre-obese\n");
	printf("  BMI 30.0 - 40.0	:	Obese\n");
	printf("  BMI 40.1 - 50.0	:	Morbid-obese\n");
	printf("  BMI > 50.0		:	Super-obese\n");
	printf("---------------------------------------------\n");
// 	system("pause");
}
