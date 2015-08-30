#include <stdlib.h>                     /* Used for malloc definition */
#include <stdio.h>                                /* Used for fprintf */

int id,arrival_time,cpu_burst,priorityn;

struct processList *primero=NULL, *ultimo, *actual, *backup, * chestup, *proceso,*a,*b,*x,*p,*primero2,*ultimo2,*actual2,*primero3,*ultimo3,*actual3;

struct gantChart *primeroGC=NULL, *actualGC, *ultimoGC;

//Struct auxiliar usado para crear listas extras de apoyo para los metodos PREEMTIVE y RoundRobin
//Contiene el id (usado como intervalo de tiempo) y el proceso (id) que se ejecuta en ese intervalo
struct gantChart
{
	int id;
	int proceso;
	struct gantChart *next;
};
//Struct que tiene el id, el intervalo de tiempo, el cpu_burst, la prioridad y el enlace al sig nodo
struct processList
{
	int id;
	int arrival_time;
	int cpu_burst;
	int priority;
	struct processList *next;
};

//Metodo: insertarGantChart
//Descripción: inserta los datos que debe contener el struct gantChart
//Input: structura donde se añadiran los datos, el valor del id y el varo del proceso
void insertarGantChart(struct gantChart *gant, int id, int proceso)
{
	gant->id=id;
	gant->proceso=proceso;
}

//Metodo: insertarProceso
//Descripción: inserta los datos que debe contener el struct
//Input: structura donde se añadiran los datos
void insertarProceso(struct processList *proceso)
{
	proceso->id=id;
	proceso->arrival_time=arrival_time;
	proceso->cpu_burst=cpu_burst;
	proceso->priority=priorityn;
}

//Metodo: ad
//Descripción: agrega el nodo al principio de la lista
void ad()
{
	if(primero==NULL)
	{
		primero=(struct processList*)malloc(sizeof(struct processList));
		insertarProceso(primero);
		ultimo=primero;
		ultimo->next=NULL;
	}
	else
	{
		actual=(struct processList*)malloc(sizeof (struct processList));
		insertarProceso(actual);
		backup=primero;
		primero=actual;
		primero->next=backup;
	}
}

//Metodo: crearGantChart
//Descripción: agrega un nodo al final de la lista GantChart
//Observaciones: Metodo auxiliar para la creacion de nodos en lista GantChart
void crearGantChart(int id, int proceso)
{
	if(primeroGC==NULL)
	{
		primeroGC=(struct gantChart*)malloc(sizeof(struct gantChart));
		insertarGantChart(primeroGC,id,proceso);
		ultimoGC=primeroGC;
		ultimoGC->next=NULL;	
	}
	else
	{
		actualGC=(struct gantChart*)malloc(sizeof (struct gantChart));
		insertarGantChart(actualGC,id,proceso);
		ultimoGC->next=actualGC; //Enlace de nodos
		ultimoGC=actualGC;
		ultimoGC->next=NULL;		
	}	
	
}

//Metodo: crearProceso3
//Descripción: agrega un nodo al final de la lista numero 3
//Observaciones: Metodo auxiliar para la creacion de nodos en la lista extra de apoyo
void crearProceso3()
{
	if(primero3==NULL)
	{
		primero3=(struct processList*)malloc(sizeof(struct processList));
		insertarProceso(primero3);
		ultimo3=primero3;
		ultimo3->next=NULL;	
	}
	else
	{
		actual3=(struct processList*)malloc(sizeof (struct processList));
		insertarProceso(actual3);
		ultimo3->next=actual3; //Enlace de nodos
		ultimo3=actual3;
		ultimo3->next=NULL;		
	}	
	
}

//Metodo: crearProceso2
//Descripción: agrega un nodo al final de la lista numero 2
//Observaciones: Metodo auxiliar para la creacion de nodos en la lista extra de apoyo
void crearProceso2()
{
	if(primero2==NULL)
	{
		primero2=(struct processList*)malloc(sizeof(struct processList));
		insertarProceso(primero2);
		ultimo2=primero2;
		ultimo2->next=NULL;	
	}
	else
	{
		actual2=(struct processList*)malloc(sizeof (struct processList));
		insertarProceso(actual2);
		ultimo2->next=actual2; //Enlace de nodos
		ultimo2=actual2;
		ultimo2->next=NULL;		
	}	
	
}

