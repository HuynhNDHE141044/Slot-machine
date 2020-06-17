#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

int random(){
	int n = rand()%10;
	return n;
}
int calulatemoney(double &money){
	srand(time(NULL));
	int a= random();
	int b=random();
	int c=random();
	printf("The slot machine shows %d%d%d\n", a,b,c);
	if(a==b&&a==c){
		printf("You win the big prize, $10.00!\n");
		money = money + 9.75;
	}else{
		if(a!=b&&a!=c&b!=c){
			printf("Sorry you don't win anything\n");
			money = money - 0.25;
		}else{
			printf("You win 50 cents!\n");
			money = money+0.25;
		}
	}
	return money-0.25;
}
void save(double &money){
	FILE *save;
	save = fopen("save.txt","w");
	fprintf(save,"%0.2lf",money);
	fclose(save);
}
void display(double &money){
	printf("You have $%0.2lf\n", money);
}
void playgame(double n){
	int choice;
	char m;
	
	do {
	    if (choice != 2){
		    display(n);
	        printf("1. Play the slot machine\n");
	        printf("2. Save game\n");
	        printf("3. Cash out\n");
	        printf("Your choice(1-3): ");
	        scanf("%d%c", &choice, &m);
	    }
	    if (choice == 1){
		    calulatemoney(n);
		}else{
		    if (choice == 2){
		        save(n);
		        printf("Your money had saved!\n");
		        break;
	        }else{
			    if (choice == 3){
		        printf("Thank you for playing! You end with $%.02lf\n", n);
	        }else{
			    if (choice > 3)
		        printf ("Invalid choice, choose again!\n");
		    }
		}
	}
	
	} while (choice != 4||choice<0);
}

int main(){
	double money = 10.00;
	playgame(money);
}

