/*
 * Copyright (c) 2012 Abelardo Lopez Lagunas
 * 
 * Program: scheduler.c
 *
 * Author:  Abelardo Lopez Lagunas
 *
 * Purpose: This program impelemnets the basic process scheduling
 *          algorithms for the TC2008 class. 
 *
 * Usage:
 *          The program reads a text file with the processes. The first
 *          integer in the file is the quantum, followed by four integer
 *          numbers per line describing the process id, arrival time, 
 *          cpu burst and priority. The usage form is:
 *
 *          schedule file.txt
 *
 * References:
 *          The material that describe the scheduling algorithms is
 *          covered in my class notes for TC2008
 *
 * File formats:
 *          The input file should have four numbers per list in ASCII
 *          format. The exeption is teh forst line which only has one
 *          integer number that represents the quantum.
 *
 * Restrictions:
 *          If the input file is not in ASCII format the program exits
 *
 * Revision history:
 *
 *          Feb 16 11:57 2011 - File created
 *          
 *          May 24 11:56 2012 - Code refactoring & big fixes
 *
 * Error handling:
 *          On any unrecoverable error, the program exits
 *
 * Notes:
 *          This code presents a solution for the first assignment
 *
 * $Id$
 */

#include <stdlib.h>                     /* Used for malloc definition */
#include <stdio.h>                                /* Used for fprintf */
#include <string.h>                                /* Used for strcmp */
#include <assert.h>                      /* Used for the assert macro */
#include "FileIO.h"    /* Definition of file access support functions */
//#include "dispatcher.h"/* Implementation of the dispatcher algorithms */

/***********************************************************************
 *                       Global constant values                        *
 **********************************************************************/
#define NUMPARAMS 2
#define NUMVAL    4

/***********************************************************************
 *                          Main entry point                           *
 **********************************************************************/


int id,arrival_time,cpu_burst,priority;

int arregloDeArrival_TimeDeProcesos[5];

struct processList *primero, *ultimo, *actual, *backup, * chestup, *proceso;

struct processList *primeroOrdenado, *ultimoOrdenado, *actualOrdenado;

struct processList
{
	int id;
	int arrival_time;
	int cpu_burst;
	int priority;
	struct processList *next;
};


void AlgoritmoDeOrdenamientoPorInserccion()
{
	int i=1,j,contador,valor;
	int a=5;
	for(j=1; j<=a-1;j++)
	{
		valor=arregloDeArrival_TimeDeProcesos[j];
		i=j-1;
		while(i>-1&&valor<arregloDeArrival_TimeDeProcesos[i])
		{
			arregloDeArrival_TimeDeProcesos[i+1]=arregloDeArrival_TimeDeProcesos[i];
			arregloDeArrival_TimeDeProcesos[i]=valor;
			i=i-1;
		}		
	}
}


void insertarProceso(struct processList *proceso)
{
	proceso->id=id;
	proceso->arrival_time=arrival_time;
	proceso->cpu_burst=cpu_burst;
	proceso->priority=priority;
}



void crearProceso(int orden)
{
	if (1==orden)
	{
		if(primeroOrdenado==NULL)
		{
			primeroOrdenado=(struct processList*)malloc(sizeof(struct processList));
			insertarProceso(primeroOrdenado);
			ultimoOrdenado=primeroOrdenado;
			ultimoOrdenado->next=NULL;	
		}
		else
		{
			actualOrdenado=(struct processList*)malloc(sizeof (struct processList));
			insertarProceso(actualOrdenado);
			ultimoOrdenado->next=actualOrdenado; //Enlace de nodos
			ultimoOrdenado=actualOrdenado;
			ultimoOrdenado->next=NULL;		
		}
	}
	else
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
	}
	
	
}




void desplegarProceso(struct processList *proceso)
{
	printf("%d %d %d %d ",proceso->id,proceso->arrival_time,proceso->cpu_burst,proceso->priority);
}


void obtenerArrival_Time(struct processList *proceso,int numeroDeProceso)
{
	arregloDeArrival_TimeDeProcesos[numeroDeProceso]=proceso->arrival_time;
}

