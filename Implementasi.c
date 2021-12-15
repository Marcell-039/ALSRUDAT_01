#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct DATA {
 char kode[5];
 struct DATA *next;
};
void hapus(struct DATA *kt, char kode);

int pilih1, pilih2, pilih3,pilih4,pilih5;
int userbenar,passbenar,kotabenar;
FILE *pf;
int i=1;
char ktp[16];
char hp[12];
char email[30];
char pass[20];
char repass[20];
char namaLengkap[20];
char kar,again = 'y';	
char user[20],passw[20];
char emailAdmin[20], passAdmin[30];
char kota[30],kode_kota[5];

 
	
int main_menuApp(){
		printf("\n===========================================\n\t\tAplikasi Booking Kereta Api\n-------------------------------------------\n");
        printf("Halo..!");
        printf("Selamat Datang, silakan pilih role Anda");
        printf("\n1. Pengunjung");
        printf("\n2. Admin");
        printf("\n3. Log Out");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda:	");
        scanf("%d",&pilih1);
        printf("\n===========================================\n");
        if(pilih1>3){
     		system("cls");
            printf("INPUTAN ANDA TIDAK VALID\n");
            printf("SILAHKAN COBA LAGI....");
		}switch(pilih1){
			case 1:
				{
				login_pengguna();
				break;	
			}
			case 2:
				{
					login_admin();
					break;
				}
			case 3:
				{
					system("exit");
				}
		}
	}


int login_admin(){
	system("cls");
        printf("\n===========================================\n\t\tHalaman Admin\n-------------------------------------------\n");
        printf("Email : ");
        scanf("%s", &emailAdmin);
        printf("Password : ");
        scanf("%s", &passAdmin);
        if((strcmp(emailAdmin,"admin")==0) && (strcmp(passAdmin,"admin") == 0)){
        	system("cls");
        	main_menu_admin();	
		}else{
			system("cls");
			printf("email/password Salah!");
		}
        
}

	int pengguna(){
		do{
		system("cls");
        printf("\n===========================================\n\t\tHalaman User\n-------------------------------------------\n");
        printf("Pilih salah satu pengguna!");
        printf("\n1. Registrasi\n");
        printf("\n2. Login\n");
        printf("\n3. Keluar");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda ?");
        scanf("%d",&pilih2);
        printf("\n===========================================\n");
        if(pilih2>3){
     		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(pilih2){
			case 1:
				
				system("cls");
				printf("======================\n");
				printf("REGISTRASI\n");
				printf("======================\n");
           		if((pf=fopen("nomorKTP.txt","w"))== NULL){
                    printf("file gagal diciptakan!\n");
                    exit(1);
            	}
            	printf("\n1. Nomor KTP : ");fflush(stdin);
                gets(ktp);
                if(strlen(ktp)==16){
                	strcat(ktp,"\n");
                	fputs(ktp, pf); 
					fclose(pf);
				}else{
					printf("Nilai yang dimasukkan tidak valid!\n");
				}
				
						
				if((pf=fopen("nama.txt","w"))== NULL){
                	printf("file gagal diciptakan!\n");
                	exit(1);
        		}
				printf("2. Nama Lengkap : ");fflush(stdin);
                gets(namaLengkap);
                strcat(namaLengkap,"\n");
               	fputs(namaLengkap, pf);	
               	fclose(pf);
				   	
				if((pf=fopen("nomorHP.txt","w"))== NULL){
                	printf("file gagal diciptakan!\n");
                	exit(1);
        		}
				printf("3. Nomor Handphone : ");fflush(stdin);
                gets(hp);
                if(strlen(hp) == 11 || strlen(hp) == 12){
                	strcat(hp,"\n");
                	fputs(hp, pf); 
                	fclose(pf);
				}else{
					printf("Nilai yang dimasukkan tidak valid!\n");
				}
				
					
				if((pf=fopen("email.txt","w"))== NULL){
                    printf("file gagal diciptakan!\n");
                    exit(1);
        		}
				printf("4. Email : ");fflush(stdin);
                gets(email);
                strcat(email,"\n");
                fputs(email, pf);
                fclose(pf);
                
				if((pf=fopen("password.txt","w"))== NULL){
                    printf("file gagal diciptakan!\n");
                    exit(1);
        		}
				printf("5. Password : ");fflush(stdin);
            	gets(pass);
            	strcat(pass,"\n");
            	fputs(pass, pf);
				fclose(pf);
				
				if((pf=fopen("repassword.txt","w"))== NULL){
                	printf("file gagal diciptakan!\n");
                	exit(1);
        		}
				printf("6. Re-Password : ");fflush(stdin);
                gets(repass);
                strcat(repass,"\n");
                fputs(repass, pf);
                
                fclose(pf);
				
				printf("Kembali ke menu [y/t] ? ");
        		again=getch();
				break;	
			
			case 2:
					login_user();
					break;
				
			case 3:
				
					system("exit");
					break;
		
		}
	}while (again == 'y');
	}




