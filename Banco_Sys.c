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
                //break;
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
               // break;
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

int getIndicePais(char nombrePais[20], Banco banco[], int tam_banco){
        int indexPais = -1;
        int i;
        for(i = 0; i < tam_banco; i++){
        //	if(strcasecmp(banco[i].nombrePais,nombrePais)){
        		indexPais = i;
		//	}
            //if(banco[i].getNombrePais().equalsIgnoreCase(nombrePais)){
                
               // break;
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
    
bool existeEspacioOcupado(Banco banco[], int pais){
    bool existeOcupado = false;
    int i;
    for(i = 0; i < getTotalClientes(banco, pais); i++){
            if(getIsOcupadoCliente(banco,pais,i)==true){
                existeOcupado = true;
                break;
            }
        }
        return existeOcupado;
    }
    
bool estaTodoVacioEstructura(Banco banco[], int tam_banco){
        bool all_vacio = true;
        int i;
        for (i=0; i<tam_banco;i++) {
            if (existeEspacioOcupado(banco,i)==true) {
                all_vacio = false;
                break;
            }
        }
        return all_vacio;
    }

void eliminarCliente(Banco banco[],int pais,int index){
	strcpy(banco[pais].clientes[index].nombre," ");
	banco[pais].clientes[index].sexo=' ';
	banco[pais].clientes[index].saldo=0.0;
	banco[pais].clientes[index].ocupado=false;
}
   
void imprimirTodo(Banco banco[], int tam_banco){
	int i;
    for(i = 0; i < tam_banco; i++){
    	int j;
		for(j=0;j<getTotalClientes(banco, i);j++){
			printf("----------------------------------------------------------------------------------------------------------------");
        	printf("\n\t---->Del pais %s",banco[i].nombrePais);
            printf("\n\t\tCliente[%i]",j);
            printf("\n\t\t\tNombre: %s",banco[i].clientes[j].nombre);
            printf("\n\t\t\tSexo: %c",banco[i].clientes[j].sexo);
            printf("\n\t\t\tSaldo: %s",banco[i].clientes[j].saldo);
		}            
    }
    printf("----------------------------------------------------------------------------------------------------------------");
}

void imprimirEspecifico(Banco banco[],int pais,int cliente){
    printf("----------------------------------------------------------------------------------------------------------------");
    printf("\n\t---->Del pais %s: ",banco[pais].nombrePais);
    printf("\n\t\t\tNombre: %s",banco[pais].clientes[cliente].nombre);
    printf("\n\t\t\tSexo: %c",banco[pais].clientes[cliente].sexo);
    printf("\n\t\t\tSaldo: %s",banco[pais].clientes[cliente].saldo);
    printf("----------------------------------------------------------------------------------------------------------------");
}
    
bool printSoloOcupados(Banco banco[],int pais){
    bool imprimio = false;
    if(existeEspacioOcupado(banco, pais)==true){
        imprimio = true;
        printf("----------------------------------------------------------------------------------------------------------------");
        printf("\tDel pais [%s] los clientes disponibles son:",banco[pais].nombrePais);
        int i;
        for(i = 0; i < getTotalClientes(banco,pais); i++){
                if(getIsOcupadoCliente(banco,pais,i)){
                    printf("El cliente %d es: ",i);
                    printf("\n\t\t\tNombre: %s",banco[pais].clientes[i].nombre);
    				printf("\n\t\t\tSexo: %c",banco[pais].clientes[i].sexo);
    				printf("\n\t\t\tSaldo: %s",banco[pais].clientes[i].saldo);
                }
            }
            printf("----------------------------------------------------------------------------------------------------------------");
        }
        return imprimio;
}

void imprimirSoloOcupados(Banco banco[], int tam_banco){
        int contador = 0;
        int i;
        for(i = 0; i < tam_banco; i++){
            if(printSoloOcupados(banco,i))
                contador++;
        }
        if(contador == 0){
            printf("\t\t ---> No existen clientes que mostrar...");
        }
    }
    
bool tieneDatos(Banco banco[], int pais, int indice){
	bool tiene_Datos=false;	
	if(strcasecmp(banco[pais].clientes[indice].nombre," ")==0 ||
		banco[pais].clientes[indice].sexo==' '){	
			tiene_Datos=false;
    }else{
    	tiene_Datos=true;    	 
	}
	return tiene_Datos;           
}

void abonarSaldo(Banco banco[], int pais, int indice ,double cuanto){
    if(tieneDatos(banco, pais,indice)==true) {
        if(cuanto > 0.0){
        	banco[pais].clientes[indice].saldo=banco[pais].clientes[indice].saldo+cuanto;
        }
        else{
            printf("\tImposible, no puedes abonar saldos negativos o nada.");
        }
    }
}

void abonarSaldoCliente(Banco banco[], int pais, int index, double cuanto){
		abonarSaldo(banco,pais,index,cuanto);
}

bool tieneSaldo(Banco banco[], int pais, int indice){
	bool tiene_Saldo=false;
	if(banco[pais].clientes[indice].saldo > 0.0){
		tiene_Saldo=true;
	}else{
		tiene_Saldo=false;
	}
        return tiene_Saldo;
}

void retirarSaldo(Banco banco[], int pais, int indice,double cuanto){
    if(tieneDatos(banco, pais,indice)==true) {
        if(cuanto > 0.0){
                if(tieneSaldo(banco, pais, indice)==true){
                    if(banco[pais].clientes[indice].saldo >= cuanto){
                        banco[pais].clientes[indice].saldo= banco[pais].clientes[indice].saldo-cuanto;
                    }else{					
                        printf("\tImposible, tú saldo es insuficiente para retirar %f",cuanto);
                	}
                }
                else{				
                    printf("\tImposible, no hay saldo.");
            	}
            }
        else{		
            printf("\tImposible, no puedes retirar saldos negativos o nada.");
        }
    }
}

void retirarSaldoCliente(Banco banco[], int pais, int index, double cuanto){
        retirarSaldo(banco, pais, index, cuanto);
}

typedef struct {
	int pais;
	int cliente;
}Indices;
						    
Indices indiceVacioTodaEstructura(Banco banco[],int tam_banco) {
	Indices temp;//new Indices();
	temp.pais=-1;
	temp.cliente=-1;
	int i;
	for(i = 0; i < tam_banco; i++) {
		int indice;
		indice = indiceVacio(banco, i);
		if(indice != -1) {
			temp.pais = i;
            temp.cliente = indice;
			break;            					
		}
	}
	return temp;
}

bool existeEspacioVacio(Banco banco[], int pais){
    bool existeVacio = false;
    int i;
    for(i = 0; i < banco[pais].num_clientes ; i++){
            if(getIsOcupadoCliente(banco,pais, i)==true){
                existeVacio = true; 
                break;
            }
        }
        return existeVacio;
    }

bool estaTodoLlenoEstructura(Banco banco[], int tam_banco){
    bool all_lleno = true;
    int i;
    for (i=0;i<tam_banco;i++) {
        if (existeEspacioVacio(banco,i)==true) {
                all_lleno = false;
                break;
            }
        }
        return all_lleno;
}

 void imprimirPaises(Banco banco[], int tam_banco){
        printf("---------------------------------------------------------------------\n");
        printf("\tLos paises son: \n");
        int i;
        for(i = 0; i < tam_banco; i++){
            printf("\t---->País [%s] ",banco[i].nombrePais);
        }
        printf("---------------------------------------------------------------------\n");
}

void instrucciones_actualizar(){
        printf("\n-------------------------------");
        printf("---- Menú Actualizar ----\n");
        printf(" 0 Mostrar menú.\n");
        printf(" 1 Actualizar Nombre.\n");
        printf(" 2 Actualizar Sexo.\n");
        printf(" 3 Regresar a ménu principal.\n");
        printf("-------------------------------");
    }

void setTodosDatos(Banco banco[],int pais, int indice){	
    strcpy(banco[pais].clientes[indice].nombre, " ");
    banco[pais].clientes[indice].sexo = ' ';
    banco[pais].clientes[indice].saldo = 0.0;
    banco[pais].clientes[indice].ocupado = false;
}

void setOcupado(Banco banco[], int pais, int indice) {
    if(tieneDatos(banco, pais,indice)==false){
        setTodosDatos(banco, pais, indice);
    }
    else{
        banco[pais].clientes[indice].ocupado = true;
    }
}

void cambiarNombre(Banco banco[], int pais, int indice, char nuevoNombre[20]){
	/*Si primer cadena > a segunda resultado es mayor a 0
		Si primer cadena > a segunda resultado es menor a 0
			Si cadenas iguales resultado 0*/
	if(strcasecmp(nuevoNombre," ")>0){	        
            strcpy(banco[pais].clientes[indice].nombre,nuevoNombre);
        }
    setOcupado(banco, pais, indice);
}

void cambiarNombreCliente(Banco banco[], int pais, int index, char nuevoNombre[20]){
        cambiarNombre(banco,pais, index,nuevoNombre);
    }

void printCliente(Banco banco[], int pais,int index){
    printf("-->Nombre: %s\n",banco[pais].clientes[index].nombre);
    printf("-->Sexo: %c\n",banco[pais].clientes[index].sexo);
    printf("-->Saldo: %f\n",banco[pais].clientes[index].saldo);
}

void cambiarSexo(Banco banco[], int pais, int indice, char sexo){
    if(sexo == 'M' || sexo == 'F'){
        banco[pais].clientes[indice].sexo = sexo;
    }
    setOcupado(banco, pais, indice);
}

void cambiarSexoCliente(Banco banco[], int pais, int index, char nuevoSexo){
    cambiarSexo(banco, pais, index, nuevoSexo);
}

int main(){
	int eleccion;
	int tam_banco;
	tam_banco=validarRango(1,LIMITE_PAISES,"Introduce el número de paises: ");
	Banco banco[tam_banco];
	introducirPaises(banco, tam_banco);
	//int l;for(l=0;l<tam_banco;l++){ puts(banco[l].nombrePais); } //Revision de llenado nombrePais
	mostrarLongitudes(banco,tam_banco);
	saltoLinea();
	instrucciones();
	printf("\n Elija una opcion: ");
	scanf("%d",&eleccion);
	while(eleccion != SALIR){
            switch(eleccion){
                case ALTA:
                	/*printf(" ");
                	int op=1;
                	do{*/
                		printf(" --- Opcion alta ---\n");                    
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
                        	printf("---------------------------------------------------------------------\n");
                        	printf("\t\t La estructura esta completamente llena.\n");
                        	printf("---------------------------------------------------------------------\n");
                        	//op=2;
                    	}
                    	/*if(op==1){
                			printf("\n\t Desea dar de alta a otro cliente");
                			printf("\n\t1.-Si\t2.-No\t");
                			scanf("%d",&op);
                		}
					}while(op==1); */                   
                break;
                case BAJA:
                    printf(" --- Opción baja ---\n");                    
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){
                        char nombre_pais[20];					
						//PEDIRNOMBREPAIS                       
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
                        int pais;
						pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente;
						cliente =validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            printf("\t--> Cliente %s  dado de baja.",banco[pais].clientes[cliente].nombre);
                            eliminarCliente(banco,pais,cliente);
                        }
                        else
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case MOSTRAR_TODO:
                    printf(" --- Opción mostrar todo ---\n");
                    imprimirTodo(banco,tam_banco);
                break;
                case MOSTRAR_ESPECIFICO:
                    printf(" --- Opción mostrar especifico ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                        char nombre_pais[20];
                        //PEDIRNOMBREPAIS                       
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
                        int pais;
						pais= getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente;
						cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            imprimirEspecifico(banco,pais,cliente);
                        }
                        else
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case MOSTRAR_OCUPADOS:
                    printf(" --- Opción mostrar solo ocupados ---\n");
                    imprimirSoloOcupados(banco, tam_banco);
                break;
                case ABONAR:
                    printf(" --- Opción abonar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                   
                        char nombre_pais[20];
                        //PEDIRNOMBREPAIS                       
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
                        int pais;
						pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente;                        
						cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){
                            double cuanto;
                            printf("\tIntroduce cuanto ingresarás a tú cuenta:  ");
							scanf("%f",&cuanto);
                            abonarSaldoCliente(banco, pais,cliente, cuanto);
                        }
                        else{
                        	printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
						}                                
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break; 
                case RETIRAR:
                    printf(" --- Opción retirar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                        char nombre_pais[20];
                        //PEDIRNOMBREPAIS                       
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
                        int pais;
						pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente;                        
						cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");                           						                        				                        
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){												
                            double cuanto;
							printf("\tIntroduce cuanto retirarás de tú cuenta: ");
							scanf("%d",&cuanto); 
                            retirarSaldoCliente(banco, pais, cliente, cuanto);
                        }
                        else
                            printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case BUSCAR_ID_VACIO_ESTRUCTURA:
                    printf(" --- Opción buscar id vacio en toda estructura ---\n");
                    if(hayVacioTodaEstructura(banco, tam_banco)==true){																							                    
                        Indices temp;
						temp = indiceVacioTodaEstructura(banco, tam_banco);
                        printf("---------------------------------------------------------------------\n");
                        printf("\tEl pais [%d] %s tiene el cliente [%d] vacio\n",temp.pais, banco[temp.pais].nombrePais, temp.cliente);
                        printf("---------------------------------------------------------------------\n");
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta completamente llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case ESTA_LLENA_ESTRUCTURA:
                    printf(" --- Opción esta llena toda la estructura ---\n");
                    if(estaTodoLlenoEstructura(banco, tam_banco)==true) {
                        printf("---------------------------------------------------------------------\n");
                        printf("\ttrue, la estructura esta toda llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\tfalse, la estructura no esta toda llena.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case ESTA_VACIA_ESTRUCTURA:
                    printf(" --- Opción esta vacia toda la estructura ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){
                        printf("---------------------------------------------------------------------\n");
                        printf("\ttrue, la estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\tfalse, la estructura no esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                break;
                case IMPRIMIR_NOM_PAISES:
                    printf(" --- Opción imprimir nombre de paises ---\n");
                    imprimirPaises(banco, tam_banco);
                break;
				case ACTUALIZAR:
                    printf(" --- Opción actualizar ---\n");
                    if(estaTodoVacioEstructura(banco, tam_banco)==false){                    
                        char nombre_pais[20];
						//PEDIRNOMBREPAIS                       
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
                        int pais;
						pais = getIndicePais(nombre_pais, banco, tam_banco);
                        int cliente;                        
						cliente = validarRango(0, getTotalClientes(banco,pais)-1, "\tIntroduce el indice del cliente: ");                           						                        				                        
                        if(getIsOcupadoCliente(banco,pais,cliente)==true){ 						                       	                                                                   
                            instrucciones_actualizar();
                            printf(" Elija una opción: ");
                            scanf("%d",&eleccion);                            
                            while(eleccion != SALIR_ACTUALIZAR) {
                                switch (eleccion) {
                                    case ACTUALIZAR_NOMBRE:
                                        printf(" --- Opción actualizar nombre ---\n");                                        
                                        char nuevoNombre[20];
										printf("Introduce nuevo nombre del cliente: ");
										fflush(stdin);
										fgets(nuevoNombre,20,stdin);
                                        cambiarNombreCliente(banco,pais,cliente,nuevoNombre);
                                        printf("-----------------------------------------------------------------\n");
                                        printCliente(banco, pais,cliente);
                                        printf("-----------------------------------------------------------------\n");
                                        break;
                                    case ACTUALIZAR_SEXO:
                                        printf(" --- Opción actualizar sexo ---\n");
                                        char nuevoSexo;                                        
                                        printf("Introduce el nuevo Sexo: ");
                                        fflush(stdin);
										scanf("%c",nuevoSexo);
										cambiarSexoCliente(banco,pais,cliente,nuevoSexo);
                                        printf("-----------------------------------------------------------------\n");
                                        printCliente(banco, pais,cliente);
                                        printf("-----------------------------------------------------------------\n");
                                        break;
                                    case ACTUALIZAR_MOSTRAR_MENU:
                                        instrucciones_actualizar();
                                        break;
                                    default:
                                        printf("******************************************\n");
                                        printf(" --- Opción Desconocida ---\n");
                                        printf("******************************************\n");                                        
                                        instrucciones_actualizar();
                                }
                                printf(" Elija una opción: ");
                                scanf("%d",&eleccion);                                
                            }
                            instrucciones();
                        }
                        else{
                        	printf("\tEl cliente %i del pais %s  no tiene datos.",cliente,banco[pais].nombrePais);
						}                            
                    }
                    else {
                        printf("---------------------------------------------------------------------\n");
                        printf("\t\t La estructura esta toda vacia.\n");
                        printf("---------------------------------------------------------------------\n");
                    }
                    break;
                case MOSTRAR_LONGITUDES:
                    printf(" --- Opción mostrar longitudes ---\n");
                    printf("---------------------------------------------------------------------\n");
                    mostrarLongitudes(banco,tam_banco);
                    printf("---------------------------------------------------------------------\n");
                break;
				case MOSTRAR_MENU_PRIN:
                    instrucciones();
                break;
				default:
                    printf("******************************************\n");
                    printf(" --- Opción Desconocida ---\n");
                    printf("******************************************\n");                    
                    instrucciones();				                 
            }
        printf(" Elija una opción: ");
        scanf("%d",&eleccion);    
    }
    printf("--- Fin de la Ejecución del Sistema ---\n");	
	return 0;
}    