//Metodo: crearProceso
//Descripción: agrega un nodo al final de la lista
void crearProceso()
{
	if(primero==NULL)
	{
		primero=(struct processList*)malloc(sizeof(struct processList));
		insertarProceso(primero);
		ultimo=primero;
		ultimo->next=NULL;	
	}
	else
	{
		actual=(struct processList*)malloc(sizeof (struct processList));
		insertarProceso(actual);
		ultimo->next=actual; //Enlace de nodos
		ultimo=actual;
		ultimo->next=NULL;		
	}	
	crearProceso2();
	crearProceso3();
}

//Metodo: OrdenarLista
//Descripción: ordena la lista de menor a mayos en base al arrival_time (la lista debe ser de sólo 5 nodos)
void OrdenarLista()
{
	p=primero;
	b=p;
	a=p->next;
	x=p->next->next;
	if(b->arrival_time>a->arrival_time)
	{
			
		b->next=x;
		a->next=b;
		primero=a;	
	}
	p=primero->next;
	b=p;
	a=p->next;
	x=p->next->next;
	if(b->arrival_time>a->arrival_time)
	{
			
		b->next=x;
		a->next=b;
		primero->next=a;	
	}
	p=primero->next->next;
	b=p;
	a=p->next;
	x=p->next->next;
	if(b->arrival_time>a->arrival_time)
	{
			
		b->next=x;
		a->next=b;
		primero->next->next=a;	
	}
	p=primero->next->next->next;
	b=p;
	a=p->next;
	x=p->next->next;
	if(b->arrival_time>a->arrival_time)
	{
			
		b->next=x;
		a->next=b;
		primero->next->next->next=a;	
	}
	
}

//Metodo: OrdenarListas
//Descripción: Version modificada de OrdenarLista, pero este puede ordenar la lista de N elementos
//Nota: No lo usa como Input pero se debe tener el metodo consultarProcesos para poder usarlo,
//esto genera que siempre se despliege la lista original que busca ser ordenada, sin contar que ordena las 3 listas
//requeridas para hacer todos los tipos de despachadores
void OrdenarListas(

	int i = consultarProcesos(1,1);
	while(i>0)
	{
		p=primero;
		b=p;
		a=p->next;
		x=p->next->next;
		if(b->arrival_time>a->arrival_time)
		{		
			b->next=x;
			a->next=b;
			primero=a;	
		}
		p=primero;
		b=p->next;
		a=b->next;
		x=a->next;
		if(b->arrival_time>a->arrival_time)
		{
				
			b->next=x;
			a->next=b;
			p->next=a;
			primero=p;
		}
		while(x!=NULL)
		{
			p=p->next;
			b=p->next;
			a=b->next;
			x=a->next;
			if(b->arrival_time>a->arrival_time)
			{				
				b->next=x;
				a->next=b;
				p->next=a;
			}			
		}
		i--;
	}
	
	i = consultarProcesos(2,0);
	while(i>0)
	{
		p=primero2;
		b=p;
		a=p->next;
		x=p->next->next;
		if(b->arrival_time>a->arrival_time)
		{		
			b->next=x;
			a->next=b;
			primero2=a;	
		}
		p=primero2;
		b=p->next;
		a=b->next;
		x=a->next;
		if(b->arrival_time>a->arrival_time)
		{
				
			b->next=x;
			a->next=b;
			p->next=a;
			primero2=p;
		}
		while(x!=NULL)
		{
			p=p->next;
			b=p->next;
			a=b->next;
			x=a->next;
			if(b->arrival_time>a->arrival_time)
			{				
				b->next=x;
				a->next=b;
				p->next=a;
			}			
		}
		i--;
	}
	
	i = consultarProcesos(3,0);
	while(i>0)
	{
		p=primero3;
		b=p;
		a=p->next;
		x=p->next->next;
		if(b->arrival_time>a->arrival_time)
		{		
			b->next=x;
			a->next=b;
			primero3=a;	
		}
		p=primero3;
		b=p->next;
		a=b->next;
		x=a->next;
		if(b->arrival_time>a->arrival_time)
		{
				
			b->next=x;
			a->next=b;
			p->next=a;
			primero3=p;
		}
		while(x!=NULL)
		{
			p=p->next;
			b=p->next;
			a=b->next;
			x=a->next;
			if(b->arrival_time>a->arrival_time)
			{				
				b->next=x;
				a->next=b;
				p->next=a;
			}			
		}
		i--;
	}
}
	int i=0;
		if(primeroGC==NULL)
		{
			printf("Lista vacia...\n");
		}
		els
	printf("|===================|\n");
	printf("|%d   |%d   |%d   |%d   |\n",proceso->id,proceso->arrival_time,proceso->cpu_burst,proceso->priority);
}
		{
			actualGC=primeroGC;
			while(actualGC!=NULL)
			{
				desplegarGantChart(actualGC);					
				actualGC=actualGC->next
	printf("%d %d \n",gant->id,gant->proceso);
}
				i++;
			}
			printf("\n");	
		}

	int i=0;
	if(primeroGC==NULL)
	{
		printf("Lista vacia...\n");
	}
	else
	{
		actualGC=primeroGC;
		while(actualGC!=NULL)
		{
			desplegarGantChart(actualGC);					
			actualGC=actualGC->next;
			i++;
		}
		printf("\n");	
	}
}
{}

