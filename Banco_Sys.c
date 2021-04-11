#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <malloc.h>


#define	MOSTRAR_MENU_PRIN			0
#define	LIMITE_PAISES				5
#define	LIMITE_CLIENTES				10
#define	ALTA						1
#define	BAJA						2
#define	MOSTRAR_TODO				3
#define	MOSTRAR_ESPECIFICO			4
#define	MOSTRAR_OCUPADOS			5
#define	ABONAR						6
#define	RETIRAR						7
#define	BUSCAR_ID_VACIO_ESTRUCTURA	8
#define	ESTA_LLENA_ESTRUCTURA		9
#define	ESTA_VACIA_ESTRUCTURA		10
#define	IMPRIMIR_NOM_PAISES			11
#define	MOSTRAR_LONGITUDES			12
#define	ACTUALIZAR					13
#define	SALIR						14
#define	ACTUALIZAR_MOSTRAR_MENU		0
#define	ACTUALIZAR_NOMBRE			1
#define	ACTUALIZAR_SEXO				2
#define	SALIR_ACTUALIZAR			3


typedef struct {
	char nombre[20];
	char sexo;
	double saldo;
	bool ocupado;
}Cliente;

typedef struct {
	char nombrePais[20];
	int num_clientes;
	Cliente clientes[];
}Banco;


void instrucciones(){
        printf("\n-------------------------------");
        printf("---- Menu ----\n");
        printf(" 0 Mostrar menu.\n");
        printf(" 1 Dar de alta Cliente.\n");
        printf(" 2 Dar de baja Cliente.\n");
        printf(" 3 Mostrar todos los clientes.\n");
        printf(" 4 Mostrar cliente en especifico.\n");
        printf(" 5 Mostrar solo clientes dados de alta.\n");
        printf(" 6 Abonar saldo a cliente.\n");
        printf(" 7 Retirar saldo de cliente.\n");
        printf(" 8 Buscar indice vacio en toda la estructura.\n");
        printf(" 9 Mostrar si esta toda llena la estructura.\n");
        printf(" 10 Mostrar si esta toda vacia la estructura.\n");
        printf(" 11 Mostrar nombre de paises.\n");
        printf(" 12 Mostrar longitudes.\n");
        printf(" 13 Actualizar datos de cliente especifico.\n");
        printf(" 14 Salir.\n");
        printf("-------------------------------");
}
    
void saltoLinea(){
        printf("\n");
}

int validarRango(int inicio, int fin, char mensaje[100]){
    puts(mensaje);
	int numero;
	scanf("%d",&numero);
    while(numero < inicio || numero > fin){
        if(numero < inicio || numero > fin){
            printf("\t\tNo esta dentro del Rango...\n");
            printf("\t\t\t--> El rango va de %d a % d\n",inicio,fin);
        }
        puts(mensaje);
        scanf("%d",&numero);
    }
    return numero;
}

bool estaNombreRepetido(int inicio, char nombrePais[20], Banco banco[]){
        bool se_encuentra = false;
        int i;
        for(i = inicio; i > 0; i--){
        	if(strcasecmp(banco[i-1].nombrePais,nombrePais)==0){
                se_encuentra = true;
                break;
            }
        }
        return se_encuentra;
    }

void introducirPaises(Banco banco[], int tam_banco){
	int i;
	int tam_cliente;
    for(i = 0; i < tam_banco; i++){
    	printf("Introduce el nombre del País [%d]    ",i);
    	char *mensaje;//="Introduce el nombre del País [%d]",i;
        char nombrePais[20];
        fflush(stdin);
        fgets(nombrePais,20,stdin);
        int inicio=i;
        while(estaNombreRepetido(inicio, nombrePais, banco)){//mientras exista
            if(estaNombreRepetido(inicio, nombrePais, banco)){
                printf("\t\tEl nombre %s ya se encuentra registrado...\n",nombrePais);
                printf("\t\t\t--> Intenta de nuevo.\n");
            }
            printf("Introduce el nombre del País [%d]    ",i);
        	fflush(stdin);
        	fgets(nombrePais,20,stdin);
        }
        mensaje= "\tIntroduce el total de clientes del pais %s :  ",nombrePais;
        strcpy(banco[i].nombrePais,nombrePais);
        tam_cliente=validarRango(1, LIMITE_CLIENTES, mensaje);
        banco[i].clientes[tam_cliente];
        banco[i].num_clientes=tam_cliente;
    }
    
} 
 
int getTotalClientes(Banco banco[], int posicion){
    return banco[posicion].num_clientes;
}
 
bool getIsOcupadoCliente(Banco banco[],int indice_pais,int index){
        bool ocupado=false;
        if(banco[indice_pais].clientes[index].ocupado != true){
        	ocupado=false;
		}else{
			ocupado=true;
		}
		return ocupado;
    } 
	
bool isTodoOcupado(Banco banco[], int indice_pais){
	bool todo_ocupado = false;
    int contador = 0;
    int i;
    for(i = 0; i < getTotalClientes(banco, indice_pais) ; i++){
    	if(getIsOcupadoCliente(banco,indice_pais,i)){
            contador++;
        }
    }
    if(contador ==getTotalClientes(banco,indice_pais)){	
    	todo_ocupado = true;
    }
    return todo_ocupado;
}

bool hayVacioTodaEstructura(Banco banco[], int tam_banco){
	bool hayLugar = false;
    //for(Banco item : banco) {
    int j;
    for(j=0;j<tam_banco;j++){
            //if(banco[i].existeEspacioVacio()) { // funciona también.
            if (isTodoOcupado(banco,j)==false) {
                hayLugar = true;
                break;
            }
        }
        return hayLugar;
    }

