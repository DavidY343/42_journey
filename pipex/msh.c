//P2-SSOO-22/23

// MSH main file
// Write your msh source code here

//#include "parser.h"
#include <stddef.h>         /* NULL */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>

#define MAX_COMMANDS 8


// ficheros por si hay redirección
char filev[3][64];

//to store the execvp second parameter
char *argv_execvp[8];

void siginthandler(int param)
{
	//Esto es para esperar a los procesos que se han quedado en bg si es que se ha quedado alguno
	while (wait(NULL) > 0){
	}
	printf("****  Saliendo del MSH **** \n");
	//signal(SIGINT, siginthandler);
	exit(0);
}
//Creamos una funcion para que el codigo que mejor refactorizado
void mycalculadora(){

	if (argv_execvp[3] != NULL && argv_execvp[4] == NULL){
		int resul = 0;
		int num1 = atoi(argv_execvp[1]);
		int num2 = atoi(argv_execvp[3]);
		//Si se la pasa una string atoi devuelve un 0
		if (num1 != 0 && num2 != 0){
			if (strcmp(argv_execvp[2], "add") == 0){
				char *variable = getenv("Acc"); // intenta obtener el valor actual de la variable de entorno				
				resul = num1 + num2;
				
				if (variable == NULL) {
				  // la variable de entorno no está definida, por lo que se crea con el valor por defecto
				  setenv("Acc", "0", 1);
				  variable = getenv("Acc");
				}
				
				int Acc_v = atoi(variable);
				Acc_v = Acc_v + resul;
				fprintf(stderr, "[OK] %d + %d = %d; Acc %d\n", num1, num2, resul, Acc_v);
				char Acc_s[50];
				sprintf(Acc_s, "%d", Acc_v);
				setenv("Acc", Acc_s, 1);
				
			}else if(strcmp(argv_execvp[2], "mul") == 0){
				resul = num1 * num2;
				fprintf(stderr, "[OK] %d * %d = %d\n", num1, num2, resul);
			}else if(strcmp(argv_execvp[2], "div") == 0){
				int resto = 0;
				resul = num1 / num2;
				resto = num1 % num2;
				fprintf(stderr, "[OK] %d / %d = %d; Resto %d\n", num1, num2, resul, resto);
			}else{
			//CONTROL DE ERRORES
				printf("[ERROR] La estructura del comando es mycalc <operando_1> <add/mul/div> <operando_2>\n");
			}
			} else {
				printf("[ERROR] La estructura del comando es mycalc <operando_1> <add/mul/div> <operando_2>\n");
			}
		}else {
			printf("[ERROR] La estructura del comando es mycalc <operando_1> <add/mul/div> <operando_2>\n");
	}
}

/* Timer */
pthread_t timer_thread;
unsigned long  mytime = 0;

void* timer_run ( )
{
	while (1)
	{
		usleep(1000);
		mytime++;
	}
}

//Creamos una funcion para calcular el tiempo 
void mytiempo(){
	if (argv_execvp[1] == NULL){
	
		int seconds = mytime / 1000;
		int hours = seconds / 3600;
		int minutes = (seconds % 3600) / 60;
		int secs = seconds % 60;
		fprintf(stderr, "%02d:%02d:%02d\n", hours, minutes, secs); 
		}
	else{
		//CONTROL DE ERRORES
		fprintf(stderr, "Error, el comando mytime no permite argumentos\n");
		}
}
/**
 * Get the command with its parameters for execvp
 * Execute this instruction before run an execvp to obtain the complete command
 * @param argvv
 * @param num_command
 * @return
 */
void getCompleteCommand(char*** argvv, int num_command) {
	//reset first
	for(int j = 0; j < 8; j++)
		argv_execvp[j] = NULL;

	int i = 0;
	for ( i = 0; argvv[num_command][i] != NULL; i++)
		argv_execvp[i] = argvv[num_command][i];
}


/**
 * Main sheell  Loop  
 */