//Metodo: desplegarProceso
//Descripcion: Hace una llamada al sistema para que imprima en pantalla los datos de un nodo de la lista
//Input: struct de tipo processList que se desa imprimir en pantalla
void desplegarProceso(struct processList *proceso)
{}

//Metodo: desplegarGantChart
//Descripcion: Hace una llamada al sistema para que imprima en pantalla los datos de un nodo de la lista GantChart
//Input: struct de tipo gantChart que se desa imprimir en pantalla
void desplegarGantChart(struct gantChart *gant)
{}

//Metodo: consultarGantChart
//Descripción: Junto con el metodo desplegarGantChart muestra en pantalla toda la lista de procesos
void consultarGantChart()
{}

//Metodo: consultarProcesos
//Descripción: Junto con el metodo desplegarProceso muestra en pantalla toda la lista de procesos solicitada
//Input: Entero que dice cual es la lista que desea consultarse y entero que especifica si desea desplegarse información
//en pantalla para ello este debe tener el valor de 1
//Output: variable Int que contiene el numero de procesos de la lista.
int consultarProcesos(int numeroDeLista, int desplegar)
{
	int i=0;
	switch(numeroDeLista)
	{
		case 1:
			if(desplegar==1)
			{
				printf("|===================|\n");
				printf("| Lista de procesos |\n");
				printf("|===================|\n");
				printf("| ID | AT | CB | PR |\n");
				printf("|===================|\n");
			}
				
			i=0;
			if(primero==NULL)
			{
				if(desplegar==1)
					printf("Lista vacia...\n");
			}
			else
			{
				actual=primero;
				while(actual!=NULL)
				{
					if(desplegar==1)
						desplegarProceso(actual);					
					actual=actual->next;
					i++;
				}
				if(desplegar==1)
					printf("|===================|\n\n");	
			}
			return i;
			break;
		case 2:
			if(desplegar==1)
				printf("lista 2\n");
			i=0;
			if(primero==NULL)
			{
				if(desplegar==1)
					printf("Lista vacia...\n");
			}
			else
			{
				actual=primero;
				while(actual!=NULL)
				{
					if(desplegar==1)
						desplegarProceso(actual);					
					actual=actual->next;
					i++;
				}
				if(desplegar==1)
					printf("\n");	
			}
			return i;
			break;
		case 3:
			if(desplegar==1)
				printf("lista 3\n");
			i=0;
			if(primero==NULL)
			{
				if(desplegar==1)
					printf("Lista vacia...\n");
			}
			else
			{
				actual=primero;
				while(actual!=NULL)
				{
					if(desplegar==1)
						desplegarProceso(actual);					
					actual=actual->next;
					i++;
				}
				if(desplegar==1)
					printf("\n");	
			}
			return i;
			break;
		default:
			printf("No existe ese numero de lista\n");
			break;
	}
	
}

