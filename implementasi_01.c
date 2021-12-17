#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

// Author	: 	Marcellino Kelly N Lumban Gaol

typedef struct jadwal {
	char kode[100];
	char tanggal[100];
	char waktu_keberangkatan[100];
	char keberangkatan[100];
	char tujuan_pergi[100];
	char kai[100];
	int sisa;
	int pemasukan;
}jadwal;
typedef struct kota {
	char kode[100];
	char namaKota[100];
} kota;

typedef struct rute {
	char keberangkatan[100];
	char tujuan[100];
	char kode[100];
	char kode1[100];
	char kode2[100];
	char kode4[100];
	int bisnis;
	int premium;
}rute;

typedef struct dataUser{
    int rno; 
    char name[20]; 
    struct subject{
        int scode;
        char name[20]; 
        int mark;
    }sub[3]; 
    int total;
    float per;
    
    char ktp[16];
    char nama[100];
    char hp[16];
    char email[100];
    char password[100];
    char repassword[100];
} dataUser;

int choose1, choose2, choose3,choose4,choose5,choose6,choose7;
int userbenar,passbenar;
FILE *pf, *pf1;
int i=1;
char hp[12];
char email[30];
char pass[20];
char repass[20];
char namaLengkap[20];
char kar,again = 'y';	
char user[20],password[20];
char emailAdmin[20], passAdmin[30];


 

	
	
int mainMenu(){
		printf("\n==================================================================================\n\t\t Program Sederhana Sistem KAT (KERETA API TOBA)\n");
		printf("==================================================================================\n");
        printf("PILIH ROLE ANDA ..............\n");
        printf("\n1. CUSTOMER");
        printf("\n2. ADMIN");
        printf("\n3. LOG-OUT");
        printf("\n");
        printf("MASUKKAN PILIHAN ANDA : ");
        scanf("%d",&choose1);
		printf("\n");
		printf("\n");
        if(choose1>3){
     		system("cls");
            printf("MASUKAN ANDA TIDAK VALID!!\n");
		}switch(choose1){
			case 1:
				{
				customer();
				break;	
			}
			case 2:
				{
					auth_admin();
					break;
				}
			case 3:
				{
					system("exit");
				}
		}
	}
		
	