void mostrarLongitudes(Banco banco[],int tam_banco){
	int i;
	for(i=0;i<tam_banco;i++){
		printf("--> Del Pais %s ------existen %d clientes.\n",banco[i].nombrePais,banco[i].num_clientes);
	}
	
}
/*bool seEncuentraNombre(char nombrePais[20], Banco banco[], int tam_banco){
        bool se_encuntra = false;
        int i;
        for (i=0;i<tam_banco;i++) {
        	if(strcasecmp(banco[i].nombrePais,nombrePais)){
            //if (item.getNombrePais().equalsIgnoreCase(nombrePais)) {
            	se_encuntra = true;
            }
        }
        return se_encuntra;
    }*/

/*char* pedirNombrePais(char mensaje[100], Banco banco[], int tam_banco){
		puts(mensaje);
        char *nombrePais;
        fflush(stdin);
		gets(nombrePais);
        while(!seEncuentraNombre(nombrePais, banco, tam_banco)){
            if(!seEncuentraNombre(nombrePais, banco, tam_banco)){
                printf("\t\tEl nombre %s no se encuentra registrado...\n",nombrePais);
                printf("\t\t\t--> Intenta de nuevo.");
            }
            puts(mensaje);
            fflush(stdin);
			gets(nombrePais);
			
        }
        nombrePais=(char*)malloc(sizeof(char));
        //return (char*)nombrePais;
        return nombrePais;
    }*/

char* getNombrePais(Banco banco[], int posicion) {
        char* nombrePais;
        strcpy(nombrePais,banco[posicion].nombrePais); 	
        nombrePais=(char*)malloc(sizeof(char));
		return nombrePais;
    }

int getIndicePais(char nombrePais[20], Banco banco[], int tam_banco){
        int indexPais = -1;
        int i;
        for(i = 0; i < tam_banco; i++){
            //if(banco[i].getNombrePais().equalsIgnoreCase(nombrePais)){
                indexPais = i;
                break;
            //}
        }
        return indexPais;
    }
    
int indiceVacio(Banco banco[], int pais){
    int index_vacio = -1;
    int i;
    for(i = 0; i < getTotalClientes(banco,pais) ; i++){
        if(getIsOcupadoCliente(banco,pais,i)==false){ 
        	index_vacio = i;
        	break;
        }
    }
    return index_vacio;
}

int indiceVacioPaisEspecifico(int pais, Banco banco[]){
		int index_vacio;
		index_vacio=indiceVacio(banco, pais);
        return index_vacio;
    }

int main(){
	int eleccion;
	//char mensaje=
	int tam_banco;
	tam_banco=validarRango(1,LIMITE_PAISES,"Introduce el número de paises: ");
	Banco banco[tam_banco];
	introducirPaises(banco, tam_banco);
	//int l;for(l=0;l<tam_banco;l++){ puts(banco[l].nombrePais); } //Revision de llenado nombrePais
	mostrarLongitudes(banco,tam_banco);
	saltoLinea();
	instrucciones();
	printf("\n Elija una opción: ");
	scanf("%d",&eleccion);
	while(eleccion != SALIR){
            switch(eleccion){
                case ALTA:
                    printf(" --- Opción alta ---\n");
                    
                    if(hayVacioTodaEstructura(banco, tam_banco)==true){
                        char nombre_pais[20];
                        //PEDIRNOMBREPAIS
                       // printf("\tIntroduce el nombre del pais: ");        				
        				//fflush(stdin);
						//gets(nombre_pais);						
						//bool seEncuentraNombre(char nombrePais[20], Banco banco[], int tam_banco){
						bool se_encuentra = 0;
						do{	
							printf("\tIntroduce el nombre del pais: ");  
            				fflush(stdin);
							//gets(nombre_pais);											
							fgets(nombre_pais,20,stdin);
        					int i;
        					for (i=0;i<tam_banco;i++) {
	        					if(strcasecmp(banco[i].nombrePais,nombre_pais)==0){
	        						//printf("%s\n",banco[i].nombrePais);
	            					se_encuentra = true;
	            				}
        					}
        					if(se_encuentra==false){
                				printf("\t\tEl nombre %s no se encuentra registrado...\n",nombre_pais);
                				printf("\t\t\t--> Intenta de nuevo.\n");
            				}
            												
						}while(se_encuentra==false);        				        			
                        int id_pais;
						id_pais = getIndicePais(nombre_pais, banco, tam_banco);
                        //printf("%d id pais\n ",id_pais);//verificar indice
						int cliente;
						cliente= indiceVacioPaisEspecifico(id_pais, banco);
						printf("%d ",cliente);//verificar indice
                        if(cliente != -1){
                        	char nombre_cliente[20];
                        	char sexo;
                        	double saldo;
                        	printf("Introduce nombre del cliente: ");
                        	fflush(stdin);                        	
                        	fgets(nombre_cliente,20,stdin);
                        	printf("\nIntroduce el Sexo: ");
                        	fflush(stdin);
                        	scanf("%c",&sexo);
                        	printf("\nIntroduce el Sueldo: ");
                        	scanf("%d",&saldo);
                            //llenar datos
                            strcpy(banco[id_pais].clientes[cliente].nombre,nombre_cliente);
                            banco[id_pais].clientes[cliente].sexo=sexo;
                            banco[id_pais].clientes[cliente].saldo=saldo;
                            banco[id_pais].clientes[cliente].ocupado=true;
                        }
                        else
                            printf("No existe indice vacio en el pais %s",banco[id_pais].nombrePais);
                    }
                    else {
                        printf("---------------------------------------------------------------------");
                        printf("\t\t La estructura esta completamente llena.");
                        printf("---------------------------------------------------------------------");
                    }
                    break;
                    
                    
            }
    }
	
	return 0;
}