//Metodo: FirstCome
//Descripción: Toma la lista de procesos y da el tiempo que tardaria en despachar siguiendo el algoritmo FCFS
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo FCFS
float FCFS()
{
	float awt=0;
	int i=0;//Numero de elementos en la lista
	float at;
	if(primero==NULL)
	{
		printf("Lista vacia...\n");
	}
	else
	{
		actual=primero;
		while(actual!=NULL)
		{
			at=actual->cpu_burst;	
			awt+=at;	
			actual=actual->next;
			i++;
		}
		awt-=at;
	}
	awt=awt/(float)i;
	return awt;	
	//printf("The average waiting FCFS time is %.2f\n",awt);
}

//Metodo: NonPremtiveSJF
//Descripción: Toma la lista de procesos y da el tiempo que tardaria en despachar 
//siguiendo el algoritmo Non Premtive SJF
//Input; Número de elementos de la cadena
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo NonPremtiveSJF
float NonPremtiveSJF(int k)
{
	float awt=0;
	int at=0;
	int cpuburst=0;
	int cpuburstTotal=0;
	int cpuburstactual=0;
	int cpuburstinicial=0;
	int j=0,i=1;
	actual=primero;
	cpuburstinicial=actual->cpu_burst;	
	at=actual->arrival_time;
	cpuburstinicial+=at;
	while(i<k)
	{
		j=1;
		actual=primero->next;
		cpuburstactual=0;
		while(j<=i)
		{
			if(j==i)
			{
				cpuburstactual=actual->cpu_burst;
				at=actual->arrival_time;
			}
			if(actual->next!=NULL);
				actual=actual->next;		
			j++;
		}	
		actual=primero->next;
		cpuburst=0;
		while(actual!=NULL)
		{
			if(cpuburstactual>actual->cpu_burst)
			{
				
				cpuburst+=actual->cpu_burst;
			}
			actual=actual->next;			
		}
		cpuburst+=cpuburstinicial-at;
		cpuburstTotal+=cpuburst;
		i++;
	}
	awt=(float)cpuburstTotal/(float)k;
	//printf("The average waiting NonPremtiveSJF time is %.3f\n",awt);
	return awt;
	
}

//Metodo: NonPremtivePriority
//Descripción: Toma la lista de procesos y da el tiempo que tardaria en despachar con un algortimo Non Premtive Priority
//Input; Número de elementos de la cadena
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo NonPremtivePriority
float NonPremtivePriority(int k)
{
	float awt=0;
	int priority=0;
	int at=0;
	int cpuburst=0;
	int cpuburstTotal=0;
	int cpuburstactual=0;
	int cpuburstinicial=0;
	int j=0,i=1;
	actual=primero;
	cpuburstinicial=actual->cpu_burst;
	at=actual->arrival_time;
	cpuburstinicial+=at;	
	while(i<k)
	{
		j=1;
		actual=primero->next;
		priority=0;
		while(j<=i)
		{
			if(j==i)
			{
				priority=actual->priority;
				cpuburstactual=actual->cpu_burst;
				at=actual->arrival_time;
			}
			if(actual->next!=NULL);
				actual=actual->next;		
			j++;
		}	
		actual=primero->next;
		cpuburst=0;
		while(actual!=NULL)
		{
			
			if(priority>actual->priority)
			{
				cpuburst+=actual->cpu_burst;
			}
			actual=actual->next;			
		}
		
		cpuburst+=cpuburstinicial-at;
		cpuburstTotal+=cpuburst;
		i++;
	}
	return awt=(float)cpuburstTotal/(float)k;
	//printf("The average waiting NonPremtivePriority time is %.3f\n",awt);
}

