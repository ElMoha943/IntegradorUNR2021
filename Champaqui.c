#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//VARIABLES GLOBALES
float m[12][3];
int cont[12], dialluvia[12]; //0 vl, 1 pc, 2 ps

//SUBRUTINA Menu
void Menu(){
    printf("*******************************************************\n");
	printf("\tMediciones CERRO CHAMPAQUI 2020\n");
	printf("\tPresione la tecla adecuada para la opcion deseada\n");
	printf("\tV - Velocidad promedio del viento\n");
	printf("\tL - Mes mas lluvioso\n");
	printf("\tC - Condiciones\n");
	printf("\tP - Presion mensual\n");
    printf("\tX - Lluvia caida menor a 10mm\n");    //NUEVA OPCION EN EL MENU
	printf("\tS - Salir\n");
	printf("*******************************************************\n");
}
//SUBRUTINA Carga
void Carga(){
//VARIABLES
    int dia, ps, mes;
    float vl, pc;
    FILE *arch;
//INICIO
    arch=fopen("Champaqui2020(1).txt","r");
    while(!feof(arch)){
        fscanf(arch,"%d %d %f %f %d",&mes,&dia,&vl, &pc, &ps);
        m[mes-1][0]+=vl;
        m[mes-1][1]+=pc;
        m[mes-1][2]+=ps;
        if(pc<10) dialluvia[mes-1]++;
        cont[mes-1]++; //contador de mediciones x mes
    }
    fclose(arch);
}
//SUBRUTINA VELOCIDAD-PROM
void VELOCIDAD_PROM(int num){
//VARIABLES
	float prom[4]; //prom[0] es el total, prom[1] es el promedio del primer trimestre...
//INICIO
	prom[1] = (m[num*3-3][0]*1.0)/cont[num*3-3];
	prom[2] = (m[num*3-2][0]*1.0)/cont[num*3-2];
	prom[3] = (m[num*3-1][0]*1.0)/cont[num*3-1];
	prom[0] = ((prom[1] + prom[2] + prom[3])*1.0)/3;
	printf("El promedio del trimestre seleccionado fue: %f m/s\n",prom[0]);
	if(prom[0]<prom[1]) printf("El mes 1 fue superior al promedio con: %f m/s\n",prom[1]);
	else{
		if(prom[0]<prom[2]) printf("El mes 2 fue superior al promedio con: %f m/s\n",prom[2]);
		else
			if(prom[0]<prom[3]) printf("El mes 3 fue superior al promedio con: %f m/s\n",prom[3]);
	}
}

//SUBRUTINA MAS_LLUVIA
void MAS_LLUVIA(){
//VARIABLES
	int i, pos=0;
	float prom,max=0;
//INICIO
	for(i=0;i<=11;i++)
		prom = (m[i][1]*1.0)/cont[i];
		if(max<prom){
			max=prom;
			pos=i;
		}
	printf("El mes mas lluvioso del anio fue: %d con: %f mm\n",pos,max);
}

//SUBRUTINA CONDICIONES

void CONDICIONES(int num){ //NUMERO DE TRIMESTRE
//VARIABLES
    float prompc=0, promps=0, promvl=0;
    int i;
//INICIO
    for(i=0;i<=2;i++){
        prompc += (m[(num*3-1)-i][1]*1.0)/cont[(num*3-1)-i];
        promps += (m[(num*3-1)-i][2]*1.0)/cont[(num*3-1)-i];
        promvl += (m[(num*3-1)-i][0]*1.0)/cont[(num*3-1)-i];
    }
    prompc = (prompc*1.0)/3;
    promps = (promps*1.0)/3;
    promvl = (promvl*1.0)/3;
    printf("%f\n",prompc);
    printf("%f\n",promps);
    printf("%f\n",promvl);
    if((prompc<=4.5) && (promvl<10) && (promps>1020 && promps<1025)) printf("La condicion es MUY BUENA\n");
    else
    {
        if((prompc>4.5 && prompc<=5) && (promvl>=10 && promvl<11) && (promps>=1013 && promps<=1020)) printf("La condicion es BUENA\n");
        else printf("La condicion es MALA\n");
    }
}

//SUBRUTINA PRESIONES
void PRESIONES(){
//VARIABLES
	int i,j;
	float promps[12],min;
    FILE *arch;
//INICIO
	//calculo de promedios
	for(i=0;i<=11;i++){
		promps[i]=(m[i][2]*1.0)/cont[i];
	}
	//bubble sort
	for(i=0;i<=11;i++){
		for(j=0;j<=11;j++){
			if(promps[i]<promps[j]){
				min=promps[i];
				promps[i]=promps[j];
				promps[j]=min;
			}
		}
	}
	arch=fopen("PRESIONES.txt","w");
	for(i=0;i<=11;i++)
		fprintf(arch,"%d %f\n",i+1,promps[i]);
	fclose(arch);
	printf("Se genero el archivo PRESIONES.txt\n");
}

//ALGORITMO ChampaquiTP2C
int main(){
//VARIABLES
	int	numtrim,mesdeseado;
	char resp,opcion;
//INICIO
    Carga();
	do{
		Menu();
		scanf(" %c",&opcion);
		switch(opcion){
		case 'V':
			printf("Ingrese un numero de trimestre:\n");
			scanf("%d",&numtrim);
			while(numtrim<=0 || numtrim>=5){
				printf("Numero invalido. Ingrese un numero entre 1 y 4\n");
				scanf("%d",&numtrim);
			}
			VELOCIDAD_PROM(numtrim);
			break;
		case 'L':
			MAS_LLUVIA();
			break;
		case 'C':
			printf("Ingrese un numero de trimestre:\n");
			scanf("%d",&numtrim);
			while(numtrim<=0 || numtrim>=5){
				printf("Numero invalido. Ingrese un numero entre 1 y 4\n");
				scanf("%d",&numtrim);
			}
			CONDICIONES(numtrim);
			break;
		case 'P':
			PRESIONES();
			break;
		case 'S':
			printf("Desea salir del programa?. S para SI. N para NO\n");
			scanf(" %c",&resp);
			break;
        case 'X':// NUEVA CASO EN ESTRUCTURA SEG�N SEA
            printf("Ingrese el mes deseado:\n");
            scanf("%d",&mesdeseado);
            while(mesdeseado<=0 || mesdeseado>12){//NUEVA VALIDACION DE DATO
                printf("Usted ha ingresado un mes invalido. Por favor, ingrese nuevamente\n");
                scanf("%d",&mesdeseado);
            }
            printf("La cantidad de dia que la lluvia caida fue menor a 10mm es: %d dias\n",dialluvia[mesdeseado-1]);
            break;
        }
        getch();
        system("cls");
	}while((resp!='S'));
	getch();
    return 0;
}