int main(int argc, char* argv[])
{


  
	/**** Do not delete this code.****/
	int end = 0; 
	int executed_cmd_lines = -1;
	char *cmd_line = NULL;
	char *cmd_lines[10];

	if (!isatty(STDIN_FILENO)) {
		cmd_line = (char*)malloc(100);
		while (scanf(" %[^\n]", cmd_line) != EOF){
			if(strlen(cmd_line) <= 0){
			
				return 0;
			}
			cmd_lines[end] = (char*)malloc(strlen(cmd_line)+1);
			strcpy(cmd_lines[end], cmd_line);
			end++;
			fflush (stdin);
			fflush(stdout);
		}
	}

	pthread_create(&timer_thread,NULL,timer_run, NULL);

	/*********************************/

	char ***argvv = NULL;
	int num_commands;
			

	while (1) 
	{
		int status = 0;
		int command_counter = 0;
		int in_background = 0;
		signal(SIGINT, siginthandler);

		// Prompt 
		write(STDERR_FILENO, "MSH>>", strlen("MSH>>"));

		// Get command
		//********** DO NOT MODIFY THIS PART. IT DISTINGUISH BETWEEN NORMAL/CORRECTION MODE***************
		executed_cmd_lines++;
		if( end != 0 && executed_cmd_lines < end) {
			command_counter = read_command_correction(&argvv, filev, &in_background, cmd_lines[executed_cmd_lines]);
		}
		else if( end != 0 && executed_cmd_lines == end){
			return 0;
		}
		else{
			command_counter = read_command(&argvv, filev, &in_background); //NORMAL MODE
		}
		//************************************************************************************************


		/************************ STUDENTS CODE ********************************/
		if (command_counter > 0) {
			if (command_counter > MAX_COMMANDS){
				printf("Error: Numero máximo de comandos es %d \n", MAX_COMMANDS);
			}
			else {
				int retorno, f10, fd[2]; 
				int i = 0;
			
				getCompleteCommand(argvv, 0);
				
				if (strcmp(argv_execvp[0], "mycalc") == 0) {
					
					mycalculadora();
				}else if ((strcmp(argv_execvp[0], "mytime") == 0)){
				
					mytiempo();
				}else{
			
					for (i = 0; i < command_counter; i++) {
						// 1.- Creamos el pipe, menos para el último proceso
						if (i != (command_counter - 1)) {
							retorno = pipe(fd);
							if (retorno < 0) {
								perror("Se creó mal la pipe");
								exit(-1);
							}
						}
						// Hacemos un fork
						pid_t pid = fork();
						switch (pid) {
							case -1:
								perror("Ha fallado el fork");
								exit(-1);
							case 0:
								// El hijo
								// Ignoramos la señal de CTRL+C en los hijos
								signal(SIGINT, SIG_IGN);
								
									if (strcmp(filev[2], "0") != 0) {
									// Si el archivo no es "0", se modifica la salida estándar
										int archivo_error;
										archivo_error = open(filev[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
										if (archivo_error < 0) {
											perror("Error al abrir el archivo de error: ");
											exit(-1);
										}
										close(2);
										dup(archivo_error);
										close(archivo_error);
									}
								
								// Si no soy el primero:
								if (i != 0) {
									close(0);
									dup(f10);
									close(f10);
								} else {
								// Si soy el primero
									int archivo_entrada;
									if (strcmp(filev[0], "0") != 0) {
									// Si el archivo no es "0", se modifica la salida estándar
									
										archivo_entrada = open(filev[0], O_RDONLY, 0666);
										if (archivo_entrada < 0) {
											perror("Error al abrir el archivo de entrada: ");
											exit(-1);
										}
										close(0);
										dup(archivo_entrada);
										close(archivo_entrada);
									}
								}
								// Si no soy el último:
								if (i != (command_counter - 1)) {
									close(1);
									dup(fd[1]);
									close(fd[0]);
									close(fd[1]);
								}else{
									int archivo_salida;
									if (strcmp(filev[1], "0") != 0) {
									// Si el archivo no es "0", se modifica la salida estándar
									
										archivo_salida = open(filev[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
									if (archivo_salida < 0) {
										perror("Error al abrir el archivo de salida: ");
										exit(-1);
									}
									close(1);
									dup(archivo_salida);
									close(archivo_salida);
								}
										
								}
								// Si el archivo es "0", se utiliza la salida estándar
								// Ejecutamos el comando
								getCompleteCommand(argvv, i);
								execvp(argv_execvp[0], argv_execvp);
								perror("execvp failed");
								exit(-1);
							default:
								// El padre
								// Si no es el último:
								if (i != (command_counter - 1)) {
									close(fd[1]);
									f10 = fd[0];
								} else if (command_counter > 1) { // Si soy el último
									close(fd[0]);
								}
								// Esperamos a todos los hijos que no están en bg
								if (!in_background) {
									while (wait(NULL) != pid) {}
								} //cierre del if
						} //cierre del switch
					} //cierre del for
				} // cierre del else
			} //cierre del else primigenio
		} //cierre del if inicial	
	} //cierre del while de la msh
	
	return 0;
} //cierre del main