//Metodo: Premtive
//Descripción: Usando la lista GantChart creado por los metodos PremtivePriority, PremtiveSJF o RoundRobin devuelve 
//el tiempo que tardaria en dspachar dependiendo de algortinmo solicitado
//Input; Número de elementos de la cadena
float Premtive (int k, int diferencia)
{
	int cpuburst=0;
	int cpuburstTotal=0;
	int i =1;
	diferencia*=-1;
	diferencia-=1;
	while(i<=k)
	{
		int inicio=-1, final=-1,intermediarios=0, anteriores=0;
		int first, last;
		
		actualGC=primeroGC;
		while(actualGC!=NULL)
		{
			if(actualGC->proceso==i)
			{
				if((inicio==-1))
				{
					inicio=actualGC->id+diferencia;
				}
				else
				{
					if((final==-1)||(((actualGC->id+diferencia)-final)>1))
					{
						final=actualGC->id+diferencia;
					}
				}		
			}		
			actualGC=actualGC->next;
		}
		actual=primero2;
		while(actual->id!=i)
		{
			actual=actual->next;
		}
		if(final-inicio>1)
		{
			actualGC=primeroGC;
			while(actualGC!=NULL)
			{
				if(actualGC->proceso!=i)
				{
					if(inicio!=-1)
					{
						if(final!=-1)
						{
							if(actualGC->id+diferencia>inicio)
							{
								if(actualGC->id+diferencia<final)
								{
									intermediarios++;
								}                                             
							}
							else
							{
								if(actualGC->proceso>0)
									anteriores++;
							}
						}
					}
				}
				actualGC=actualGC->next;
			}
		}
		
		if(intermediarios>0)
		{
			cpuburst=intermediarios+anteriores-(actual->arrival_time);
		}
		else
		{	
			cpuburst=inicio-actual->arrival_time;
		}
		i++;
		
		cpuburstTotal+=cpuburst;
	}
	primeroGC=NULL;
	return (float)cpuburstTotal/(float)k;
	
}
//Metodo: PremtiveSJF
//Descripción: Crea una lista GantChart que con ayuda del metodo Premtive devuelve el valor 
//del tiempo que tardaria en dspachar con el algoritmo PremtiveSJF
//Input; Número de elementos de la cadena
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo PremtiveSJF
float PremtiveSJF(int k)
{
	float awt=0;
	int at=0;
	int d;
	int cpuburst=0;
	int cpuburstTotal=0;
	int cpuburstactual=0;
	int contador=0;
	int sumaDeCPUBurst=0;
	int j=0;
	actual=primero2;
	while(actual!=NULL)
	{
		sumaDeCPUBurst+=actual->cpu_burst;
		actual=actual->next;
	}	
	actual=primero2;
	if(primero2->arrival_time==0)
	{
		cpuburstactual=primero2->cpu_burst;
		contador++;
		cpuburstactual--;
		primero2->cpu_burst=cpuburstactual;
		crearGantChart(contador,primero2->id);	
	}
	else
	{
		int c=0;
		for(c=0;c<primero2->arrival_time;c++)
		{
			contador++;
			crearGantChart(contador,-1);
		}
		int d = c;
	}		
	while(contador<sumaDeCPUBurst+primero2->arrival_time)
	{
		actual=primero2;
		while(actual->next!=NULL)
		{
			if(actual->arrival_time==contador)
			{
				break;
			}
			actual=actual->next;		
		}
		if(contador==actual->arrival_time)
		{
			if(cpuburstactual>actual->cpu_burst)
			{
				cpuburstactual=actual->cpu_burst;
				contador++;
				cpuburstactual--;
				if(actual->id==primero2->id)
				{
					primero2->cpu_burst=cpuburstactual;
					cpuburstactual=	primero2->cpu_burst;
					crearGantChart(contador,primero2->id);
				}
				else
				{
					actual->cpu_burst=cpuburstactual;	
					crearGantChart(contador,actual->id);
				}
			}
			else
			{
				actual=primero2;
				if(cpuburstactual>0)
				{
					while(actual!=NULL)
					{
						if(actual->cpu_burst==cpuburstactual)
						{
							break;
						}
						else
						{
							actual=actual->next;
						}
					}	
				}
				else
				{
					int menor = primero2->cpu_burst;
					while(actual!=NULL)
					{
						if((actual->cpu_burst<menor)&&(actual->cpu_burst>0))
							menor=actual->cpu_burst;
						actual=actual->next;
					}
				}
				contador++;
				cpuburstactual--;
				if(actual->id==primero2->id)
				{
					primero2->cpu_burst=cpuburstactual;
					cpuburstactual=	primero2->cpu_burst;
					crearGantChart(contador,primero2->id);
				}
				else
				{
					actual->cpu_burst=cpuburstactual;	
					crearGantChart(contador,actual->id);
				}
				
			}
		}
		else
		{
			actual=primero2;
			if(cpuburstactual>0)
			{
				while(actual!=NULL)
				{
					if(actual->cpu_burst==cpuburstactual)
					{
						break;
					}
					else
					{
						actual=actual->next;
					}
				}		
			}
			else
			{
				cpuburstactual = primero2->cpu_burst;
				while(cpuburstactual==0)
				{
					cpuburstactual=actual->cpu_burst;
					if(actual->next!=NULL)
					{
						actual=actual->next;
					}
				}
				int x =0;
				while(x==0)
				{
					if((actual->cpu_burst<cpuburstactual)&&(actual->cpu_burst>0))
					{
						cpuburstactual=actual->cpu_burst;		
					}
					if(actual->next!=NULL)
					{
						actual=actual->next;
					}
					else
					{
	
						x=1;
					}
				}
				actual=primero2;
				x=0;
				while(x==0)
				{
					if(actual->cpu_burst==cpuburstactual)
					{
						break;
					}
					else
					{
						if(actual->next!=NULL)
						{
							actual=actual->next;
						}
						else
						{
							x=1;
						}

					}
					
				}
			}
			contador++;
			cpuburstactual--;
			if(actual->id==primero2->id)
			{
				
				primero2->cpu_burst=cpuburstactual;
				cpuburstactual=	primero2->cpu_burst;
				crearGantChart(contador,primero2->id);
			}
			else
			{
				actual->cpu_burst=cpuburstactual;	
				crearGantChart(contador,actual->id);
			}	
		}	
			
	}
	return Premtive(k,d);
	//printf("The average waiting PremtiveSJF time is %.3f\n",Premtive(k,d));		
}
	
