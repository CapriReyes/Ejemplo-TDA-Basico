#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

int size[5];

struct alumno{
	char nombre[20];
	char *p_nombre;
	char apellido[30];
	char *p_apellido;
	char domicilio[20];
	char *p_domicilio;
	char no_Control[9];
	char *p_nC;
	char carrera[3];
	char *p_carrera;
}alum[2];

void gotoxy(int,int);

int main(){
	int pos=2;
	for(int i=0;i<2;i++){
		gotoxy(1,2);cout<<"DATOS DEL ALUMNO "<<i+1;
		gotoxy(1,4);cout<<"Nombre      |";
		gotoxy(1,5);cout<<"Apellidos   |";
		gotoxy(1,6);cout<<"Domicilio   |";
		gotoxy(1,7);cout<<"Carrera     |";
		gotoxy(1,8);cout<<"No. Control |";
		fflush(stdin);
		gotoxy(15,4);gets(alum[i].nombre);
		gotoxy(15,5);gets(alum[i].apellido);
		gotoxy(15,6);gets(alum[i].domicilio);
		gotoxy(15,7);gets(alum[i].carrera);
		gotoxy(15,8);cin>>alum[i].no_Control;
		
		
		size[0]=strlen(alum[i].nombre);
		alum[i].p_nombre=(char *)malloc(size[0]*sizeof(char));
		size[1]=strlen(alum[i].apellido);
		alum[i].p_apellido=(char *)malloc(size[1]*sizeof(char));
		size[2]=strlen(alum[i].domicilio);
		alum[i].p_domicilio=(char *)malloc(size[2]*sizeof(char));
		size[3]=strlen(alum[i].carrera);
		alum[i].p_carrera=(char *)malloc(size[3]*sizeof(char));
		size[4]=strlen(alum[i].no_Control);
		alum[i].p_nC=(char *)malloc(size[4]*sizeof(char));
		
		gotoxy(1,10);cout<<"Datos         |"<<"Size";
		gotoxy(1,11);cout<<"Nombre        |"<<size[0];
		gotoxy(1,12);cout<<"Apellidos     |"<<size[1];
		gotoxy(1,13);cout<<"Domicilio     |"<<size[2];
		gotoxy(1,14);cout<<"Carrera       |"<<size[3];
		gotoxy(1,15);cout<<"No. Control   |"<<size[4]<<endl;
		
		if(alum[i].nombre==NULL||alum[i].carrera==NULL||alum[i].domicilio==NULL||
				alum[i].apellido==NULL||alum[i].no_Control==NULL){
			printf("Error al asignar mamoria, ABORTAR....");
			return 0;
		}else{
			strcpy(alum[i].p_nombre,alum[i].nombre);
			strcpy(alum[i].p_apellido,alum[i].apellido);
			strcpy(alum[i].p_domicilio,alum[i].domicilio);
			strcpy(alum[i].p_carrera,alum[i].carrera);
			strcpy(alum[i].p_nC,alum[i].no_Control);
		}
		system("pause");
		system("cls");
	}
	gotoxy(1,1);cout<<"DATOS DE LOS ALUMNOS";
	for(int j=0;j<2;j++){
		gotoxy(1,pos);cout<<"Alumno "<<j+1;
		pos++;
		gotoxy(1,pos);cout<<"Nombre     |"<<alum[j].p_nombre;
		pos++;
		gotoxy(1,pos);cout<<"Apellidos  |"<<alum[j].p_apellido;
		pos++;
		gotoxy(1,pos);cout<<"Domicilio  |"<<alum[j].p_domicilio;
		pos++;
		gotoxy(1,pos);cout<<"Carrera    |"<<alum[j].p_carrera;
		pos++;
		gotoxy(1,pos);cout<<"No. Control|"<<alum[j].p_nC;
		pos+=3;
	}
	free(alum->p_nombre);
	free(alum->p_apellido);
	free(alum->p_domicilio);
	free(alum->p_carrera);
	free(alum->p_nC);
	return 1;
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}