void consultarProcesos(int c, int consultaOrdenada)
{
	if(consultaOrdenada==1)
	{
		if(primeroOrdenado==NULL)
		{
			printf("Lista vacia...\n");
		}
		else
		{
			actualOrdenado=primeroOrdenado;
			while(actualOrdenado!=NULL)
			{
				desplegarProceso(actualOrdenado);
				actualOrdenado= actualOrdenado->next;
			}
		}
	}
	else
	{
		int i =0;
		if(primero==NULL)
		{
			printf("Lista vacia...\n");
		}
		else
		{
			actual=primero;
			while(actual!=NULL)
			{
				if(1==c)
					desplegarProceso(actual);
				else
					obtenerArrival_Time(actual,i);
				actual= actual->next;
				i++;
			}
		}
	}
	
}



void consultarArrivalTimeDeProceso(int valorABuscar)
{
	int n=0;
	int m=0;
		if(primero==NULL)
		{
			printf("Lista vacia...\n");
		}
		else
		{
			actual=primero;
			while(actual!=NULL)
			{			
				if(valorABuscar==actual->arrival_time)
				{
					id=actual->id;
					arrival_time=actual->arrival_time;
					cpu_burst=actual->cpu_burst;
					priority=actual->priority;
					crearProceso(1);
					
				}			
				actual= actual->next;
			}
		}

}

void OrdenarListaPorTiempoDeLlegada()
{
	consultarProcesos(0,0);
	int i=0;	
	while(i<6)
	{
		consultarArrivalTimeDeProceso(i);
	}
	
	
}
 
 
 
int main (int argc, const char * argv[]) {
    
    FILE   *fp;                                /* Pointer to the file */
    int    quantum = 0;              /* Quantum value for round robin */
    //GSList  *processList_p = NULL;      /* Pointer to the process list */
    int    parameters[NUMVAL];      /* Process parameters in the line */
    int    i;                  /* Number of parameters in the process */
    
    /* Check if the number of parameters is correct */
    if (argc < NUMPARAMS){  
        printf("Need a file with the process information\n");
        printf("Abnormal termination\n");
        return (EXIT_FAILURE);
    } else {
        /* Open the file and check that it exists */
        fp = fopen (argv[1],"r");	  /* Open file for read operation */
        if (!fp) {                               /* There is an error */
            ErrorMsg("main","filename does not exist or is corrupted");
        } else {
            /* The first number in the file is the quantum */
            quantum = GetInt(fp);
            
            if (quantum == EXIT_FAILURE) {
                ErrorMsg("main","Quantum not found");
            } else {
                /*
                 * Read the process information until the end of file
                 * is reached.
                 */
                while (!feof(fp)){
                    /* For every four parameters create a new process */
                    for (i = 0; ((i < NUMVAL) && (!feof(fp))); i++) {
                        parameters[i] = GetInt(fp);
                    }
                    
                    /* Do we have four parameters? */
                    if (i == NUMVAL) {
                    	id=parameters[0];
                    	arrival_time=parameters[1];
                    	cpu_burst=parameters[2];
                    	priority=parameters[3];
                    	crearProceso(0);
                        /*processList_p = CreateProcess(processList_p,
                                                       parameters[0],
                                                       parameters[1],
                                                       parameters[2],
                                                       parameters[3],
                                                       NULL);*/
                    }
                }
            }
        }
        
        /* Start by sorting the processes by arrival time */
       OrdenarListaPorTiempoDeLlegada();
        
#ifdef DEBUG
        /* Now print each element in the list */
        ConsultarProcesos(0,1);
#endif
        
        /*
         * Apply all the scheduling algorithms and print the results
         */
        /*FirstCome (processList_p);
        
        NonPreemptive(processList_p, PRIORITY);
        
        NonPreemptive(processList_p, CPUBURST);
        
        Preemptive(processList_p, PRIORITY);
        
        Preemptive(processList_p, CPUBURST);
        
        RoundRobin(processList_p, quantum);

        /* Deallocate the memory assigned to the list */
        /*DestroyList(processList_p);*/
        
        printf("Program terminated correclty\n");
        //return (EXIT_SUCCESS);
    }
}