//Metodo: PremtivepRIORITY
//Descripción: Crea una lista GantChart que con ayuda del metodo Premtive devuelve el valor 
//del tiempo que tardaria en dspachar con el algoritmo PremtivePriority
//Input; Número de elementos de la cadena
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo PremtivePriority	
float PremtivePriority(int k)
{
	float awt=0;
	int at=0;
	int d;
	int cpuburst=0;
	int cpuburstTotal=0;
	int cpuburstactual=0;
	int contador=0;
	int sumaDeCPUBurst=0;
	int priorityactual=32767;
	int j=0,i=1;
	actual=primero3;
	while(actual!=NULL)
	{
		sumaDeCPUBurst+=actual->cpu_burst;
		actual=actual->next;
	}	
	actual=primero3;
	if(primero3->arrival_time==0)
	{
		cpuburstactual=primero3->cpu_burst;
		priorityactual=primero3->priority;
		contador++;
		cpuburstactual--;
		primero3->cpu_burst=cpuburstactual;
		crearGantChart(contador,primero3->id);	
	}
	else
	{
		int c=0;
		for(c=0;c<primero3->arrival_time;c++)
		{
			contador++;
			crearGantChart(contador,-1);
		}
		d=c;
	}
			
	while(contador<sumaDeCPUBurst+primero3->arrival_time)
	{
		actual=primero3;
		while(actual->next!=NULL)
		{
			if(actual->arrival_time==contador)
			{
				break;
			}
			actual=actual->next;		
		}
		
		if(contador==actual->arrival_time)
		{
			if(priorityactual>actual->priority&&actual->cpu_burst>0)
			{
				priorityactual=actual->priority;
				cpuburstactual=actual->cpu_burst;
				contador++;
				cpuburstactual--;
				if(actual->id==primero3->id)
				{
					primero3->cpu_burst=cpuburstactual;
					cpuburstactual=	primero3->cpu_burst;
					priorityactual=primero3->priority;
					crearGantChart(contador,primero3->id);
				}
				else
				{
					actual->cpu_burst=cpuburstactual;	
					crearGantChart(contador,actual->id);
				}
			}
			else
			{
				
				actual=primero3;
				if(cpuburstactual>0)
				{
					
					while(actual!=NULL)
					{
						if(actual->cpu_burst==cpuburstactual&&priorityactual==actual->priority)
						{
							break;
						}
						actual=actual->next;
					}	
				}
				else
				{					
					int menor = primero3->priority;
					while(actual->next!=NULL)
					{
						if((actual->priority<menor)&&(actual->cpu_burst>0))
						{
							menor=actual->priority;
						}						
						actual=actual->next;
					}
					actual=primero3;
					while(actual->next!=NULL)
					{
						if(actual->priority==menor)
						{
							cpuburstactual=actual->cpu_burst;
							priorityactual=actual->priority;
							break;
						}
						actual=actual->next;
					}
				}
				contador++;
				cpuburstactual--;
				if(actual->id==primero3->id)
				{
					primero3->cpu_burst=cpuburstactual;
					cpuburstactual=	primero3->cpu_burst;
					crearGantChart(contador,primero3->id);
				}
				else
				{
					actual->cpu_burst=cpuburstactual;	
					crearGantChart(contador,actual->id);
				}
				
			}
		}
		else
		{
			actual=primero3;
			if(cpuburstactual>0)
			{
				while(actual->next!=NULL)
				{
					if(actual->cpu_burst==cpuburstactual&&priorityactual==actual->priority)
					{
						break;
					}
					actual=actual->next;
				}		
			}
			else
			{
				int x =0;
				cpuburstactual = 0;
				priorityactual=0;
				while(x==0)
				{
					if(actual->cpu_burst>0)
					{
						cpuburstactual=actual->cpu_burst;
						priorityactual=actual->priority;
						break;
					}
					if(actual->next!=NULL)
					{
						actual=actual->next;
					}
					else
					{
						x=1;
					}
				}
				x=0;
				actual=primero3;
				while(x==0)
				{
					if((actual->priority<priorityactual)&&(actual->cpu_burst>0))
					{
						priorityactual=actual->priority;
						cpuburstactual=actual->cpu_burst;	
						break;	
					}
					if(actual->next!=NULL)
					{
						actual=actual->next;
					}
					else
					{
						x=1;
					}
				}
				actual=primero3;
				x=0;
				while(x==0)
				{
					if((actual->cpu_burst==cpuburstactual)&&(actual->priority==priorityactual))
					{
						break;
					}
					if(actual->next!=NULL)
					{
						actual=actual->next;
					}
					else
					{
						x=1;
					}
				}
			}
			contador++;
			cpuburstactual--;
			if(actual->id==primero3->id)
			{
				
				primero3->cpu_burst=cpuburstactual;
				cpuburstactual=	primero3->cpu_burst;
				crearGantChart(contador,primero3->id);
			}
			else
			{
				actual->cpu_burst=cpuburstactual;	
				crearGantChart(contador,actual->id);
			}
		}				
	}
	return Premtive(k,d);
	//printf("The average waiting PremtivePriority time is %.3f\n",Premtive(k,d));
}	