int userMenu(){
	do{
		system("cls");
		printf("*********=MENU CUSTOMER=*********\n");
		printf("HALO TEMAN KAI PARTOBAA, \n\n", user);
		printf("1. Lihat Kota\n");
		printf("2. Lihat Rute\n");
		printf("3. Kelola Profile\n");
		printf("4. Lihat Jadwal Perjalanan\n");
		printf("5. Logout\n\n");
		printf("Pilihan Anda [1/2/3/4] :  ");
		scanf("%d",&choose3);
		if(choose3>4){
			system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(choose3){
			case 1:
				system("cls");
				printf("\n===========================");
				printf("Halaman Lihat Kota User\n");
				printf("\n===========================");
				system("cls");
			kota k1;
			int counter = 1;
			kota *k;
			FILE *city, *city1;
			int n,i,j;
			
			k = (kota*)malloc(100*sizeof(kota));
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.namaKota);
				counter++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
				printf("\n\nMain Menu [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
				
			case 2:
				system("cls");
				printf("\n===========================");
				printf("Halaman Lihat Rute User\n");
				printf("\n===========================");
				lihat_rute();
				printf("\n\nMain Menu [y/t] ? ");
        		again=getch();
        		system("cls");
				break;
			
			case 3:
	system("cls");
				printf("\n==============================================\n");
				printf("------ Halaman Kelola Akun By User ------\n");
				printf("\n================================================\n\n");
				int   found=0;
			    dataUser user1;
			    char ktp[100];
			    fflush(stdin);
			    printf("Masukkan Nomor KTP : ");
			    scanf("%[^\n]s",ktp);
			
			    pf = fopen("dataUser.txt","r");
			    pf1 = fopen("temp.txt","w");
			    while(fread(&user1,sizeof(dataUser),1,pf)){
			        if(strcmp(user1.ktp,ktp)==0){
			            found = 1;
			            
			            printf("===============================\n");
			            printf("----------Data Customer--------\n");
			            printf("===============================\n");
			            printf("\nNama Lengkap : %s",user1.nama);
			   			printf("\nNomor Handphone : %s",user1.hp);
			   			printf("\nEmail : %s",user1.email);
			   			printf("\nPassword : %s",user1.password);  
			   			
			   			printf("\n\n===============================\n");
			   			printf("\n\n--Ubah Data Customer--");
			   			printf("\n\n===============================\n");
			            fflush(stdin);
			        	printf("\nNomor KTP : ");
				        fflush(stdin);
				        scanf("%[^\n]s",user1.ktp);
				        fflush(stdin);
				        printf("Nama Lengkap : ");
				        scanf("%[^\n]s",user1.nama);
				        fflush(stdin);
				        printf("Nomor Handphone : ");
				        scanf("%[^\n]s",user1.hp);
				        fflush(stdin);
				        printf("Email : ");
				        scanf("%[^\n]s",user1.email);
				        fflush(stdin);
				        printf("Password : ");
				        scanf("%[^\n]s",user1.password);
				        fflush(stdin);
				        printf("Re-Password : ");
				        scanf("%[^\n]s",user1.repassword);
			        }
			        fwrite(&user1,sizeof(dataUser),1,pf1);
			    }
			    fclose(pf);
			    fclose(pf1);
			
			
			    if(found){
			            pf = fopen("dataUser.txt","w");
			            pf1 = fopen("temp.txt","r");
			
			            while(fread(&user1,sizeof(dataUser),1,pf1)){
			                fwrite(&user1,sizeof(dataUser),1,pf);
			                printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
			                printf("\nNama Lengkap : %s",user1.nama);
				   			printf("\nNomor Handphone : %s",user1.hp);
				   			printf("\nEmail : %s",user1.email);
				   			printf("\nPassword : %s",user1.password); 
							   		
			            }
			            fclose(pf);
			            fclose(pf1);
			    }
			    			printf("\nMain Menu [y/t] ? ");
			        		again=getch();
							break;
			
			case 4:
				system("cls");
				printf("\n===========================");
				printf("Halaman Lihat Jadwal Perjalanan User\n");
				printf("\n===========================");
				lihat_jadwal();
				printf("\n\nMain Menu [y/t] ? ");
        		again=getch();
        		system("cls");
				break;				
			
			case 5:
				system("cls");
				mainMenu();
				system("cls");
		}
	}while(again == 'y');
}

int login_user(){
			system("cls");  
			 int i, j, found=0;
    dataUser user1;
    dataUser *s;
    char email[100];
    char choose6ord[100];
			printf("======================\n");
			printf("---------LOGIN----------\n");
			printf("======================\n");
			fflush(stdin);
			printf("Username :  ");
    		scanf("%[^\n]s",email);
    		fflush(stdin);
    		printf("Password : ");
    		scanf("%[^\n]s",password);

    pf = fopen("dataUser.txt","r");
    while(fread(&user1,sizeof(dataUser),1,pf)){
        if(strcmp(user1.email,email)==0){
            if (strcmp(user1.password,password)==0) {	
       			userMenu();
				found = 1;
				fclose(pf);
			}else if(!found){
				login_user();
			}
        }
	}
}
	//CUSTOMER SIDE
	int customer(){
		do{
		system("cls");
        printf("\n===========================================\n\t\t****CUSTOMER PAGE****\n-------------------------------------------\n");
        printf("\n\n");
        printf("\n1. Registrasi\n");
        printf("\n2. Login\n");
        printf("\n3. LOG OUT");
        printf("\n-------------------------------------------\n");
        printf("Pilihan Anda [1/2/3] : ");
        scanf("%d",&choose2);
        printf("\n===========================================\n");
        if(choose2>3){
     		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
		}switch(choose2){
			case 1:
				
				system("cls");
				printf("======================\n");
				printf("*******REGISTRASI*****\n");
				printf("======================\n");
				
		           	 dataUser *s;
		        	int n,i,j;

		        s = (dataUser*)malloc(100*sizeof(dataUser));
		        pf = fopen("dataUser.txt","w+");
		
		        for(i=0;i<1;i++){
		        	fflush(stdin);
		            printf("Nomor KTP : ");
		            scanf("%[^\n]s",s[i].ktp);
		            fflush(stdin);
		            printf("Nama Lengkap : ");
		            scanf("%[^\n]s",s[i].nama);
		            fflush(stdin);
		            printf("Nomor Handphone : ");
		            scanf("%[^\n]s",s[i].hp);
		            fflush(stdin);
		            printf("Email : ");
		            scanf("%[^\n]s",s[i].email);
		            fflush(stdin);
		            printf("Password : ");
		            scanf("%[^\n]s",s[i].password);
		            fflush(stdin);
		            printf("Re-Password : ");
		            scanf("%[^\n]s",s[i].repassword);
		
		            fwrite(s+i,sizeof(dataUser),1,pf);
				        }
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
//ADMIN SIDE

int auth_admin(){
	system("cls");
        printf("\n===========================================\n\t\t****ADMIN PAGE****\n-------------------------------------------\n\n");
        printf("Username : ");
        scanf("%s", &emailAdmin);
        printf("Password : ");
        scanf("%s", &passAdmin);
        if((strcmp(emailAdmin,"admin")==0) && (strcmp(passAdmin,"admin") == 0)){
        	system("cls");
        	menu_admin();	
		}else{
			system("cls");
			printf("email/password Salah!");
		}
    	    
}

int menu_admin(){
	do{
		system("cls");
		printf("===============================\n");
		printf("**********=MENU ADMIN=**********\n");
		printf("===============================\n");
		printf("1. Kelola Akun\n");
		printf("2. Kelola Kota\n");
		printf("3. Kelola Rute\n");
		printf("4. Lihat Pemasukan\n");
		printf("5. Kelola Jadwal\n");
		printf("6. LOG OUT\n");
		printf("MASUKKAN PILIHAN ANDA : ");
		scanf("%d",&choose4);
		if(choose4>6){
			system("cls");
            printf("INPUTAN TIDAK VALID!\n");
		}switch(choose4){
			case 1:
				system("cls");
				printf("\n===========================\n");
				printf("------Halaman Kelola Akun------\n");
				printf("\n===========================\n\n");
				int i, j, found=0;
			    dataUser user1;
			    char ktp[100];
			    fflush(stdin);
			    printf("Masukkan Nomor KTP : ");
			    scanf("%[^\n]s",ktp);
			
			    pf = fopen("dataUser.txt","r");
			    pf1 = fopen("temp.txt","w");
			    while(fread(&user1,sizeof(dataUser),1,pf)){
			        if(strcmp(user1.ktp,ktp)==0){
			            found = 1;
			            
			            printf("===============================\n");
			            printf("----------Data Customer--------\n");
			            printf("===============================\n");
			            printf("\nNama Lengkap : %s",user1.nama);
			   			printf("\nNomor Handphone : %s",user1.hp);
			   			printf("\nEmail : %s",user1.email);
			   			printf("\nPassword : %s",user1.password);  
			   			
			   			printf("===============================\n");
			   			printf("\n\n--Ubah Data Customer--");
			   			printf("===============================\n");
			            fflush(stdin);
			        	printf("\nNomor KTP : ");
				        fflush(stdin);
				        scanf("%[^\n]s",user1.ktp);
				        fflush(stdin);
				        printf("Nama Lengkap : ");
				        scanf("%[^\n]s",user1.nama);
				        fflush(stdin);
				        printf("Nomor Handphone : ");
				        scanf("%[^\n]s",user1.hp);
				        fflush(stdin);
				        printf("Email : ");
				        scanf("%[^\n]s",user1.email);
				        fflush(stdin);
				        printf("Password : ");
				        scanf("%[^\n]s",user1.password);
				        fflush(stdin);
				        printf("Re-Password : ");
				        scanf("%[^\n]s",user1.repassword);
			        }
			        fwrite(&user1,sizeof(dataUser),1,pf1);
			    }
			    fclose(pf);
			    fclose(pf1);
			
			
			    if(found){
			            pf = fopen("dataUser.txt","w");
			            pf1 = fopen("temp.txt","r");
			
			            while(fread(&user1,sizeof(dataUser),1,pf1)){
			                fwrite(&user1,sizeof(dataUser),1,pf);
			                printf("\n\nData Berhasil Diupdate, Berikut Data Terbaru: ");
			                printf("\nNama Lengkap : %s",user1.nama);
				   			printf("\nNomor Handphone : %s",user1.hp);
				   			printf("\nEmail : %s",user1.email);
				   			printf("\nPassword : %s",user1.password); 
							   		
			            }
			            fclose(pf);
			            fclose(pf1);
			    }
			    			printf("\nMain Menu [y/t] ? ");
			        		again=getch();
							break;
				
			case 2:
				system("cls");
				kelola_kota();
				break;
			
			case 3:
				system("cls");
				kelola_rute();
				break;
			
			case 4:
				system("cls");
				printf("PEMASUKAN\n");
				
				
        		again=getch();
				break;
			
			case 5:
				system("cls");
				printf("======KELOLA JADWAL=======\n");
				kelola_jadwal_admin();
				break;
			
			case 6:
				system("cls");
				mainMenu();
				break;	
		}
	}while(again == 'y');
}	


int kelola_kota(){
	do{
	system("cls");
	printf("========KELOLA KOTA========\n");
	printf("1. Tambah Data Kota\n");
	printf("2. Lihat Data Kota\n");
	printf("3. Edit Data Kota\n");
	printf("4. Delete Data Kota\n");
	printf("5. Main Menu\n");
	printf("\nPilihan : ");
	scanf("%d",&choose5);
	if(choose5>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(choose5){
		case 1:
			
			system("cls");
			printf("======TAMBAH DATA KOTA======\n");
			kota *k;
			FILE *city, *city1;
			int n,i,j;
			
			k = (kota*)malloc(100*sizeof(kota));
			city = fopen("kota.txt","a+");
			
			printf("#TAMBAH DATA KOTA#\n\n");
			for(i=0;i<1;i++){
				printf("Tambah Kota : ");
				fflush(stdin);
			    scanf("%s %s",k[i].kode,k[i].namaKota);
			    fwrite(k+i,sizeof(kota),1,city);
			}
	    
	    fclose(city);	
		printf("Main Menu [y/t] ? ");
        again=getch();		
			break;
			
		case 2:
			system("cls");
			kota k1;
			int counter = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.namaKota);
				counter++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
            printf("\nMain Menu [y/t] ? ");
			again=getch();
			break;
			
		case 3:
			system("cls");
			char id_kota[5];
			int found = 0;
			int counter2 = 1;
			city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter2,k1.kode,k1.namaKota);
				counter2++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
    		
		    char kodeKota[10];
		    fflush(stdin);
		    printf("\nEdit Kota : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    city = fopen("kota.txt","r");
		    city1= fopen("temp2.txt","w");
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kodeKota)==0){
		        	found ==1;
		        	fflush(stdin);
		            printf("\nKode Kota : ");
		            fflush(stdin);
				    scanf("%[^\n]s",k1.kode);
				    fflush(stdin);
				    printf("Nama Kota : ");
				    scanf("%[^\n]s",k1.namaKota); 	
		        } 
		        fwrite(&k1,sizeof(kota),1,city1);
		    }
		    fclose(city);
		    fclose(city1);
		    
			if(found==0){
            	city = fopen("kota.txt","w");
	            city1 = fopen("temp2.txt","r");
	
	        while(fread(&k1,sizeof(kota),1,city1)){
	           fwrite(&k1,sizeof(kota),1,city);	
            }
            fclose(city);
            fclose(city1);
    }

			break;
		
		case 4:	
			system("cls");
			int counter3 = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter3,k1.kode,k1.namaKota);
				counter3++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);

    		char kode[10];
		    printf("\nDelete Kota : DELETE_");
		    fflush(stdin);
		    scanf("%[^\n]s",kode);
			
			city = fopen("kota.txt","r");
		    city1 = fopen("temp2.txt","w");
		    
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kode)==0){
		        	found = 1;			
		        }
		        else
		        
		        fwrite(&k1,sizeof(kota),1,city1);   
		    }
		    fclose(city);
		    fclose(city1);
		     if(found){
		        city = fopen("kota.txt","w");
		        city1 = fopen("temp2.txt","r");
		
		        while(fread(&k1,sizeof(kota),1,city1)){
		            fwrite(&k1,sizeof(kota),1,city);
		        }
		        fclose(city);
		        fclose(city1);
		        printf("\nData telah berhasil dihapus\n");
    		}
    		
            printf("Main Menu [y/t] ? ");
			again=getch();
			break;
		
		case 5:
			system("cls");
			menu_admin();
			system("cls");
			break;
	}
	}while(again == 'y');	
}