//Metodo: RoundRobin
//Descripción: Crea una lista GantChart que con ayuda del metodo Premtive devuelve el valor 
//del tiempo que tardaria en despachar con el algoritmo RoundRobin
//Input; Número de elementos de la cadena y el valor del quantum
//Output: float con el valor del tiempo que tardaria en despachar con el algoritmo RoundRobin
float RoundRobin(int k, int quantum)
{
	float awt=0;
	int at=0;
	int cpuburst=0;
	int cpuburstTotal=0;
	int cpuburstactual=0;
	int contador=0;
	int sumaDeCPUBurst=0;
	int j=0,q=0,diferencia;
	int d=0;
	actual=primero;
	while(actual!=NULL)
	{
		sumaDeCPUBurst+=actual->cpu_burst;
		actual=actual->next;
	}	
	actual=primero;
	if(primero->arrival_time==0)
	{
		for(q=0;q<quantum;q++)
		{
			cpuburstactual=primero->cpu_burst;
			contador++;
			cpuburstactual--;
			primero->cpu_burst=cpuburstactual;
			crearGantChart(contador,primero3->id);
		}
		actual=actual->next;		
	}
	else
	{
		int c=0;
		for(c=0;c<primero->arrival_time;c++)
		{
			contador++;
			crearGantChart(contador,-1);
		}
		d=c;
	}		
	while(contador<sumaDeCPUBurst+primero->arrival_time)
	{	
		if(actual==NULL)
		{
			actual=primero;	
		}
		if(actual->arrival_time>contador||actual->cpu_burst<=0)
		{
			while(actual!=NULL)
			{
				if(actual->arrival_time<=contador&&actual->cpu_burst>0)
				{
					break;
				}
				actual=actual->next;
				if(actual==NULL)
				{
					actual==primero;
				}		
			}
		}
		
		if(actual->cpu_burst>=quantum)
			diferencia=quantum;
		else
			diferencia=actual->cpu_burst;
		if(actual->id==primero->id)
		{
			for(q=0;q<diferencia;q++)
			{
				cpuburstactual=primero->cpu_burst;
				contador++;
				cpuburstactual--;
				primero->cpu_burst=cpuburstactual;
				crearGantChart(contador,primero->id);
			}
		}
		else
		{
			for(q=0;q<diferencia;q++)
			{
				cpuburstactual=actual->cpu_burst;
				contador++;
				cpuburstactual--;
				actual->cpu_burst=cpuburstactual;
				crearGantChart(contador,actual->id);
			}
		}
		actual=actual->next;	
						
	}	
	return Premtive(k,d);
	//printf("The average waiting time RoundRobin is %.3f\n",Premtive(k,d));
}


//Metodo: Desplegar Ratos
//Descrpción: hace una llamada al sistema operativo para desplegar los datos final al usuario
//Input: Arreglo con los valores de tiempo que se obtuvieron de los metodos anteriores
void DesplegarResultados(float *arreglo)
{

	printf("|=================================|\n");
	printf("|Algoritmo            | Tiempo    |\n");
	printf("|=================================|\n");
	printf("|FCFS                 | %.3f     |\n",arreglo[0]);
	printf("|=================================|\n");
	printf("|NonPremtiveSJF       | %.3f     |\n",arreglo[1]);
	printf("|=================================|\n");
	printf("|NonPremtivePriority  | %.3f    |\n",arreglo[2]);
	printf("|=================================|\n");
	printf("|PremtiveSJF          | %.3f     |\n",arreglo[3]);
	printf("|=================================|\n");
	printf("|PremtivePriority     | %.3f    |\n",arreglo[4]);
	printf("|=================================|\n");
	printf("|RoundRobin           | %.3f    |\n",arreglo[5]);
	printf("|=================================|\n");
	float temporal;
	int i,j;
	for(i=2;i<=6;i++)
	{
		for(j=0;j<=6-i;j++)
		{
			if(arreglo[j]>arreglo[j+1])
			{
				temporal=arreglo[j+1];
				arreglo[j+1]=arreglo[j];
				arreglo[j]=temporal;			
			}
		}
	}
	printf("|Best one this time   | %.3f     |\n",arreglo[0]);
	printf("|=================================|\n");
	
}


int main (int argc, const char * argv[])
{
    

    int    quantum = 4;              /* Quantum value for round robin */
    //int    parameters[NUMVAL];      /* Process parameters in the line */
    id=4;
    arrival_time=3;
	cpu_burst=5;
    priorityn=5;
    crearProceso();
    id=3;
    arrival_time=2;
	cpu_burst=9;
    priorityn=0;
    crearProceso();
    id=1;
    arrival_time=0;
	cpu_burst=8;
    priorityn=1;
    crearProceso();
    id=2;
    arrival_time=1;
	cpu_burst=4;
    priorityn=3;
    crearProceso();

	OrdenarListas();	
	consultarProcesos(1,0);
	float arreglo [6] ={(float)FCFS(),(float)NonPremtiveSJF(consultarProcesos(1,0)),(float)NonPremtivePriority(consultarProcesos(1,0)),(float)PremtiveSJF(consultarProcesos(1,0)),(float)PremtivePriority(consultarProcesos(1,0)),(float)RoundRobin(consultarProcesos(1,0),quantum)};	
	DesplegarResultados(arreglo);
    printf("Program terminated correclty\n");
    return (EXIT_SUCCESS);
}

										   

		