int lihat_rute(){
	rute *r;
	rute r1;
	kota k1;
    FILE *prute,*prute1;
    int n,i,j, found =0;
	int counter4=1;
    prute = fopen("rute.txt","r");
	system("cls");
	printf("\n\n#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\t\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,prute)) {
		printf("%d\t\t%s\t\t%s\t\t%s - %s\t\t%d\t\t\%d\n",counter4,r1.keberangkatan,r1.tujuan,r1.kode1,r1.kode2,r1.bisnis,r1.premium);
		counter4++;
    }
	printf("\n\n-------------------------------------------------------------------");
    fclose(prute);
}

//JADWAL
int kelola_jadwal_admin(){
	
	do{
	system("cls");
	printf("========KELOLA JADWAL KEBERANGKATAN========\n");
	printf("1. Tambah Jadwal Keberangkatan\n");
	printf("2. Lihat Data Jadwal Keberangkatan\n");
	printf("3. Edit Data Jadwal Keberangkatan\n");
	printf("4. Delete Data Jadwal Keberangkatan\n");
	printf("5. Main Menu\n");
	printf("\nPilihan : ");
	scanf("%d",&choose7);
	if(choose7>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(choose7){
		case 1:
			
		add_jadwal();
		printf("Main Menu [y/t] ? ");
        again=getch();
			
			
			break;
			
		case 2:
		
		lihat_jadwal();
            printf("\nMain Menu [y/t] ? ");
			again=getch();
			break;
			
		case 3:
			edit_jadwal();
            printf("\nMain Menu [y/t] ? ");
			again=getch();
			

			break;
		
		case 4:	
		delete_jadwal();
            printf("Main Menu [y/t] ? ");
			again=getch();
			break;
		
		case 5:
			system("cls");
			menu_admin();
			system("cls");
			break;
	}
	}while(again == 'y');	
}

add_jadwal() {
	jadwal *j;
	jadwal j1;
	rute r1;
    FILE *fp,*fp1;
    int n,i;

    j = (jadwal*)malloc(100*sizeof(jadwal));
    fp = fopen("jadwal.txt","a+");
    fp1 = fopen("rute.txt","r");
    
	printf("#TAMBAH DATA JADWAL#\n\n");
	
    for(i=0;i<1;i++){
    	printf("Tambah Data Jadwal : ");
    	printf("Data Di Bawah Wajib di Isi !\n");
    	printf("\n\nKode Jadwal : ");
    	fflush(stdin);
        scanf("%s",j[i].kode);
        printf("\nTanggal : ");
    	fflush(stdin);
        scanf("%s",j[i].tanggal);
        printf("\nWaktu Keberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].waktu_keberangkatan);
        printf("\nKeberangkatan : ");
    	fflush(stdin);
        scanf("%s",j[i].keberangkatan);
        printf("\nTujuan : ");
    	fflush(stdin);
        scanf("%s",j[i].tujuan_pergi);
        printf("\nKAI : ");
    	fflush(stdin);
        scanf("%s",j[i].kai);
        printf("\nJumlah sisa kursi : ");
    	fflush(stdin);
        scanf("%d",&j[i].sisa);
        
        
        
        while(fread(&r1,sizeof(rute),1,fp1)) {
            if(strcmp(j[i].keberangkatan,r1.keberangkatan)!=0) {
            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j[i].keberangkatan);
			} 
			
			if (strcmp(j[i].tujuan_pergi,r1.tujuan)!=0) {
				printf("\n\nTujuan %s tidak ada pada daftar !",j[i].tujuan_pergi);
			}
		
        }
        
        fwrite(j+i,sizeof(jadwal),1,fp);
    }
    
    printf("\n-----------------------------------------");
    printf("\nData Berhasil Ditambahkan...\n");
    printf("------------------------------------------");
    
    fclose(fp);
    
    kelola_jadwal_admin();
}


int lihat_jadwal() {
	jadwal *j;
	jadwal j1;
    FILE *fp;
    int n,i;
    

	
	printf("\n\n-------------------------------------------------------------------");
    
    fp = fopen("jadwal.txt","r");
	system("cls");
	printf("----------------------------------\n");
	printf("#=====LIHAT DATA JADWAL=====#");
	printf("----------------------------------\n");
	printf("\nData Lengkap Jadwal Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("Kode Jadwal\tTanggal\tWaktu Keberangkatan\t\tKeberangkatan\tTujuan\t\tKAI\t\tStatus\n");
	while(fread(&j1,sizeof(jadwal),1,fp)) { 
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tKAI %s\t\tSisa %d Kursi\n",j1.kode,j1.tanggal, j1.waktu_keberangkatan, j1.keberangkatan, j1.tujuan_pergi, j1.kai, j1.sisa);
    }
	
	printf("\n\n-------------------------------------------------------------------");
    fclose(fp);
}

int edit_jadwal() {
	jadwal *j;
	int i=0;
	int found=0, counter=1;
    jadwal j1;
    rute r1;
    FILE *fp, *fp1, *fp2;
    
    char kode[100], kode1[100], kode2[100], kode3[100];
    
	system("cls");
    lihat_jadwal();


    fflush(stdin);
    
	fp = fopen("rute.txt","r");
    fp1 = fopen("jadwal.txt","r");
    fp2 = fopen("temp.txt","w");
    
    
    printf("\n\nEdit Jadwal : \nEDIT_");
    scanf("%[^\n]s",kode);
    
	while(fread(&j1,sizeof(jadwal),1,fp1)){
    	if(strcmp(j1.kode,kode)==0){
				found = 1;
		    printf("\n\nKode Jadwal : ");
	    	fflush(stdin);
	        scanf("%s",j1.kode);
	        printf("\nTanggal : ");
	    	fflush(stdin);
	        scanf("%s",j1.tanggal);
	        printf("\nWaktu Keberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.waktu_keberangkatan);
	        printf("\nKeberangkatan : ");
	    	fflush(stdin);
	        scanf("%s",j1.keberangkatan);
	        printf("\nTujuan : ");
	    	fflush(stdin);
	        scanf("%s",j1.tujuan_pergi);
	        printf("\nKAI : ");
	    	fflush(stdin);
	        scanf("%s",j1.kai);
	        printf("\nJumlah sisa kursi : ");
	    	fflush(stdin);
	        scanf("%d",&j1.sisa);   	

			while(fread(&r1,sizeof(rute),1,fp1)) {
	            if(strcmp(j1.keberangkatan,r1.keberangkatan)!=0) {
	            	printf("\n\nKeberangkatan %s tidak ada pada daftar !",j1.keberangkatan);
				} 
				
				if (strcmp(j1.tujuan_pergi,r1.tujuan)!=0) {
					printf("\n\nTujuan %s tidak ada pada daftar !",j1.tujuan_pergi);
				}
			
	        }
	        
	        
	    	
        } 
        
    	fwrite(&j1,sizeof(jadwal),1,fp2);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    
    if (found==1) {
	    
    	fp = fopen("jadwal.txt","w");
    	fp1 = fopen("temp.txt","r");
    	
		while(fread(&j1,sizeof(jadwal),1,fp1)) {
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        
	    fclose(fp);
	    fclose(fp1);
	    
	} else {
		printf("\n\nnot found");
	}
}


int delete_jadwal() {
	int i, found=0;
    jadwal j1;
    FILE *fp, *fp1;
    char kode[100];
    fp = fopen("jadwal.txt","r");
    
	system("cls");
	lihat_jadwal();
    
    printf("\nDelete Jadwal : DELETE_");
    fflush(stdin);
    scanf("%[^\n]s",kode);

    fp = fopen("jadwal.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&j1,sizeof(jadwal),1,fp)){
        if(strcmp(j1.kode,kode)==0){
            found = 1;
        }
        else
            fwrite(&j1,sizeof(jadwal),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
        fp = fopen("jadwal.txt","w");
        fp1 = fopen("temp.txt","r");

        while(fread(&j1,sizeof(jadwal),1,fp1)){
            fwrite(&j1,sizeof(jadwal),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nData Tidak Ditemukan...\n");
}


//RUTE
int kelola_rute(){
	do{
	system("cls");
	printf("========KELOLA KOTA========\n");
	printf("1. Tambah Data Rute\n");
	printf("2. Lihat Data Rute\n");
	printf("3. Edit Data Rute\n");
	printf("4. Delete Data Rute\n");
	printf("5. Main Menu\n");
	printf("\nPilihan : ");
	scanf("%d",&choose6);
	if(choose6>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(choose6){
		case 1:
		system("cls");
		rute *r;
		rute r1;
		kota k1;
	    FILE *prute,*prute1;
	    int n,i,j, found =0;
	
	    r = (rute*)malloc(100*sizeof(rute));
	    prute = fopen("rute.txt","a+");
	    prute1 = fopen("kota.txt","r");
	    
		printf("#TAMBAH DATA RUTE#\n\n");
		char kode1[225], kode2[225], kode3[225],kode4[2];
		
	    	printf("Tambah Data Rute : ");
	    	fflush(stdin);
	        scanf("%s %s %d %d",r1.keberangkatan,r1.tujuan,&r1.bisnis,&r1.premium);
	        while(fread(&k1,sizeof(kota),1,prute1)) {
	            if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
	            	strcpy(r1.kode1,k1.kode);
				} 
				if (strcmp(r1.tujuan,k1.namaKota)==0) {
					strcpy(r1.kode2,k1.kode);
				}
				strcpy(kode3,strcat(r1.kode1,""));
				strcpy(r1.kode,(strcat(kode3,r1.kode2)));
	        }
	        fwrite(&r1,sizeof(rute),1,prute);
	    
	    
	    printf("\n-----------------------------------------");
	    printf("\nData Berhasil Ditambahkan\n");
	    printf("------------------------------------------");
	    
	    fclose(prute);
	    fclose(prute1);
	    printf("\nMain Menu [y/t] ? ");
		again=getch();
		break;
		
		case 2:
			system("cls");
		    lihat_rute();
		    printf("\nMain Menu [y/t] ? ");
			again=getch();
		break;
		
		case 3:
		system("cls");
		int counter5 =1;
			prute = fopen("rute.txt","r");
			system("cls");
			lihat_rute();
			char kodeKota[100];
			printf("\n\n#EDIT DATA RUTE#");
			fflush(stdin);
		    printf("\n\nEdit Rute : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    pf= fopen("kota.txt","r");
		    prute = fopen("rute.txt","r");
		    prute1 = fopen("temp3.txt","w");
		    	while(fread(&r1,sizeof(rute),1,prute)){
		        	if(strcmp(r1.kode,kodeKota)==0){
		       			found = 1;
				    	fflush(stdin);
			            printf("\nKeberangkatan : ");
					    scanf("%[^\n]s",r1.keberangkatan);
					    fflush(stdin);
					    printf("Tujuan : ");
					    scanf("%[^\n]s",r1.tujuan);
					    fflush(stdin);
					    printf("Bisnis : ");
					    scanf("%d",&r1.bisnis);
					    fflush(stdin);
					    printf("Premium : ");
					    scanf("%d",&r1.premium);
						    
						while(fread(&k1,sizeof(kota),1,pf)) {
						if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
	            			strcpy(r1.kode1,k1.kode);
						} 
						if (strcmp(r1.tujuan,k1.namaKota)==0) {
							strcpy(r1.kode2,k1.kode);
						}
				        }
					}
					fwrite(&r1,sizeof(rute),1,prute1); 
		    }
		    fclose(pf);
		    fclose(prute);
		    fclose(prute1);
		    
		    if (found==1) {
		    	prute = fopen("rute.txt","w");
		    	prute1 = fopen("temp3.txt","r");
		    	
				while(fread(&r1,sizeof(rute),1,prute1)) {
		            fwrite(&r1,sizeof(rute),1,prute);
		            
		        }
		        fclose(prute);
			    fclose(prute1);
				printf("Data berhasil diubah");
			}	
			printf("\nMain Menu [y/t] ? ");
			again=getch();
		break;
		
		case 4:
			system("cls");
			FILE *drute,*drute1;
			prute = fopen("rute.txt","r");
			system("cls");
			lihat_rute();
			printf("\n\n#EDIT DATA RUTE#");
			fflush(stdin);
		    printf("\n\nDelete Rute : DELETE_");
		    scanf("%[^\n]s",kodeKota);
		    
		    drute = fopen("rute.txt","r");
		    drute1 = fopen("temp3.txt","w");
		    	while(fread(&r1,sizeof(rute),1,drute)){
		    		if(strcmp(r1.kode,kodeKota)){
		        		found = 1;
		        	}
				}
					fwrite(&r1,sizeof(rute),1,drute1); 
		    
			fclose(drute);
			fclose(drute1);
		    
		     if(found){
		        drute = fopen("rute.txt","w");
		        drute1 = fopen("temp3.txt","r");
		
		        while(fread(&r1,sizeof(rute),1,drute1)){
		            fwrite(&r1,sizeof(rute),1,drute);
		        }
		        fclose(drute);
		        fclose(drute1);
		        printf("\nData telah berhasil dihapus\n");
    		}
			
			printf("\nMain Menu [y/t] ? ");
			again=getch();
		break;
		
		case 5:
		system("cls");
		menu_admin();
		system("cls");
	}
}while(again == 'y');
}
